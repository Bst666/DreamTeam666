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
	 * Prüft ob die  start Taste gedückt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_start_is_gedrueckt();

	/**
	 * Prüft ob die  stopp Taste gedückt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_stopp_is_gedrueckt();

	/**
	 * Prüft ob die  reset Taste gedückt ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	bool Taste_reset_is_gedrueckt() ;

	/**
	 * Prüft ob die  E-Stopp Taste gedückt ist
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
