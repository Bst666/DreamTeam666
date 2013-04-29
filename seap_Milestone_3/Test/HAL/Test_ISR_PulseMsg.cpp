/*
 * Test_ISR_PulseMsg.cpp *  Created on: 22.04.2013 *      Author: H.Bani */

#include "Test_ISR_PulseMsg.h"
using namespace std;
using namespace hal;
namespace thread {
HALSensorik *sensorik;
Test_ISR_PulseMsg::Test_ISR_PulseMsg() {
	sensorik = HALSensorik::getInstance();
}
Test_ISR_PulseMsg::~Test_ISR_PulseMsg() {
}

void Test_ISR_PulseMsg::shutdown(){
	 cout << "Shutting down..." << endl;
}

void Test_ISR_PulseMsg::execute(void* arg){
	const int iIChannelID = sensorik->getInputInterruptChannelID_DISPATCH();
	while (!isStopped()) {
		 // wait for an pulse message event generated by the HAL
		struct _pulse pulse;
		if (MsgReceivePulse(iIChannelID, &pulse, sizeof(pulse), NULL) == -1){
			  perror("SensorCtrl: MsgReceivePulse");
			  exit(EXIT_FAILURE);
		}
		switch(pulse.code){

		//Tasten
		case PULSE_TASTE_START_IST_GEDRUECKT:
			cout<<"Received _Msg: Die Start Taste wurde gedr�ckt"<<endl;
			break;
		case	PULSE_TASTE_START_IST_NICHT_GEDRUECKT :
			cout<<"Received _Msg: Die Start Taste wurde los gelassen"<<endl;
			break;
		case	PULSE_TASTE_STOP_IST_GEDRUECKT:
			cout<<"Received _Msg: Die Stopp Taste wurde gedr�ckt"<<endl;
			break;
		case	PULSE_TASTE_RESET_IST_GEDRUECKT:
			cout<<"Received _Msg: Die Reset Taste wurde gedr�ckt"<<endl;
			break;
		case	PULSE_TASTE_RESET_IST_NICHT_GEDRUECKT:
			cout<<"Received _Msg: Die Reset Taste wurde los gelassent"<<endl;
			break;
		case	PULSE_TASTE_EMERGENCY:
			cout<<"Received _Msg:Die E-Stopp Taste wurde gedr�ckt"<<endl;			break;		case	PULSE_TASTE_EMERGENCY_NICHT_GEDRUEKT:					cout<<"Received _Msg:Die E-Stopp Taste wurde Losgelassen"<<endl;
			break;

		//Werkst�ck
		case	PULSE_WERKSTUECK_IN_HOEHENMESSUNG:
			cout<<"Received _Msg: Das Werkst�ck ist in H�henmessung "<<endl;
			break;
		case	PULSE_WERKSTUECK_NICHT_IN_HOEHENMESSUNG:
			cout<<"Received _Msg: Das Werkst�ck ist nicht in H�henmessung  "<<endl;
			break;
		case	PULSE_WERKSTUECK_IN_Toleranzbereich:
			cout<<"Received _Msg: Das Werkst�ck ist in Toleranzbereich "<<endl;
			break;
		case	PULSE_WERKSTUECK_METAL:
			cout<<"Received _Msg: Das Werkst�ck ist mit Metal "<<endl;
			break;
		case	PULSE_WERKSTUECK_IM_EINLAUF:
			cout<<"Received _Msg: Das Werkst�ck ist im Einlauf "<<endl;
			break;
		case PULSE_WERKSTUECK_NICHT_IM_EINLAUF:
			cout<<"Received _Msg: Das Werkst�ck ist nicht im Einlauf "<<endl;
			break;
		case PULSE_WERKSTUECK_IM_AUSLAUF:
			cout<<"Received _Msg: Das Werkst�ck ist im Auslauf "<<endl;
			break;
		case PULSE_WERKSTUECK_NICHT_IM_AUSLAUF:
			cout<<"Received _Msg: Das Werkst�ck ist nicht im Auslauf "<<endl;
			break;
		case PULSE_WERKSTUECK_NICHT_IN_WEICHE:
			cout<<"Received _Msg: Das Werkst�ck ist nicht in der  Weiche "<<endl;
			break;
		case PULSE_WERKSTUECK_IN_WEICHE:
			cout<<"Received _Msg: Das Werkst�ck ist in der  Weiche "<<endl;
			break;

		//Weiche
		case	PULSE_WEICHE_IST_OFFEN:
			cout<<"Received _Msg: Die Weiche ist Offen "<<endl;
		break;

		//Rutsche
		case	PULSE_RUTSCHE_SCHRANKE_FREI:
			cout<<"Received _Msg: Die Rutsche ist nicht Voll "<<endl;
		break;
		case	PULSE_RUTSCHE__SCHRANKE_GESPERRT:
			cout<<"Received _Msg: Die Rutsche ist Voll "<<endl;
		break;
		default:
			cout<<"Nothing "<<endl;
			break;
		}

	 }
}

}
