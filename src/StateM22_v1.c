/*
 ============================================================================
 Name        : StateM.c
 Author      : Carla Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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
		printf("AddStateTransition %i %i %i %i\n",statetable[statetableline][0], statetable[statetableline][1], statetable[statetableline][2], statetableline);
		statetableline++;
		return(1);
	}
	return(0);
}


void historic(int prevState, int actEvent,int nextState){ //record the table historic transitions
	mathistoric[mathistoricline][0]=prevState;
	mathistoric[mathistoricline][1]=actEvent;
	mathistoric[mathistoricline][2]=nextState;
	printf("historic %i %i %i %i\n" ,mathistoric[mathistoricline][0], mathistoric[mathistoricline][1], mathistoric[mathistoricline][2], mathistoricline);
	mathistoricline++;
}



void PrintStateMachine(){  // print the current state of machine
		printf("PrintStateMachine %i\n",mathistoric[mathistoricline-1][2]);
}


int ProcessEvent(int triggerEvent){ //according to the event the program chance to the correct state
	switch(state){
	case CLOSED:
		switch(triggerEvent){
		case CLOSED_OPENED:
			state=OPENED;
			historic(CLOSED, CLOSED_OPENED, OPENED);
			return(1);
		case OPENED_CLOSED:
			printf("The state is already closed!!!");
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
			return(1);
		case CLOSED_OPENED:
			printf("The state is already opened!!!");
			return(0);
		default:
			exit(1);
			break;
		}
	break;
	}
return(0);
}


int main(void) {
	state=OPENED;
	//int i = ProcessEvent(OPENED_CLOSED);
	int a = AddStateTransition(CLOSED, CLOSED_OPENED, OPENED);
	int b = AddStateTransition(OPENED, OPENED_CLOSED, CLOSED);
	int c = AddStateTransition(CLOSED, OPENED_CLOSED, OPENED);
	int d = AddStateTransition(OPENED_CLOSED, OPENED_CLOSED, OPENED);
	PrintStateMachine();
	//printf("texto\n");
	//printf("texto %i\n",i);
	//printf("texto %i\n" , ProcessEvent(CLOSED_OPENED));
	printf("estado %i %i %i %i\n",a,b,c,d);
	return EXIT_SUCCESS;
}
