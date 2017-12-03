/*
 * ModulizeBlackjack.c
 *
 *  Created on: 2017¦~10¤ë3¤é
 *      Author: 1MF10
 */
#include <stdio.h>
#include <stdlib.h>   // "rand" and "srand"are included in the header file, "stdlib.h"
#include <time.h>
#include "Blackjack.h"
#define SIZE 21

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    int output, number, integer = 0, ASCII, card[52] = {0};
    char inputChar, name[SIZE];
    char *ptr = &inputChar;         //define point *ptr = address
	if (WelcomeMessage() == 1){
		InputName(name);
		printf("Hello, %s\n", name);
        ASCII = MagicNumber(name);
        printf("Your magic number is %d\n\n", ASCII);
        printf("Start Game!\n");
        printf("Select the mode you want:\n");
        MenuSelection(ptr);         //send pointer to the function

        switch(inputChar)
        {
            case 'A':
            case 'a':
                ShuffleCards(card);
                printf("The value of one item in cards:\n");
                for(size_t f = 0; f < 52; ++f){
                   	printf("%3d", card[f]);
                   	if(f%13 == 12)
                        puts("");
                }
                puts("");
                printf("The sum is %d\n\n", Face(card[0]) +Face(card[2]));
                for(output = 0 ;integer <= 30 ; integer+=2)
                    output+=integer;
                printf("The sum of the even integers from 2 to 30 is %d\n", output);
                break;
            case 'B':
            case 'b':
            	number = sizeof(card)/sizeof(card[0]);
            	printf("The number of cards is %d", number);
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

void InputName(char name[])
{
    printf("Please input your English name:  ");
    scanf("%20s", name);
}

int MagicNumber(char name[])
{
    int ASCII = 0;
    for(size_t s = 0; s < SIZE && name[s] != '\0'; ++s)
    	ASCII += name[s];
    return ASCII;
}

void ShuffleCards(int card[])       //initial setting 52 cards and switch
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

int Face(int card)
{
    card%=13;
    if(card == 0)
    	card = 13;
    return card;
}

void MenuSelection(char* inputchar)     //pass by reference to change value
{
    printf("A) Shuffle Cards \nB) Play Game \nC) Exit Game\n");
    getchar();
    *inputchar = getchar();
}
