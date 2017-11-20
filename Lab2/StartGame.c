/*
 * StartGame.c
 *
 *  Created on: 2017¦~9¤ë19¤é
 *      Author: 1MF10
 */
#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	int answer;
	puts("Welcome to Blackjack Game!");
	puts("Are you ready?  1) Yes  2)No");

	scanf("%d", &answer);
	while(answer > 2 || answer < 1){
		printf("Illegal choice! Please input 1 or 2!\n");
		scanf("%d", &answer);
	}

	if(answer == 1)
			printf("Start Game!\n");
	else
			printf("Good bye!\n");


}
