/*
 * Ampel.cpp
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#include "Ampel.h"
namespace hal{
//---------------------------------Instanzierung---------------------------------------//
bool Ampel::instanceFlag;
Ampel* Ampel::instance;
Ampel* Ampel::getInstance(){
	 if(!instanceFlag){
		    instance = new Ampel();
	        instanceFlag = true;
	        return instance;
	  }else{
	        return instance;
	    }
}
//---------------------------------Ende Instanzierung----------------------------------------//
HALAktorik *hal_Ampel;
//---------------------------------Konstruktor-----------------------------------------------//

Ampel::Ampel() {
	instanceFlag = false;
	instance = NULL;
	hal_Ampel = HALAktorik::getInstance(); //Hall mit Mutex und Zugriffserlaublis
}

Ampel::~Ampel() {
	 delete instance;
	instance = NULL;

}
//---------------------------------Ende Konstruktor-------------------------------------------//

//---------------------------------Methoden---------------------------------------------------//
void Ampel::ampel_gruenesLicht( bool an){
	//Ampel Licht : Grün an/aus
	hal_Ampel->setDevice(D_GROUP0_PORTA, AMPEL_GRUEN_OUT, an);
}

void Ampel::ampel_gelbLicht( bool an){
	//Ampel Licht : Gelb an/aus
	hal_Ampel->setDevice(D_GROUP0_PORTA, AMPEL_GELB_OUT, an);
}

void Ampel::ampel_rotLicht( bool an){
	//Ampel Licht : Rot an/aus
	hal_Ampel->setDevice(D_GROUP0_PORTA, AMPEL_ROT_OUT, an);
}
}
//---------------------------------Ende Methoden----------------------------------------------//
