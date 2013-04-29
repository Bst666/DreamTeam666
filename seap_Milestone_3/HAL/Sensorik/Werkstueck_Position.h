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
	 * Prüft ob das Werkstück sich im Anlauf befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	 bool werktueck_ist_Im_Anlauf();

	/**
	 * Prüft ob das Werkstück im Auslauf ist
	 * @return true wenn ja
	 * sonst nicht.
	 */
	 bool werktueck_ist_im_Auslauf() ;

	/**
	 * Prüft ob das Werkstück sich in höhenmesung befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_HoehenMessung();

	/**
	 * Prüft ob das Werkstück in der Toleranzbereich sich befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_ToleranzBereich() ;

	/**
	 * Prüft ob das Werkstück in der Weiche sich befindet
	 * @return true wenn ja
	 * sonst nicht.
	 */
	  bool werktueck_ist_In_Weiche();

	/**
	 * Prüft ob das Werkstück mit Metallansatz
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
