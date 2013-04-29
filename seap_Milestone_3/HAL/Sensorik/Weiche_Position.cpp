/*
 * Weiche_Position.cpp *  Created on: 22.04.2013 *      Author: H.Bani */

#include "Weiche_Position.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Weiche_Position::instanceFlag;
Weiche_Position* Weiche_Position::instance;
Weiche_Position* Weiche_Position::getInstance(){
	 if(!instanceFlag){
		    instance = new Weiche_Position();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALSensorik *hal_Weiche_Position;
//---------------------------------Konstruktor-----------------------------------------------//
Weiche_Position::Weiche_Position() {
	instanceFlag = false;
	instance = NULL;
	hal_Weiche_Position = HALSensorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis

}

Weiche_Position::~Weiche_Position() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
bool Weiche_Position::weiche_ist_Offen() {
	return hal_Weiche_Position->getDevice(D_GROUP0_PORTB, WEICHE_OFFEN_IN);
}
//---------------------------------Ende Methoden---------------------------------------------------//
}
