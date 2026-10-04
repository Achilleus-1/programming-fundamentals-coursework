// Project 1 CS-1714-0E5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main() {
    srand(time(NULL)); // starts random number generator

    int totalRounds, currentRound, currentPlayer, player1Points = 0, player2Points = 0;

    printf("Enter the number of rounds: ");
    scanf("%d", &totalRounds);

    printf("P1      : 0\n");
    printf("P2      : 0\n\n");

    for (currentRound = 1; currentRound <= totalRounds; currentRound++) {
        printf("ROUND %d\n", currentRound);
        printf("--------\n");

        currentPlayer = (currentRound % 2 == 1) ? 1 : 2;

        ROUNDTYPE roundType = getRoundType();
        int dice = getRandomNumber(1, 6);
        int points = getRoundPoints(roundType);

        printf("Player  : %d\n", currentPlayer);
        printRoundInfo(roundType, dice, points);

        if ((currentPlayer == 1 && dice % 2 == 1) || (currentPlayer == 2 && dice % 2 == 0)) {  // Success HERE
            if (roundType == BONUS)
                points = 200;
            else if (roundType == DOUBLE) // Fail HERE
                points *= 2;
        } else {
            if (roundType != BONUS) //ALL CAPS MF DOOM REFERENCE !!!
                points *= -1;
            currentPlayer = (currentPlayer == 1) ? 2 : 1;   // Switch player
        }

        if (currentPlayer == 1)
            player1Points += points;
        else
            player2Points += points;

        printPlayerPoints(player1Points, player2Points);
        printf("\n");
    }

    printf("GAME OVER!!\n");
    if (player1Points > player2Points)
        printf("P1 Won\n");
    else if (player2Points > player1Points)
        printf("P2 Won\n");
    else
        printf("It's a Tie\n"); //no caps

    return 0;
}
