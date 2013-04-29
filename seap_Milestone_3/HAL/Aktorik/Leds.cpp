/*
 * Leds.cpp
 *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "LEDS.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Leds::instanceFlag;
Leds* Leds::instance;
Leds* Leds::getInstance(){
	 if(!instanceFlag){
		    instance = new Leds();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALAktorik *hal_Leds;
//---------------------------------Konstruktor-----------------------------------------------//
Leds::~Leds() {
	 delete instance;
	instance = NULL;
}
Leds::Leds() {
	instanceFlag = false;
	instance = NULL;
	hal_Leds = HALAktorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//



void Leds::led_Start_Taste(bool offen){
	hal_Leds->setDevice(D_GROUP0_PORTC, LED_START_TASTE_OUT, offen);
}

void Leds::led_reset_Taste(bool offen) {
	hal_Leds->setDevice(D_GROUP0_PORTC, LED_RESET_TASTE_OUT, offen);
}

void Leds::led_q1( bool offen) {
	hal_Leds->setDevice(D_GROUP0_PORTC, LED_Q1_TASTE_OUT, offen);
}

void Leds::led_q2( bool offen) {
	hal_Leds->setDevice(D_GROUP0_PORTC, LED_Q2_TASTE_OUT, offen);
}

}

//---------------------------------Ende Methoden----------------------------------------------//
