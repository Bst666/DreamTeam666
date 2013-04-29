/*
 * Tasten_Sensor.cpp *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "Tasten_Sensor.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Tasten_Sensor::instanceFlag;
Tasten_Sensor* Tasten_Sensor::instance;
Tasten_Sensor* Tasten_Sensor::getInstance(){
	 if(!instanceFlag){
		    instance = new Tasten_Sensor();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALSensorik *hal_Tasten_Sensor;
//---------------------------------Konstruktor-----------------------------------------------//
Tasten_Sensor::Tasten_Sensor() {
	instanceFlag = false;
	instance = NULL;
	hal_Tasten_Sensor = HALSensorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis

}

Tasten_Sensor::~Tasten_Sensor() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
bool Tasten_Sensor::Taste_start_is_gedrueckt() {
	return hal_Tasten_Sensor->getDevice(D_GROUP0_PORTC, TASTE_START_IN);
}

bool Tasten_Sensor::Taste_stopp_is_gedrueckt() {
	return !hal_Tasten_Sensor->getDevice(D_GROUP0_PORTC, TASTE_STOP_IN);
}

bool Tasten_Sensor::Taste_reset_is_gedrueckt() {
	return hal_Tasten_Sensor->getDevice(D_GROUP0_PORTC, TASTE_RESET_IN);
}

bool Tasten_Sensor::Taste_eStopp_is_gedrueckt(){
	return !hal_Tasten_Sensor->getDevice(D_GROUP0_PORTC, TASTE_EMERGENCY_IN);
}
//---------------------------------Ende Methoden---------------------------------------------------//
}
