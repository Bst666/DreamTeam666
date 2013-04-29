/*
 * InputInterruptService.cpp
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */
#include "InputInterruptService.h"
namespace hal {
InputInterruptService::InputInterruptService():
//Kanäle erstelle um Msgs von der ISR zu erhalten
interruptChannelID_ISR(ChannelCreate(0)),
inputInterruptChannelID_DIPATCH(ChannelCreate(0))
{}
InputInterruptService::~InputInterruptService() {
// Stop thread
   stop();
//wait for end
   join();
ChannelDestroy(inputInterruptChannelID_DIPATCH);
ChannelDestroy(interruptChannelID_ISR);
}

int InputInterruptService::getInterruptChannelID_ISR(){
	return interruptChannelID_ISR;
}
int InputInterruptService::getInterruptChannelID_DISPATCH(){
	start(NULL); //Thread starten
	return inputInterruptChannelID_DIPATCH;
}

void InputInterruptService::execute(void* arg){
	const int inputInterruptConnectionID = ConnectAttach(0, 0, inputInterruptChannelID_DIPATCH, _NTO_SIDE_CHANNEL, 0);
	struct _pulse pulse;
	while ( !isStopped() ){
		// Warten auf Pulse Message vom kernel
		if (MsgReceivePulse(interruptChannelID_ISR, &pulse, sizeof(pulse), NULL) == -1){ //Puls Msg empfangen
			perror("MsgReceivePulse failed: ");
			exit(1);
		}

		if (pulse.code == HALSensorik::hardwareIRQPulseCode){ //kommt aus der HAW ISR?			detectInputChange(pulse.value.sival_int, inputInterruptConnectionID);//Update Input und Pulse Msg senden		}else if(pulse.code == HALSensorik::timerPulse){			MsgSendPulse(inputInterruptConnectionID, SIGEV_PULSE_PRIO_INHERIT, PULSE_TIME, 0);		}
	}
	ConnectDetach(inputInterruptConnectionID);
}
void InputInterruptService::shutdown(){}
void InputInterruptService::detectInputChange(const int inputValue, const int inputInterruptConnectionID){

	const uint8_t inputPortB = inputValue & 0xFF;
	const uint8_t inputPortC = (inputValue >> 8) & 0xFF;
	//Update and send Message
	//Tasten
	static UpdateAndSendMsg taste_Emergency(TASTE_EMERGENCY_IN, true, inputInterruptConnectionID, PULSE_TASTE_EMERGENCY_NICHT_GEDRUEKT, PULSE_TASTE_EMERGENCY);
	taste_Emergency.update(inputPortC);
	static UpdateAndSendMsg taste_reset(TASTE_RESET_IN, false, inputInterruptConnectionID, PULSE_TASTE_RESET_IST_GEDRUECKT, PULSE_TASTE_RESET_IST_NICHT_GEDRUECKT);
	taste_reset.update(inputPortC);
	static UpdateAndSendMsg taste_start(TASTE_START_IN, false, inputInterruptConnectionID, PULSE_TASTE_START_IST_GEDRUECKT, PULSE_TASTE_START_IST_NICHT_GEDRUECKT);
	taste_start.update(inputPortC);
	static UpdateAndSendMsg taste_stop(TASTE_STOP_IN, true, inputInterruptConnectionID, NOTHING, PULSE_TASTE_STOP_IST_GEDRUECKT);
	taste_stop.update(inputPortC);
	//Rutsche
	static UpdateAndSendMsg rutsche(RUTSCHE_VOLL_IN, false, inputInterruptConnectionID, PULSE_RUTSCHE_SCHRANKE_FREI, PULSE_RUTSCHE__SCHRANKE_GESPERRT);
	rutsche.update(inputPortB);

	//Weiche
	static UpdateAndSendMsg weiche(WEICHE_OFFEN_IN, false, inputInterruptConnectionID, PULSE_WEICHE_IST_OFFEN, NOTHING);
	weiche.update(inputPortB);
	//Werkstück
	static UpdateAndSendMsg werkstueck_In_Hoehenmessung(WERKSTUECK_IN_HOEHENMESSUNG_IN, true, inputInterruptConnectionID, PULSE_WERKSTUECK_NICHT_IN_HOEHENMESSUNG, PULSE_WERKSTUECK_IN_HOEHENMESSUNG);
	werkstueck_In_Hoehenmessung.update(inputPortB);

	static UpdateAndSendMsg werkstueck_In_Toleranzbereich(WERKSTUECK_KLEIN_GROSS_IN, false, inputInterruptConnectionID, PULSE_WERKSTUECK_IN_Toleranzbereich, PULSE_WERKSTUECK_ZU_FLACH);
	werkstueck_In_Toleranzbereich.update(inputPortB);

	static UpdateAndSendMsg werkstueck_Mit_Metal(WERKSTUECK_METAL_IN, false, inputInterruptConnectionID, PULSE_WERKSTUECK_METAL, NOTHING);
	werkstueck_Mit_Metal.update(inputPortB);

	static UpdateAndSendMsg werkstueck_Im_Anlauf(WERKSTUECK_EINLAUF_IN, true, inputInterruptConnectionID, PULSE_WERKSTUECK_NICHT_IM_EINLAUF, PULSE_WERKSTUECK_IM_EINLAUF);
	werkstueck_Im_Anlauf.update(inputPortB);

	static UpdateAndSendMsg werkstueck_Im_Auslauf(WERKSTUECK_AUSLAUF_IN, true, inputInterruptConnectionID, PULSE_WERKSTUECK_NICHT_IM_AUSLAUF, PULSE_WERKSTUECK_IM_AUSLAUF);
	werkstueck_Im_Auslauf.update(inputPortB);

	static UpdateAndSendMsg werkstueck_In_Weiche(WERKSTUECK_IN_WEICHE_IN, true, inputInterruptConnectionID, PULSE_WERKSTUECK_NICHT_IN_WEICHE, PULSE_WERKSTUECK_IN_WEICHE);
	werkstueck_In_Weiche.update(inputPortB);

}
}


