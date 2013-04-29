/*
 * Ampel.h *  Created on: 22.04.2013 *      Author: H.Bani *
 */

#ifndef AMPEL_H_
#define AMPEL_H_

#include "HAL/Aktorik/HALAktorik.h"


namespace hal{
class Ampel {
public:
	//Liefert die Aktuelle intanz der Klasse Ampel
	static Ampel* getInstance();

	/*
	 * kontrolliert die Gelbe Lampe
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	 void ampel_gelbLicht( bool an);

	/*
	 * kontrolliert die Rote Lampe
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	 void ampel_rotLicht(bool an);

	 /*
	 * kontrolliert die Grüne Lampe
	 * @param an = true => licht an
	 * sonst licht aus
	 */
	 void ampel_gruenesLicht (bool an);
private:
	 static Ampel* instance;
	 static bool instanceFlag;
	 HALAktorik *hal_Ampel;
	Ampel();
	~Ampel();
};
}
#endif /* AMPEL_H_ */
