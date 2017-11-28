/*
 * Blackjack.c
 *
 *  Created on: 2017¦~11¤ë28¤é
 *      Author: 1MF10
 */
#include <stdio.h>
#include <stdlib.h>   // "rand" and "srand"are included in the header file, "stdlib.h"
#include <time.h>       //include time header for rand seed
#include <string.h> 	//for using strlen
#include <ctype.h>		//for using isaplpha
#include "Blackjack.h"
#define SIZE 21

int WelcomeMessage()
{
	int answer;
	puts("Welcome to Blackjack Game!");
	printf("Are you ready?  \n1) Yes  2)No  ");
	scanf("%d", &answer);
	while ((answer != 1) && (answer != 2)){
		printf("===============================\nIllegal choice! \nPlease input 1 or 2!Try again:");
		scanf("%d", &answer);
	}
	return answer;
}

int InputPersonalInformation(char* name)
{
    int len = 0, alpha = 0;
	printf("===============================\nPlease input your English name:\n");
    scanf("%s", name);
    len = strlen(name);
    for(size_t f = 0; f < len; ++f){
    	if(isalpha(name[f]) == 0){
    	    if(name[f] != '-')
    	    	alpha++;
    	   }
    }
    while ((len > 20) || (alpha != 0)){
    	 puts("Illegal name");
    	 alpha = 0;
    	 scanf("%s", name);
    	 len = strlen(name);
    	 for(size_t f = 0; f < len; ++f){
    		 if(isalpha(name[f]) == 0){
    			 if(name[f] != '-')
    				 alpha++;
    		 }
    	 }
    }
   int month = 0, day = 0, year = 0;
   printf("Please input your personal information (mm-dd-yyyy): ");
   scanf("%d%*c%d%*c%d", &month, &day, &year);
   if(year >= 1999){
	   printf("Good bye! %s", name);
	   return 1;
   }
   return 0;

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

int Face(int* card)
{
    int point = *card;
    point %= 13;
    if(point == 0)
    	point = 13;
    return point;
}

int MenuSelection(char* inputChar)     //pass by reference to change value
{
    while(1){
        puts("\nA) Shuffle Cards \nB) Play Game \nC) Exit Game");
        scanf("%s", inputChar);
        if(*(inputChar + 1) == 0)
            return 1;
        printf("Your selection is %s. Please select A, B or C\n===============================\n", inputChar);
    }
}

int* DealCards(int* cardPosition, int* dP1, int* pP1, int* dP2, int* pP2, int* ds, int* ps)
{
    *dP1 = *pP1 = *dP2 = *pP2 = *ds = *ps = 0;
    *dP1 =  Face(cardPosition);
    cardPosition++;
    Point(dP1, ds);
    *pP1 =  Face(cardPosition);
    cardPosition++;
    Point(pP1, ps);
    *dP2 =  Face(cardPosition);
    cardPosition++;
    Point(dP2, ds);
    *pP2 =  Face(cardPosition);
    cardPosition++;
    Point(pP2, ps);
    printf("\nDealer's cards: %d & %d\n", *dP1, *dP2);
    printf("Player's cards: %d & %d\n", *pP1, *pP2);
    //printf("%d-%d", *ds, *ps);
    if(((*ds < *ps) && (*ps <= 21)) || (*ds > 21 && *ps <= 21))
        printf("You Win!!\n===============================\n");
    else if((*ds == *ps) || ((*ds >= 21) && (*ps >= 21)))
        printf("You Push!!\n===============================\n");
    else
        printf("You Lose!!\n===============================\n");
    return cardPosition;
}

void Point(int* face, int* sum)
{
	if((*face == 13) || (*face == 12) || (*face == 11))
        *sum += 10;
	else if(*face == 1)
        *sum += 11;
    else
        *sum += *face;
}
