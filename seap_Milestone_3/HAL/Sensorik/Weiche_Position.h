/*
 * Weiche_Position.h *  Created on: 22.04.2013 *      Author: H.Bani*/

#ifndef WEICHE_POSITION_H_
#define WEICHE_POSITION_H_
#include "HAL/Sensorik/HALSensorik.h"
namespace hal{
class Weiche_Position {
public:
static Weiche_Position* getInstance(); //Liefert die Aktuelle intanz der Klasse Weiche_Position


/**
 * Pr�ft die WEICHE
 * @param oeffnen == true => WEICHE g�ffnet => DAS WERCKST�CK WIRD NICHT AUSSORTIERT.
 * offen == false=>DAS WERCKST�CK WIRD AUSSORTIERT.
 */
bool weiche_ist_Offen();

private:
	static Weiche_Position* instance;
	static bool instanceFlag;
	Weiche_Position();
	~Weiche_Position();
};
}
#endif /* WEICHE_POSITION_H_ */
