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

int mathistoric[100][3];
int mathistoricline=0;

enum states {  //Take into account the following values: CLOSED=0 e OPENED=1
	CLOSED,
	OPENED,
}state;

enum events {  //Take into account the following values: CLOSED_OPENED=0 e OPENED_CLOSED=1
	CLOSED_OPENED,
	OPENED_CLOSED,
}triggerEvent;

void historic(int prevState, int actEvent,int nextState){
	mathistoric[mathistoricline][0]=prevState;
	mathistoric[mathistoricline][1]=actEvent;
	mathistoric[mathistoricline][2]=nextState;
	printf("historic %i %i %i %i\n" ,mathistoric[mathistoricline][0], mathistoric[mathistoricline][1], mathistoric[mathistoricline][2], mathistoricline);
	mathistoricline++;
}

int ProcessEvent(int triggerEvent){
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
	int i = ProcessEvent(OPENED_CLOSED);
	printf("texto\n");
	printf("texto %i\n",i);
	printf("texto %i\n" , ProcessEvent(CLOSED_OPENED));
	return EXIT_SUCCESS;
}
