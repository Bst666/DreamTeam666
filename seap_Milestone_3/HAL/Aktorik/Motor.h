/*
 * Motor.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "HAL/Aktorik/HALAktorik.h"

namespace hal{
class Motor {
public:
	//Liefert die Aktuelle intanz der Klasse Motor
	static Motor* getInstance();

	/**
	 * Startet den Motor mit einem Parameter
	 * @param fast = true => schnell
	 * sonst langsam
	 */
	void motor_start(bool schnell) ;

	/**
	 * Stoppt den Motor
	 */
	void motor_stopp() ;

private:
	static Motor* instance;
	static bool instanceFlag;
	Motor();
	~Motor();
};
}
#endif /* MOTOR_H_ */
