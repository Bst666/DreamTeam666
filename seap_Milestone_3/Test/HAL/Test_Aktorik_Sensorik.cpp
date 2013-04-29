/*
 * Test_Aktorik_Sensorik.cpp
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#include "Test_Aktorik_Sensorik.h"
using namespace std;
using namespace hal;

namespace thread {

Leds *leds_Hall;
Motor *motor_Hall;
Ampel *ampel_Hall;
Weiche *weiche_Hall;
Werkstueck_Position *werkstueck_Position_Hall;
Tasten_Sensor *tasten_Sensor_Hall;
Rutsche_Voll *Rutsche_Voll_Hall;
Weiche_Position *weiche_Position_Hall;

Test_Aktorik_Sensorik::Test_Aktorik_Sensorik() {
	leds_Hall   = Leds::getInstance();
	motor_Hall  = Motor::getInstance();
	ampel_Hall  = Ampel::getInstance();
	weiche_Hall = Weiche::getInstance();
	tasten_Sensor_Hall = Tasten_Sensor::getInstance();
	werkstueck_Position_Hall = Werkstueck_Position::getInstance();
	Rutsche_Voll_Hall =Rutsche_Voll::getInstance();
	weiche_Position_Hall = Weiche_Position::getInstance();
}

Test_Aktorik_Sensorik::~Test_Aktorik_Sensorik() {
	// TODO Auto-generated destructor stub
}

void Test_Aktorik_Sensorik::shutdown(){
	 cout << "Shutting down..." << endl;
}

void Test_Aktorik_Sensorik::execute(void* arg){
			//Motor
			cout << "-----------------------------------Motor Test--------------------" << endl;
			cout << "Motor start schnell" << endl;
			motor_Hall->motor_start(true);
			sleep(3);

			cout << "Motor start Langsam" << endl;
			motor_Hall->motor_start(false);
			sleep(3);

			cout << "Motor stop" << endl;
			motor_Hall->motor_stopp();
			sleep(3);


			//Ampel
			cout << "-----------------------------------AMPEL Test-----------------------" << endl;
			cout << "rot an" << endl;
			ampel_Hall->ampel_rotLicht(true);
			sleep(3);

			cout << "rot aus" << endl;
			ampel_Hall->ampel_rotLicht(false);


			cout << "gelb an" << endl;
			ampel_Hall->ampel_gelbLicht(true);
			sleep(3);

			cout << "gelb aus" << endl;
			ampel_Hall->ampel_gelbLicht(false);


			cout << "gruen an" << endl;
			ampel_Hall->ampel_gruenesLicht(true);
			sleep(3);

			cout << "gruen aus" << endl;
			ampel_Hall->ampel_gruenesLicht(false);


			//Leds
			cout << "-----------------------------------LED Test---------------------------" << endl;
			cout << "Led start an" << endl;
			leds_Hall->led_Start_Taste(true);
			sleep(3);
			cout << "Led start aus" << endl;
			leds_Hall->led_Start_Taste(false);
			sleep(3);

			cout << "Led Reset an" << endl;
			leds_Hall->led_reset_Taste(true);
			sleep(3);

			cout << "Led Reset aus" << endl;
			leds_Hall->led_reset_Taste(false);
			sleep(3);

			cout << "Led Q1 an" << endl;
			leds_Hall->led_q1(true);
			sleep(3);

			cout << "Led Q1 aus" << endl;
			leds_Hall->led_q1(false);
			sleep(3);

			cout << "Led Q2 an" << endl;
			leds_Hall->led_q2(true);
			sleep(3);
			cout << "Led Q2 aus" << endl;
			leds_Hall->led_q2(false);
			sleep(3);


			cout << "-----------------------------------Test Weiche-----------------------" << endl;
			cout << "Weiche_Auf" << endl;
			weiche_Hall->weiche_Oeffnen(true);
			sleep(3);

			//Ist weiche auf
			if (weiche_Position_Hall->weiche_ist_Offen()){
				cout << "Weiche ist auf" << endl;
			}else{
				cout << "Weiche ist zu" << endl;
			}
			sleep(3);

			cout << "Weiche_Zu" << endl;
			weiche_Hall->weiche_Oeffnen(false);
			sleep(3);

			//Ist weiche zu
			if (weiche_Position_Hall->weiche_ist_Offen()){
				cout << "Weiche ist auf" << endl;
			}else{
				cout << "Weiche ist zu" << endl;
			}
			sleep(3);

			cout << "-----------------------------------Werkstück Position Test-------------------" << endl;

			if (werkstueck_Position_Hall->werktueck_ist_Im_Anlauf()){
				cout << "Werkstük im Anlauf" << endl;
			}else{
				cout << "Werkstük nicht im Anlauf" << endl;
			}
			sleep(3);

			if (werkstueck_Position_Hall->werktueck_ist_In_HoehenMessung()){
				cout << "Werkstük in HoehenMessung" << endl;
			}else{
				cout << "Werkstük nicht in HoehenMessung" << endl;
			}
			sleep(3);

			if (werkstueck_Position_Hall->werktueck_ist_In_ToleranzBereich()){
				cout << "Werkstük in ToleranzBereich" << endl;
			}else{
				cout << "Werkstük nicht in ToleranzBereich" << endl;
			}
			sleep(3);

			if (werkstueck_Position_Hall->werktueck_ist_In_Weiche()){
				cout << "Werkstük in Weiche" << endl;
			}else{
				cout << "Werkstük nicht in Weiche" << endl;
			}
			sleep(3);
			if (werkstueck_Position_Hall->werktueck_ist_Mit_Metall()){
				cout << "Werkstük ist mit Metall" << endl;
			}else{
				cout << "Werkstük ist ohne Metall" << endl;
			}
			sleep(3);
			if (werkstueck_Position_Hall->werktueck_ist_im_Auslauf()){
				cout << "Werkstük ist im Auslauf" << endl;
			}else{
				cout << "Werkstük ist nicht im Auslauf" << endl;
			}
			sleep(3);

			cout << "-----------------------------------Tasten Test --------------------------------" << endl;

			if (tasten_Sensor_Hall->Taste_start_is_gedrueckt()){
				cout << "Die Start Taste ist gedrückt" << endl;
			}else{
				cout << "Die Start Taste ist nicht gedrückt" << endl;
			}
			sleep(3);

			if (tasten_Sensor_Hall->Taste_reset_is_gedrueckt()){
				cout << "Die Reset Taste ist gedrückt" << endl;
			}else{
				cout << "Die Reset ist nicht gedrückt" << endl;
			}
			sleep(3);

			if (tasten_Sensor_Hall->Taste_stopp_is_gedrueckt()){
				cout << "Die Stopp Taste ist gedrückt" << endl;
			}else{
				cout << "Die Stopp ist nicht gedrückt" << endl;
			}
			sleep(3);

			if (tasten_Sensor_Hall->Taste_eStopp_is_gedrueckt()){
				cout << "Die eStopp Taste ist gedrückt" << endl;
			}else{
				cout << "Die eStopp ist nicht gedrückt" << endl;
			}
			sleep(3);

			cout << "-----------------------------------Rutsche Test------------------------------" << endl;
			if (Rutsche_Voll_Hall->ist_Rutsche_voll()){
				cout << "Die Rutsche ist Voll" << endl;
			}else{
				cout << "Die Rutsche ist nicht  Voll" << endl;
			}
			sleep(3);


		cout << "beendet" << endl;
}
}
