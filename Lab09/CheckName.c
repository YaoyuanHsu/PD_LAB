/*
 * ModulizeBlackjack.c
 *
 *  Created on: 2017¦~10¤ë3¤é
 *      Author: Yuan
 */
#include <stdio.h>
#include <stdlib.h>   // "rand" and "srand"are included in the header file, "stdlib.h"
#include <time.h>       //include time header for rand seed
#include <string.h> 	//for using strlen
#include <ctype.h>		//for using isaplpha
#include "Blackjack.h"
#define SIZE 21

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    int dealerPoint1 = 0, playerPoint1 = 0, dealerPoint2 = 0, playerPoint2 = 0, Dsum = 0, Psum = 0, card[52] = {0};
    int *cardPosition = card, *dP1 = &dealerPoint1, *pP1 = &playerPoint1, *dP2 = &dealerPoint2, *pP2 = &playerPoint2, *dS = &Dsum, *pS= &Psum;
    char inputChar[2], name[SIZE];
    char *ptr = inputChar;         //define point *ptr = address
	if (WelcomeMessage() == 1){
		InputName(name);
		printf("Hello, %s\n", name);
        puts("Start Game!\n===============================");
        puts("Select the mode you want:");

        while(MenuSelection(ptr)){        //send pointer to the function
            switch(inputChar[0])
            {
                case 'A':
                case 'a':
                        ShuffleCards(card);
                        dealerPoint1 = playerPoint1 = dealerPoint2 = playerPoint2 = Dsum = Psum = 0;        //Reset if you shuffle cards again after playing
                        puts("Cards message shuffled!");
                        /*for(size_t f = 0; f < 52; ++f){
                            printf("%-3d", card[f]);        //print from left side
                            if(f%13 == 12)
                                puts("");
                        }*/
                        puts("===============================");
                    break;

                case 'B':
                case 'b':
					cardPosition = DealCards(cardPosition, dP1, pP1, dP2, pP2, dS, pS);         //Deal cards and return the last card position after dealing
                    break;

                case 'C':
                case 'c':
                    printf("Your selection is C) Exit Game\n===============================\n");
                    return 0;
                    break;

                default:
                    printf("Your selection is %s. \nPlease select A, B or C\n===============================\n", inputChar);
                    break;
            }
        }

    }
    else{
        printf("Good bye!\n===============================\n");
    }

}

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

void InputName(char* name)
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

int Face(int* card)     //the initial date of cards is num1 to num52, so we have to change it to ace~king
{
    int point = *card;
    point %= 13;        //define card ace~queen
    if(point == 0)
    	point = 13;     //if the reminder is 0, set it become king
    return point;
}

int MenuSelection(char* inputChar)     //pass by reference to change value
{
    while(1){
        puts("\nA) Shuffle Cards \nB) Play Game \nC) Exit Game");
        scanf("%s", inputChar);
        if(*(inputChar + 1) == 0)       //if input is a character, then return 1 and start input selection
            return 1;
        printf("Your selection is %s. Please select A, B or C\n===============================\n", inputChar);
    }
}

int* DealCards(int* cardPosition, int* dP1, int* pP1, int* dP2, int* pP2, int* ds, int* ps)
{
    *dP1 = *pP1 = *dP2 = *pP2 = *ds = *ps = 0;          //reset all value to initial value, 0
    *dP1 =  Face(cardPosition);     //use face to get the card point  ace~king
    cardPosition++;         //position plus
    Point(dP1, ds);         //change to blackjack form and plus to sum
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
    if(*dP1 == *dP2 == 1)       //if you get two ace, you have to make some change
        *ds = 12;
    if(*pP1 == *pP2 == 1)
        *ps = 12;
    //printf("%d-%d", *ds, *ps);
    if((*ds > 21 &&  *ps <= 21) || (*ps >*ds && *ps <= 21))
        printf("You Win!!\n===============================\n");
    else if((*ds == *ps) || ((*ds >= 21) && (*ps >= 21)))
        printf("You Push!!\n===============================\n");
    else
        printf("You Lose!!\n===============================\n");
    return cardPosition;
}

void Point(int* face, int* sum)         //change cards ace~king to blackjack form
{
	if((*face == 13) || (*face == 12) || (*face == 11))     //set king, queen, and jack to 10
        *sum += 10;
	else if(*face == 1)         //set ace to 11
        *sum += 11;
    else
        *sum += *face;
}
