/*
 * HALSensorik.h *  Created on: 22.04.2013 *      Author: H.Bani
 */

#ifndef HALSENSORIK_H_
#define HALSENSORIK_H_
#include <stdint.h>
#include <exception>
#include "Common/HWaccess.h"
#include "Common/MUTEX.h"
#include "Common/MUTEX.cpp"
#include "HAL/IIS/InputInterruptService.h"


namespace hal{
/**
 * Hardware access Exception.
 */
class SensorikAccessFailedEx: public std::exception{
	virtual const char* what() const throw(){
		return "Sensorik Access Failed";
	}
};

/**
 * Inerrupt Exception
 */
class InterruptAttachFailedException: public std::exception{
	virtual const char* what() const throw(){
		return "Interrupt Attach Failed Exception";
	}
};
class HALSensorik {
public :
	static HALSensorik* getInstance(); //Liefert die Aktuelle intanz der Klasse HALSensorik
	/**
	 * Wert auslesen
	 * @param port Verbindungsport
	 * @param portBit Bitnummer in Verbindungsport
	 */
	 bool getDevice(D_Port port,D_PortBit portBit);
	 virtual int getInputInterruptChannelID_DISPATCH();
	 static int hardwareIRQPulseCode;	 static int timerPulse;
	 // Sigevent Struktur
	 struct sigevent isr_event;
private:
	HALSensorik();
	virtual ~HALSensorik();
	static  MUTEX* SensorikMUTEX; 	//IO access thread safe.
	static HALSensorik* instance;
	static bool instanceFlag;

	/**
	 * Interrupted Input,
	 */
	InputInterruptService iISR;

	/**
	 * Anzahl der Interrupted Inputs
	 */
	static int hardwareInputIRQ;

	/**
	 * the connection id (soll im emfangenen Prozess erzeugt Laut Vorlesung)
	 */
	 int interruptConnectionID;

	 /**
	 *  id interrupt attach function
	 */
	int interruptId;

	/**
	 *ISR Implementiert die ISR
	 */
	static const struct sigevent* ISR(void* arg, int interruptId);
};
}
#endif /* HALSENSORIK_H_ */
