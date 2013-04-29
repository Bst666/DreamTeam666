/*
 * lampensteuerung.cpp
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
*/


#include "Lampensteuerung.h"


using namespace std;

namespace thread {
//--------------------------------------------Konstruktor----------------------------------------------------------------------------//
Ampel *ampel_H;

Lampensteuerung ::Lampensteuerung(){
	ampel_H = Ampel::getInstance();
	period=2;
}

Lampensteuerung::~Lampensteuerung() {
}

//--------------------------------------------Funktionen Definition-------------------------------------------------------------------//
void Lampensteuerung::shutdown() {
}
void Lampensteuerung::stop(){
	running =false;
	ampel_H->ampel_gelbLicht(false);
	ampel_H->ampel_gruenesLicht(false);
	ampel_H->ampel_rotLicht(false);
}


void Lampensteuerung::execute(void* arg) {
	running =true;
	ampel_H->ampel_gelbLicht(false);
	ampel_H->ampel_gruenesLicht(false);
	ampel_H->ampel_rotLicht(false);
	for(int i=0; i<6;i++){
		ampel_H->ampel_gelbLicht(true);
		sleep(period);
		ampel_H->ampel_gelbLicht(false);
		sleep(period);
	}
	this->stop();
	this->shutdown();

}




//--------------------------------------------Funktionen Definition Ende-------------------------------------------------------------------//
}
