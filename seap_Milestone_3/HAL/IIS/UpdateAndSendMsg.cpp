/*
 * UpdateAndSendMsg.cpp *  Created on: 22.04.2013 *      Author: H.Bani*/

#include "UpdateAndSendMsg.h"
namespace hal{
//---------------------------------Konstruktor-----------------------------------------------//
UpdateAndSendMsg::UpdateAndSendMsg(const D_PortBit bit, const bool standWert, const int connectionID,
		 const PulseCode an, const PulseCode aus):
portBit(bit),
connectionID(connectionID),
an(an),
aus(aus),
wert_alt(standWert)
{}
UpdateAndSendMsg::~UpdateAndSendMsg() {}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
void UpdateAndSendMsg::update(const uint8_t portWert){
	const bool wert_neu = ( ( portWert & (1 << portBit) ) != 0  );
	if (wert_neu != wert_alt){
		if (wert_neu){
			sendPulseMsg(an);
		}else{
			sendPulseMsg(aus);
		}
	}
	wert_alt = wert_neu;
}

void UpdateAndSendMsg::sendPulseMsg(const PulseCode pulsCode){
	//Nicht definierte Pulse Code dürfen nicht gesendet
	if (pulsCode == NOTHING){
		return;
    }
	const int ret = MsgSendPulse(connectionID, SIGEV_PULSE_PRIO_INHERIT, pulsCode, 0);
	if (ret == -1){
		throw InputPulseMsgSendFailedException();
	}
}
}
//---------------------------------Ende Methoden------------------------------------------------//

