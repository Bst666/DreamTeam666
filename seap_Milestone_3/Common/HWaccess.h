/*
 * HWaccess.h
 *
 *  Created on: 22.04.2013
 *      Author: H.Bani
 */

#ifndef HWACCESS_H_
#define HWACCESS_H_




//#define SIMULATION
//#define BAND2
#define STAION_D
//#define TIMER_D
//#define FIFO_COUNTER_D
//#define Dispatcher_D
//#define SYNCHRONISATION_D






#include <stdio.h>
#include <sys/neutrino.h>
#include <hw/inout.h>



// Die drei folgenden includes dürfen nur in dieser Datei stehen

#ifdef SIMULATION
#include <ioaccess.h>
#endif
#define D_IOBASE 0x300  // Anfangsadresse Ports

//DIGITAL_CARD
enum D_Port{
 D_CONTROL		  = (D_IOBASE + 0x03), // control
 D_GROUP0_PORTA	  = (D_IOBASE + 0x00), // Port A
 D_GROUP0_PORTB	  = (D_IOBASE + 0x01), // Port B
 D_GROUP0_PORTC	  = (D_IOBASE + 0x02), // Port C
 ENABLE_INTERRUPT = (D_IOBASE + 0x0B), //interrupt enable register
 CLEAR_INTERRUPT  = (D_IOBASE + 0x18), //interrupt clear register
};

enum D_PortBit{

//Ausgabeport A				 	  0	       1
 MOTOR_RECHLAUF_OUT  = 0, // -	Motor Rechtlauf
 MOTOR_LINKLAUF_OUT  = 1, // -	Motor Linklauf
 MOTOR_LANGSAM_OUT   = 2, // -	Motor Langsam
 MOTOR_STOPP_OUT     = 3, // -	Motor Stopp
 WEICHE_AUF_OUT      = 4, // -	Weiche auf
 AMPEL_GRUEN_OUT     = 5, // -	Ampel Grün
 AMPEL_GELB_OUT      = 6, // -	Ampel Gelb
 AMPEL_ROT_OUT       = 7, // -	Ampel Rot


//Eingabeport B												0								1
 WERKSTUECK_EINLAUF_IN 				= 0, // Werkstück ist im Einlauf				    Kein Werkstück  im Einlauf
 WERKSTUECK_IN_HOEHENMESSUNG_IN 	= 1, // Werkstück ist in Höhen Messung  		    Kein Werkstück  in Höhen Messung
 WERKSTUECK_KLEIN_GROSS_IN			= 2, // Werkstück is zu klein oder zu gross			Kein Werkstück  im Toleranz Bereich
 WERKSTUECK_IN_WEICHE_IN 			= 3, // Werkstück ist in Weiche						Kein Werkstück  in der  Weiche
 WERKSTUECK_METAL_IN 				= 4, // Werkstück ist kein Metall					Werkstück ist   Metall
 WEICHE_OFFEN_IN 					= 5, // Weiche    ist geschlossen					Weiche    Offen
 RUTSCHE_VOLL_IN 					= 6, // Rutsche   ist Voll							Rutsche   ist nicht  Voll
 WERKSTUECK_AUSLAUF_IN 				= 7, // Werkstück ist im Auslauf					Kein Werkstück ist im Auslauf


//Ein-Ausgabeport C						0								1
  LED_START_TASTE_OUT	= 0, // Status-LED dunkel				Status-LED leuchtet
  LED_RESET_TASTE_OUT 	= 1, // Rset-LED dunkel					Rset-LED leuchtet
  LED_Q1_TASTE_OUT 		= 2, // Q1-LED dunkel					Q1-LED leuchtet
  LED_Q2_TASTE_OUT 		= 3, // Q2-LED dunkel					Q2-LED leuchtet
  TASTE_START_IN 		= 4, // Starttaste nicht gedrückt		Starttaste ist gedrückt
  TASTE_STOP_IN 		= 5, // Stop Taste gedrückt				Stop Taste ist nicht gedrückt
  TASTE_RESET_IN 		= 6, // Reset Taste nicht gedückt       Reset Taste ist gedückt
  TASTE_EMERGENCY_IN 	= 7, // E-Stop Taste gedrüclt			E-Stop Taste ist nicht gedrückt

};
#endif /* HWACCESS_H_ */
