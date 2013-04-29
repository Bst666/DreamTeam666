/*
 * HALAktorik.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef HALAKTORIK_H_
#define HALAKTORIK_H_
#include <stdint.h>
#include <exception>
#include "Common/HWaccess.h"
#include "Common/MUTEX.h"
#include "Common/MUTEX.cpp"


namespace hal{
/**
 * Hardware access Exception.
 */
class AktorikAccessFailedEx: public std::exception{
	virtual const char* what() const throw(){
		return "Aktorik Access Failed";
	}
};
class HALAktorik {
public:
	static HALAktorik* getInstance(); //Liefert die Aktuelle intanz der Klasse HALAktorik
	/**
	 * setzt den den Ausgangswert
	 * @param port Verbindungsport
	 * @param portBit Bitnummer in Verbindungsport
	 * @param an anschalten wenn true sonst ausschalten
	 */
	void setDevice(D_Port port, D_PortBit portBit,bool an);
private:
	HALAktorik();
	virtual ~HALAktorik();

	static  MUTEX* AktorikMUTEX; 	//IO access thread safe.
	static HALAktorik* instance;
	static bool instanceFlag;
};
}

#endif /* HALAKTORIK_H_ */
