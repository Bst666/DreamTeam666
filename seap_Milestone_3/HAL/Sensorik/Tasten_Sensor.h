/*
 * Tasten_Sensor.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef TASTEN_SENSOR_H_
#define TASTEN_SENSOR_H_
#include "HAL/Sensorik/HALSensorik.h"
namespace hal{
class Tasten_Sensor {
public:
	static Tasten_Sensor* getInstance(); //Liefert die Aktuelle intanz der Klasse Tasten_Sensor

	/**
	 * Pr�ft ob die  start Taste ged�ckt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_start_is_gedrueckt();

	/**
	 * Pr�ft ob die  stopp Taste ged�ckt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_stopp_is_gedrueckt();

	/**
	 * Pr�ft ob die  reset Taste ged�ckt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_reset_is_gedrueckt() ;

	/**
	 * Pr�ft ob die  E-Stopp Taste ged�ckt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_eStopp_is_gedrueckt();

private:
	static Tasten_Sensor* instance;
	static bool instanceFlag;
	Tasten_Sensor();
	~Tasten_Sensor();
};
}
#endif /* TASTEN_SENSOR_H_ */
