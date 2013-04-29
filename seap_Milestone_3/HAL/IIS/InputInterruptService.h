/*
 * InputInterruptService.h *  Created on: 22.04.2013 *      Author: H.Bani*/

#ifndef INPUTINTERRUPTSERVICE_H_
#define INPUTINTERRUPTSERVICE_H_

#include "Common/HAWThread.h"
#include <stdint.h>
#include <sys/neutrino.h>
#include "HAL/IIS/UpdateAndSendMsg.h"
#include "HAL/IIS/UpdateAndSendMsg.cpp"
#include "HAL/IIS/PulseCode.h"




namespace hal {
class InputInterruptService: public thread::HAWThread {
public:
	InputInterruptService();
	virtual ~InputInterruptService();
	/**
	 * Liefert die Input channel ID die für den Transfert der Msg(definiert in pulse Code) an Dispatcher.
	 * @return channel ID
	 */
	virtual int getInterruptChannelID_DISPATCH();
	/**
	 * Liefert die channel id des inputs puls Msg(generiert von von der ISR )
	 */
	virtual int getInterruptChannelID_ISR();
private:
	/**
	 * Thread new start
	 * Empfängt Msg von der ISR der HAW Input
	 * und schickt einen pulse Msg (wird vom dispatcher benötigt)
	 */
	virtual void execute(void* arg);
	/*wird nicht benutz*/
	virtual void shutdown();
	/**	 * Sendet einen pulse Msg (je nach änderung im HAW  Input)
	 * @param inputValue Aktueller Wert des Ports geliefert von der Hall (ISR)
	 * @param inputInterruptConnectionID Verbindung ID (um pulse Msgs zu schicken wenn inputs sich ändern)
	 */
	 void detectInputChange(const int inputValue, const int inputInterruptConnectionID);

	/**
	 * ankommende (von ISR) Pulse Msg ID
	 */
	const int interruptChannelID_ISR;

	/**
	 * Chanel ID für pulse Transfert an Dispatcher
	 */
	const int inputInterruptChannelID_DIPATCH;
};
}
#endif /* INPUTINTERRUPTSERVICE_H_ */
