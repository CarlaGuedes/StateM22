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

int statetable[2][3]; // initialization of statetable


enum states;
enum events;

int AddStateTransition(int fromState, int triggerEvent, int toState);

void historic(int prevState, int actEvent,int nextState);

void PrintStateMachine();

int ProcessEvent(int triggerEvent);

int main(void) {
	int event;
	state=OPENED;
	AddStateTransition(CLOSED, CLOSED_OPENED, OPENED);
	AddStateTransition(OPENED, OPENED_CLOSED, CLOSED);
	historic(CLOSED, CLOSED_OPENED, OPENED);

	while(mathistoricline<100){
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
		switch(event){
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
