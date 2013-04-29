/*
 * Weiche.h *  Created on: 22.04.2013 *      Author: H.Bani *
 */

#ifndef WEICHE_H_
#define WEICHE_H_

#include "HAL/Aktorik/HALAktorik.h"

namespace hal{
class Weiche {
public:
	static Weiche* getInstance();
	/**
	 * Steuert die WEICHE
	 * @param offen == true => WEICHE göffnet => DAS WERCKSTÜCK WIRD NICHT AUSSORTIERT.
	 * offen == false=>Weiche zu.
	 */
	void weiche_Oeffnen(bool oeffnen);
private:
	static Weiche* instance;
	static bool instanceFlag;
	Weiche();
	~Weiche();
};
}
#endif /* WEICHE_H_ */
