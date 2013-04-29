/*
 * Werkstueck_Position.cpp *  Created on: 22.04.2013 *      Author: H.Bani*/

#include "Werkstueck_Position.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Werkstueck_Position::instanceFlag;
Werkstueck_Position* Werkstueck_Position::instance;
Werkstueck_Position* Werkstueck_Position::getInstance(){
	 if(!instanceFlag){
		    instance = new Werkstueck_Position();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALSensorik *hal_Werkstueck_Position;
//---------------------------------Konstruktor-----------------------------------------------//

Werkstueck_Position::Werkstueck_Position() {
	instanceFlag = false;
	instance = NULL;
	hal_Werkstueck_Position = HALSensorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis

}

Werkstueck_Position::~Werkstueck_Position() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
bool Werkstueck_Position::werktueck_ist_Im_Anlauf() {
	return !hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_EINLAUF_IN);
}

bool Werkstueck_Position::werktueck_ist_im_Auslauf() {
	return !hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_AUSLAUF_IN);
}

bool Werkstueck_Position::werktueck_ist_In_HoehenMessung() {
	return !hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_IN_HOEHENMESSUNG_IN);
}

bool Werkstueck_Position::werktueck_ist_In_ToleranzBereich() {
	return hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_KLEIN_GROSS_IN);
}

bool Werkstueck_Position::werktueck_ist_In_Weiche() {
	return !hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_IN_WEICHE_IN);
}

bool Werkstueck_Position::werktueck_ist_Mit_Metall() {
	return hal_Werkstueck_Position->getDevice(D_GROUP0_PORTB, WERKSTUECK_METAL_IN);
}
}
//---------------------------------Ende Methoden---------------------------------------------------//
