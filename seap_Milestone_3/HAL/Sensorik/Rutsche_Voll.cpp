/*
 * Rutsche_Voll.cpp
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#include "Rutsche_Voll.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Rutsche_Voll::instanceFlag;
Rutsche_Voll* Rutsche_Voll::instance;
Rutsche_Voll* Rutsche_Voll::getInstance(){
	 if(!instanceFlag){
		    instance = new Rutsche_Voll();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALSensorik *hal_Rutsche_Voll;
//---------------------------------Konstruktor-----------------------------------------------//
Rutsche_Voll::Rutsche_Voll() {
	instanceFlag = false;
	instance = NULL;
	hal_Rutsche_Voll = HALSensorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis
}

Rutsche_Voll::~Rutsche_Voll() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
bool Rutsche_Voll::ist_Rutsche_voll() {
	return !hal_Rutsche_Voll->getDevice(D_GROUP0_PORTB, RUTSCHE_VOLL_IN);
}
//---------------------------------Ende Methoden---------------------------------------------------//
}
