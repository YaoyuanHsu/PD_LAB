/*
 * ModulizeBlackjack.c
 *
 *  Created on: 2017¦~10¤ë3¤é
 *      Author: Yuan
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
                        dealerPoint1 = playerPoint1 = dealerPoint2 = playerPoint2 = Dsum = Psum = 0;
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
					cardPosition = DealCards(cardPosition, dP1, pP1, dP2, pP2, dS, pS);
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
    printf("===============================\nPlease input your English name:\n");
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
