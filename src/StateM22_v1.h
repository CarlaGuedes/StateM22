/*
 * StateM22_v1.h
 *
 *  Created on: 02/11/2018
 *      Author: 2x2CARD
 */

#ifndef STATEM22_v1_H_
#define STATEM22_v1_H_


enum states {  //Take into account the following values: CLOSED=0 e OPENED=1
	CLOSED,
	OPENED,
}state;

enum events {  //Take into account the following values: CLOSED_OPENED=0 e OPENED_CLOSED=1
	CLOSED_OPENED,
	OPENED_CLOSED,
}triggerEvent;

int AddStateTransition(int fromState, int triggerEvent, int toState);

void historic(int prevState, int actEvent,int nextState);

void PrintStateMachine();

int ProcessEvent(int triggerEvent);


#endif /* STATEM22_v1_H_ */
