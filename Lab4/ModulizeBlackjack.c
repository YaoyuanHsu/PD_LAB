/*
 * ModulizeBlackjack.c
 *
 *  Created on: 2017¦~10¤ë3¤é
 *      Author: 1MF10
 */
#include <stdio.h>
#include "Blackjack.h"    //include "header.h" can use to read function head title

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    int inputChar, output, integer = 0;

	if (WelcomeMessage() == 1){
        printf("Start Game!\n");
        printf("Select the mode you want:\n");
        printf("A) Shuffle Cards \nB) Play Game \nC) Exit Game\n");
        getchar();
        inputChar = getchar();
        switch(inputChar)
        {
            case 'A':
            case 'a':
                for(output = 0 ;integer <= 30 ; integer+=2)
                    output+=integer;
                printf("The sum of the even integers from 2 to 30 is %d\n", output);
                break;
            case 'B':
            case 'b':
                printf("Your selection is B) Play Game\n");
                break;
            case 'C':
            case 'c':
                printf("Your selection is C) Exit Game\n");
                break;
            default:
                printf("Your selection is %c. Please select A, B or C", inputChar);
                break;
        }

    }
    else{
        printf("Good bye!\n");
    }

}

int WelcomeMessage()
{
	int answer;
	puts("Welcome to Blackjack Game!");
	puts("Are you ready?  1) Yes  2)No");
	scanf("%d", &answer);
	while (answer > 2 || answer < 1){
		printf("Illegal choice! Please input 1 or 2!\n");
		scanf("%d", &answer);
	}
	return answer;
}

