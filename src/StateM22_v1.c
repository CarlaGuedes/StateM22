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

enum states {  //Take into account the following values: CLOSED=0 e OPENED=1
	CLOSED,
	OPENED,
}state;

enum events {  //Take into account the following values: CLOSED_OPENED=0 e OPENED_CLOSED=1
	CLOSED_OPENED,
	OPENED_CLOSED,
}triggerEvent;

int ProcessEvent(int triggerEvent){
	switch(state){
	case CLOSED:
		switch(triggerEvent){
		case CLOSED_OPENED:
			state=OPENED;
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
