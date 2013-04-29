/*
 * Weiche.cpp *  Created on: 22.04.2013 *      Author: H.Bani
 */

#include "Weiche.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Weiche::instanceFlag;
Weiche* Weiche::instance;
Weiche* Weiche::getInstance(){
	 if(!instanceFlag){
		    instance = new Weiche();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALAktorik *hal_Weiche;
//---------------------------------Konstruktor-----------------------------------------------//
Weiche::Weiche() {
	instanceFlag = false;
	instance = NULL;
	hal_Weiche = HALAktorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis

}

Weiche::~Weiche() {
	delete instance;
	instance = NULL;
}
void Weiche::weiche_Oeffnen(bool oeffnen){
	hal_Weiche->setDevice(D_GROUP0_PORTA, WEICHE_AUF_OUT, oeffnen);
}
}
