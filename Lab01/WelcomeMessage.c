/*
 * WelcomeMessage.c
 *
 *  Created on: 2017�~9��19��
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

	printf("Your choice is %d\n", answer);

}

