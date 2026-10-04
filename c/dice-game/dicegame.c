// Project 1 CS-1714-0E5
#include "dicegame.h"
#include <stdlib.h>
#include <stdio.h>

int getRandomNumber(int min, int max) { // generates random number between min and max function
    return rand() % (max - min + 1) + min;
}

ROUNDTYPE getRoundType() { // determines type of round based on chance fucntion
    int random = getRandomNumber(0, 9);
    if (random < 2)
        return BONUS; //i love capitals
    else if (random < 5)
        return DOUBLE;
    else
        return REGULAR;
}

int getRoundPoints(ROUNDTYPE roundType) { // to get points for round based on its type
    return getRandomNumber(1, 10) * 10; // Points between 10-100
}

void printPlayerPoints(int p1, int p2) { // Print player points at end of each round
    printf("P1      : %d\n", p1);
    printf("P2      : %d\n", p2);
}
// prints round information (duh)
void printRoundInfo(ROUNDTYPE t, int dice, int points) {
    printf("Type    : "); //no caps here because I feel like it
    switch (t) {
        case BONUS: //still love capitals
            printf("BONUS\n");
            break;
        case DOUBLE:
            printf("DOUBLE\n");
            break;
        case REGULAR:
            printf("REGULAR\n");
            break;
    }
    printf("Dice    : %d\n", dice);
    printf("Points  : %d\n", points);
}
