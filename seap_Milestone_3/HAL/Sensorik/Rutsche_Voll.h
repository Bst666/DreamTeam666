/*
 * Rutsche_Voll.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef RUTSCHE_VOLL_H_
#define RUTSCHE_VOLL_H_
#include "HAL/Sensorik/HALSensorik.h"


namespace hal{
class Rutsche_Voll {
public:
	static Rutsche_Voll* getInstance(); //Liefert die Aktuelle intanz der Klasse Rutsche_Voll

	/**
	 * Prüft ob die  Rutsche Voll ist
	 * @return true wenn ja
	 * sonst leer.
	 */
	bool ist_Rutsche_voll();

private:
	static Rutsche_Voll* instance;
	static bool instanceFlag;
	Rutsche_Voll();
	~Rutsche_Voll();
};
}
#endif /* RUTSCHE_VOLL_H_ */

