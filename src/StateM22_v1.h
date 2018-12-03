/*
 * StateM22_v1.h
 *
 *  Created on: 02/11/2018
 *      Author: 2x2CARD
 */

#ifndef STATEM22_v1_H_
#define STATEM22_v1_H_


#include <stdio.h>
#include <stdlib.h>

int mathistoric[100][3]; // initialization of mathistoric table
int mathistoricline=0;
int statetable[2][3]; // initialization of statetable
int statetableline=0;

enum states {  //Take into account the following values: CLOSED=0 e OPENED=1
	CLOSED,
	OPENED,
}state;

enum events {  //Take into account the following values: CLOSED_OPENED=0 e OPENED_CLOSED=1
	CLOSED_OPENED,
	OPENED_CLOSED,
}triggerEvent;


int AddStateTransition(int fromState, int triggerEvent, int toState){ //Add to the table (statetable), each  possible changes
	while (statetableline<2){ //must be below 2 because we've only two possible transition states
		statetable[statetableline][0]=fromState;
		statetable[statetableline][1]=triggerEvent;
		statetable[statetableline][2]=toState;
		printf("Insert %iº state  %i %i %i \n",statetableline+1, statetable[statetableline][0], statetable[statetableline][1], statetable[statetableline][2]);
		statetableline++;
		return(1);
	}
	return(0);
}


void historic(int prevState, int actEvent,int nextState){ //record the table historic transitions
	mathistoric[mathistoricline][0]=prevState;
	mathistoric[mathistoricline][1]=actEvent;
	mathistoric[mathistoricline][2]=nextState;
	mathistoricline++;
}



void PrintStateMachine(){  // print the current state of machine
		printf("Actual State Machine %i\n",mathistoric[mathistoricline-1][2]);
}



int ProcessEvent(int triggerEvent){ //according to the event the program chance to the correct state
	switch(state){
	case CLOSED:
		switch(triggerEvent){
		case CLOSED_OPENED:
			state=OPENED;
			historic(CLOSED, CLOSED_OPENED, OPENED);
			printf("Opened with success!!!\n");
			return(1);
		case OPENED_CLOSED:
			printf("The state is already closed!!!\n");
			return(0);
		default:
			exit(1);
			break;
		}
	break;
	case OPENED:
		switch(triggerEvent){
		case OPENED_CLOSED:
			state=CLOSED;
			historic(OPENED, OPENED_CLOSED, CLOSED);
			printf("Closed with success!!!\n");
			return(1);
		case CLOSED_OPENED:
			printf("The state is already opened!!!\n");
			return(0);
		default:
			exit(1);
			break;
		}
	break;
	}
return(0);
}


#endif /* STATEM22_v1_H_ */
