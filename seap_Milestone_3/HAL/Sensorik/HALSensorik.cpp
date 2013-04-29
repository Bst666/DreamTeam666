/*
 * HALSensorik.cpp
 *
 *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "HALSensorik.h"

namespace hal{
int HALSensorik::hardwareInputIRQ = 11;
int HALSensorik::hardwareIRQPulseCode = _PULSE_CODE_MINAVAIL;int HALSensorik::timerPulse = _PULSE_CODE_MAXAVAIL;
//---------------------------------Instanzierung---------------------------------------//
bool HALSensorik::instanceFlag;
HALSensorik* HALSensorik::instance;
HALSensorik* HALSensorik::getInstance(){
	 if(! instanceFlag){
		instance = new HALSensorik();
		instanceFlag = true;
		return instance;
	  }else{
	     return instance;
	   }
}
//---------------------------------Ende Instanzierung----------------------------------//
//-------------------------------------Mutex-------------------------------------------//
MUTEX* HALSensorik::SensorikMUTEX;

//-----------------------------------Ende Mutex----------------------------------------//


//---------------------------------Konstruktor-----------------------------------------//
HALSensorik::HALSensorik():
iISR(),
interruptConnectionID( ConnectAttach(0, 0, iISR.getInterruptChannelID_ISR(), _NTO_SIDE_CHANNEL, 0) ){
	SensorikMUTEX= new MUTEX();
	instanceFlag = false;
	instance = NULL;
#ifdef SIMULATION
	// Open connection to the simulation
	IOaccess_open();
#endif

	// Get permissions for hardware access
		if (ThreadCtl(_NTO_TCTL_IO, 0) == -1)
			throw SensorikAccessFailedEx();


	out8(D_CONTROL, 0x8A);
	// Enable interrupt  für  port B and C
	out8(ENABLE_INTERRUPT, 0xF9);
	//interrupts zurücksetzen
	in8(CLEAR_INTERRUPT);


	//Init sigevent
	SIGEV_PULSE_INIT( &isr_event, interruptConnectionID, SIGEV_PULSE_PRIO_INHERIT, hardwareIRQPulseCode, 0 );
	//Kernel Startet die ISr sobald der IRQ aufgetreten
	interruptId = InterruptAttach(hardwareInputIRQ, ISR, (const struct sigevent*)&isr_event, sizeof(isr_event), 0);
		if (interruptId == -1)
			throw InterruptAttachFailedException();	//Timer 0.01 sec -> ein Pulse	static timer_t timerID;	static struct itimerspec timerSpec;	static volatile struct sigevent timer_event;	SIGEV_PULSE_INIT( &timer_event, interruptConnectionID, SIGEV_PULSE_PRIO_INHERIT, timerPulse, 0 );	timer_create(CLOCK_REALTIME, (struct sigevent*)&timer_event, &timerID);	timerSpec.it_value.tv_sec = 0;	timerSpec.it_value.tv_nsec = 100000000;	timerSpec.it_interval.tv_sec = 0;	timerSpec.it_interval.tv_nsec = 100000000;	timer_settime(timerID, 0, &timerSpec, NULL);
}


HALSensorik::~HALSensorik() {
	delete instance;
	instance = NULL;
}

bool HALSensorik::getDevice(D_Port port, D_PortBit portBit){
	const uint8_t portBitMask = (1 << portBit);
	//Entring Critical Section
	SensorikMUTEX->lock();
	uint8_t value = in8(port);
	SensorikMUTEX->unlock();
	return ((value & portBitMask) == portBitMask);
}

int HALSensorik::getInputInterruptChannelID_DISPATCH(){
	return iISR.getInterruptChannelID_DISPATCH();
}

const struct sigevent* HALSensorik::ISR(void* arg, int interruptId){
 static struct sigevent* event = NULL; //Event der geschickt werden soll(muss static sein da innerhalb der ISR)
// Interrupt zurücksetzen
uint8_t changeState = in8(CLEAR_INTERRUPT);
//Bestimmung derInterrupt Uhrsache
if ( (changeState & 0x0A) != 0 ){
	// Inputs Änderung
	event = (struct sigevent*)arg;
	// die Ämderung in einem pulse message speichern
	event->sigev_value.sival_int = in8(D_GROUP0_PORTB);
	event->sigev_value.sival_int |= in8(D_GROUP0_PORTC) << 8;
}
return event;// wenn null soll kein thread benachrichtigt werden
}
}
