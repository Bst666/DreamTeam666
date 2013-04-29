/*
 * HALAktorik.cpp * *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "HALAktorik.h"

namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool HALAktorik::instanceFlag;
HALAktorik* HALAktorik::instance;
HALAktorik* HALAktorik::getInstance(){
	 if(! instanceFlag){
		    instance = new HALAktorik();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------//

//-------------------------------------Mutex-------------------------------------------//
MUTEX* HALAktorik::AktorikMUTEX;
//-----------------------------------Ende Mutex----------------------------------------//

//---------------------------------Konstruktor-----------------------------------------//
HALAktorik::HALAktorik() {
	AktorikMUTEX= new MUTEX();
		instanceFlag = false;
		instance = NULL;

	#ifdef SIMULATION
		// Open connection to the simulation
		IOaccess_open();
	#endif

		// Get permissions for hardware access
			if (ThreadCtl(_NTO_TCTL_IO, 0) == -1)
				throw AktorikAccessFailedEx();
			out8(D_CONTROL, 0x8A);

}

HALAktorik::~HALAktorik() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-----------------------------------------//


void HALAktorik::setDevice(D_Port port, const D_PortBit portBit, bool an){

	//00100000||00100000 =00100000
	//00100000&11011111 =>00000000

	const uint8_t portBitMask = (1 << portBit);//bit mask

	//Entring Critical Section
	AktorikMUTEX->lock();
	uint8_t value = in8(port);
	if (an)
		value |= portBitMask;
	else
		value &= ~portBitMask;

	out8(port, value);
	AktorikMUTEX->unlock();

}
}
