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
    int dealerPoint1 = 0, playerPoint1 = 0, dealerPoint2 = 0, playerPoint2 = 0, Dsum = 0, Psum = 0, card[52] = {0}, age = 0;
    int *cardPosition = card, *dP1 = &dealerPoint1, *pP1 = &playerPoint1, *dP2 = &dealerPoint2, *pP2 = &playerPoint2, *dS = &Dsum, *pS= &Psum;
    char inputChar[2], name[SIZE];
    char *ptr = inputChar;         //define point *ptr = address
	if (WelcomeMessage() == 1){
		age = InputPersonalInformation(name);
		if(age)         //if return value is 1(younger), run function "return 0"
			return 0;       //end function
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
