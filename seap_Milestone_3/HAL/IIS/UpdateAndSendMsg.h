/*
 * UpdateAndSendMsg.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef UPDATEANDSENDMSG_H_
#define UPDATEANDSENDMSG_H_
#include <exception>
#include <stdint.h>
#include <sys/neutrino.h>
#include "Common/HWaccess.h"
#include "HAL/IIS/PulseCode.h"


namespace hal{
/**
 *  exception Klasse für das versenden von pulse Msg an dispatcher.
 */
class InputPulseMsgSendFailedException: public std::exception{
	virtual const char* what() const throw(){
		return "InputPulseMsgSendFailedException";
	}
};

class UpdateAndSendMsg {
public:
	/**
	 * Wert Inititialisieren
	 * @param bit das Bit das gecheckt werden soll
	 * @param standWert default Wert vom bit (an/aus wird gebraucht bei der erste Flanke nach der Initialisierung)
	 * @param connectionID Verbindungs ID des Empfängers des Pulse Msg
	 * @param an   pulse code
	 * @param aus  pulse code
	 */
	UpdateAndSendMsg(const D_PortBit bit, const bool standWert, const int connectionID, const PulseCode an, const PulseCode aus);
	virtual ~UpdateAndSendMsg();

	/**
	 * macht ein Update des Internen gespeicherten Wert
	 * sendet bei steigende Flanke einen pulse Msg an den vorgegebenen Kanal
	 * @param newPortValue  neuer Wert  wird mit dem alten verglichen
	 */
	 virtual void update(const uint8_t portWert);
private:

	 /**
	 * Sendet den Puls Msg an den gegebenen Kanal.
	 * @param pulseCode the pulse code der gesendet wird
	 */
	void sendPulseMsg(const PulseCode pulsCode);

	/**
	 * Bit nummer des Signals (Genetiv)
	 */
	const D_PortBit portBit;

	/**
	 * Verbindungs ID
	 */
	const int connectionID;

	/**
	 * Puls
	 */
	const PulseCode an;

	/**
	 * Puls
	 */
	const PulseCode aus;

	/**
	 *Alter Wert stammt aus dem Letzten aufruf der Funktion update
	 */
	bool wert_alt;
};
}
#endif /* UPDATEANDSENDMSG_H_ */
