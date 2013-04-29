/*
 * Leds.h *   Created on: 22.04.2013 *      Author: H.Bani *
 */

#ifndef LEDS_H_
#define LEDS_H_


#include "HAL/Aktorik/HALAktorik.h"




namespace hal{

class Leds {
public:

	static Leds* getInstance(); //Liefert die Aktuelle intanz der Klasse Leds

	/**
	 * Steuert die LED  der starttaste
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	void led_Start_Taste(bool an);


	/**
	 * Steuert das LED  der resettaste
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	void led_reset_Taste(bool an) ;


	/**
	 * Steuert die LED  der Q1
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	void led_q1(bool an) ;

	/**
	 * Steuert die LED  der Q2
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	void led_q2( bool an) ;


	private:
			static Leds* instance;
			static bool instanceFlag;
			Leds();
			~Leds();
};
}
#endif /* LEDS_H_ */
