/*
 * Werkstueck_Position.h *  Created on: 22.04.2013 *      Author: H.Bani*/

#ifndef WERKSTUECK_POSITION_H_
#define WERKSTUECK_POSITION_H_

#include "HAL/Sensorik/HALSensorik.h"

namespace hal{
class Werkstueck_Position {
public:
	static Werkstueck_Position* getInstance(); //Liefert die Aktuelle intanz der Klasse Werkstueck_Position

	/**
	 * Pr�ft ob das Werkst�ck sich im Anlauf befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	 bool werktueck_ist_Im_Anlauf();

	/**
	 * Pr�ft ob das Werkst�ck im Auslauf ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	 bool werktueck_ist_im_Auslauf() ;

	/**
	 * Pr�ft ob das Werkst�ck sich in h�henmesung befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_HoehenMessung();

	/**
	 * Pr�ft ob das Werkst�ck in der Toleranzbereich sich befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_ToleranzBereich() ;

	/**
	 * Pr�ft ob das Werkst�ck in der Weiche sich befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_Weiche();

	/**
	 * Pr�ft ob das Werkst�ck mit Metallansatz
	 * @return true wenn ja
	 * sonst ohne.
	 */
	  bool werktueck_ist_Mit_Metall();

private:
	static Werkstueck_Position* instance;
	static bool instanceFlag;
	Werkstueck_Position();
	~Werkstueck_Position();
};
}
#endif /* WERKSTUECK_POSITION_H_ */
