/*
 * Motor.cpp
 *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "Motor.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Motor::instanceFlag;
Motor* Motor::instance;
Motor* Motor::getInstance(){
	 if(!instanceFlag){
		    instance = new Motor();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//

HALAktorik *hal_Motor;
//---------------------------------Konstruktor-----------------------------------------------//
Motor::Motor() {
	instanceFlag = false;
	instance = NULL;
	hal_Motor = HALAktorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis


}

Motor::~Motor() {
	delete instance;
	instance = NULL;
}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
void Motor::motor_start(bool schnell){
	// Motor Geschwindigkeit einstellen
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_LANGSAM_OUT, !schnell);

	// Motor Lauf Richtung Rechts
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_RECHLAUF_OUT, true);
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_LINKLAUF_OUT, false);

	// Motor stopp
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_STOPP_OUT, false);
}

void Motor::motor_stopp() {
	// Motor Geschwindigkeit einstellen
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_LANGSAM_OUT, true);

	// Motor Lauf Richtung
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_RECHLAUF_OUT, false);
	hal_Motor->	setDevice(D_GROUP0_PORTA, MOTOR_LINKLAUF_OUT, false);

	// Motor stopp
	hal_Motor->setDevice(D_GROUP0_PORTA, MOTOR_STOPP_OUT, true);
}
}
//---------------------------------Ende Methoden---------------------------------------------------//
