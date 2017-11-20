/*
 * ModulizeBlackjack.c
 *
 *  Created on: 2017¦~10¤ë3¤é
 *      Author: 1MF10
 */
#include <stdio.h>
#include <stdlib.h>   // "rand" and "srand"are included in the header file, "stdlib.h"
#include <time.h>       //include time header for rand seed
#include "Blackjack.h"
#define SIZE 21

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    int output, number, index = 0, dealerPoint = 0, playerPoint = 0, integer = 0, card[52] = {0};
    int *cardPosition = &index;
    char inputChar[2], name[SIZE];
    char *ptr = inputChar;         //define point *ptr = address
	if (WelcomeMessage() == 1){
		InputName(name);
		printf("Hello, %s\n", name);
        puts("Start Game!");
        puts("Select the mode you want:");

        while(MenuSelection(ptr)){        //send pointer to the function
            switch(inputChar[0])
            {
                case 'A':
                case 'a':
                        ShuffleCards(card);
                        index = dealerPoint = playerPoint = 0;
                        puts("Cards message shuffled!");
                        for(size_t f = 0; f < 52; ++f){
                            printf("%-3d", card[f]);        //print from left side
                            if(f%13 == 12)
                                puts("");
                        }
                        puts("");
                    break;

                case 'B':
                case 'b':
                    dealerPoint += Face(card, cardPosition);
                    playerPoint += Face(card, cardPosition);
                    printf("\nDealer's point: %d\n", dealerPoint);
                    printf("Player's point: %d\n", playerPoint);
                    if(((dealerPoint < playerPoint) && (playerPoint <= 21)) || (dealerPoint > 21 && playerPoint <= 21))
                        printf("You Win!!\n");
                    else if((dealerPoint == playerPoint) || ((dealerPoint >=21) && (playerPoint >=21)))
                        printf("You Push!!\n");
                    else
                        printf("You Lose!!\n");
                    break;

                case 'C':
                case 'c':
                    printf("Your selection is C) Exit Game\n");
                    return 0;
                    break;

                default:
                    printf("Your selection is %s. Please select A, B or C\n", inputChar);
                    break;
            }
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
	printf("Are you ready?  \n1) Yes  2)No  ");
	scanf("%d", &answer);
	while ((answer != 1) && (answer != 2)){
		puts("Illegal choice! Please input 1 or 2!");
		scanf("%d", &answer);
	}
	return answer;
}

void InputName(char* name)
{
    printf("Please input your English name:  ");
    scanf("%20s", name);
}

void ShuffleCards(int *card)       //initial setting 52 cards and switch
{
	int temp = 0, j = 0;
	for(size_t f = 0; f < 52; ++f)
        card[f] = f + 1;
	for(size_t f = 0; f < 52; ++f){
		j = rand() % 52;
		temp = card[f];
		card[f] = card[j];
		card[j] = temp;
	}
}

int Face(int* card, int* cardPosition)
{
    int point = card[*cardPosition];
    point%=13;
    if(point == 0)
    	point = 13;
    DealCards(cardPosition);
    return point;
}

int MenuSelection(char* inputChar)     //pass by reference to change value
{
    while(1){
        puts("\nA) Shuffle Cards \nB) Play Game \nC) Exit Game");
        scanf("%s", inputChar);
        if(*(inputChar + 1) == 0)
            return 1;
        printf("Your selection is %s. Please select A, B or C\n", inputChar);
    }
}

void DealCards(int* cardPosition)
{
    (*cardPosition)++;
}
