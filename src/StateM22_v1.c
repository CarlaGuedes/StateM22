/*
 ============================================================================
 Name        : StateM22_v1.c
 Author      : Carla Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "StateM22_v1.h"

int mathistoric[100][3]; // initialization of mathistoric table
int mathistoricline=0; // initialization of mathistoricline  to zero
int statetable[2][3]; // Declaration of statetable
int statetableline=0; // initialization of mathistoricline  to zero



enum states; // enumeration of states, is a data type that consists of integral constants, order the constant by sequence of record, as 0,1,2...
enum events; // enumeration of events, is a data type that consists of integral constants, order the constant by sequence of record, as 0,1,2...

int AddStateTransition(int fromState, int triggerEvent, int toState);

void historic(int prevState, int actEvent,int nextState);

void PrintStateMachine();

int ProcessEvent(int triggerEvent);

int main(void) { //Function main is the first to be one were the program execution always start from.
				 //int and void are the return type. Void means it will not return any value.
	int event; // Calling for the methods AddStateTransition and historic
	state=OPENED;
	AddStateTransition(CLOSED, CLOSED_OPENED, OPENED);
	AddStateTransition(OPENED, OPENED_CLOSED, CLOSED);
	historic(CLOSED, CLOSED_OPENED, OPENED);

	while(mathistoricline<100){ //while mathistoricline is below 100 (maximum allowed line),from mathistoric table, the program keep a state transition record.
		printf("\n");
		printf("****************************\n");
		printf("**                        **\n");
		printf("**  0 = CLOSED -> OPENED  **\n");
		printf("**  1 = OPENED -> CLOSED  **\n");
		printf("**  2 = CURRENT STATE     **\n");
		printf("**  3 = PRINT HISTORIC    **\n");
		printf("**  4 = PRINT STATE TABLE **\n");
		printf("**  5 = QUIT PROGRAM      **\n");
		printf("**                        **\n");
		printf("****************************\n");
		printf("\n");
		printf("Please insert option:");
		fflush(stdout);
		scanf("%i",&event);
		printf("\n");
		switch(event){ //for the selected option, it's called the respective method for each case.
		case 0:
			ProcessEvent(event);
			break;
		case 1:
			ProcessEvent(event);
			break;
		case 2:
			PrintStateMachine();
			break;
		case 3:
			printf("Table transition historic is:\n");
			for(int i=0; i<=mathistoricline-1;i++){
				printf("%i %i %i\n" ,mathistoric[i][0], mathistoric[i][1], mathistoric[i][2]);
			}
			break;
		case 4:
			printf("State Table is:\n");
			for(int i=0; i<=statetableline-1;i++){
				printf("%i %i %i\n" ,statetable[i][0], statetable[i][1], statetable[i][2]);
			}
			break;
		case 5:
			printf("The program is closed!!!");
			return EXIT_SUCCESS;
		default:
			printf("Wrong option, please see again!!!\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}

int AddStateTransition(int fromState, int triggerEvent, int toState){ //Add to the table (statetable), each  possible changes
	while (statetableline<2){ //must be below 2 because we've only two possible transition states
		statetable[statetableline][0]=fromState;
		statetable[statetableline][1]=triggerEvent;
		statetable[statetableline][2]=toState;
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
