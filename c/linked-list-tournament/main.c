#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

#define NUM_ROLES 4

// shows end of battle
int outcomes[NUM_ROLES][NUM_ROLES] = {
        // MAGE    FIGHTER  SUPPORT  TANK
        {0,       1,       1,       2},    // mage
        {2,       0,       1,       1},    // fighter
        {2,       2,       0,       1},    // support
        {1,       1,       2,       0}     // tank
};

// prints the names
const char *roleNames[NUM_ROLES] = {"MAGE", "FIGHTER", "SUPPORT", "TANK"};

// actually concludes the winner
void determineOutcome(Champion *player1, Champion *player2, int round) {

    Champion *champion1 = player1->next;
    Champion *champion2 = player2->next;


    player1->next = player1->next->next;

    player2->next = player2->next->next;

    int role1 = champion1->role;
    int role2 = champion2->role;

    int result = outcomes[role1][role2];


    printf("----- ROUND %d -----\n", round);

    printf("Player 1: ");


     printChampionList(player1);

    printf("Player 2: ");

    printChampionList(player2);

     printf("Player 1 is a %s and Player 2 is a %s\n", roleNames[role1], roleNames[role2]);

    if (result == 0) {
        printf("It's a tie!\n");

    }
    else if (result == 1) {
        printf("Player 1 (%s) wins and gains one new champion.\n", roleNames[role1]);
        printf("Player 2 (%s) loses this round.\n", roleNames[role2]);
        Champion *newChampion = createChampion();
        player1->next = addChampion(player1->next, newChampion);

    }
    else if (result == 2) {
        printf("Player 2 (%s) wins and gains one new champion.\n", roleNames[role2]);
        printf("Player 1 (%s) loses this round.\n", roleNames[role1]);
        Champion *newChampion = createChampion();
        player2->next = addChampion(player2->next, newChampion);
    }

}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_champions>\n", argv[0]);
        return 1;
    }
    int numChampions = atoi(argv[1]);
    if (numChampions <= 0) {
        printf("Number of champions must be greater than 0.\n");
        return 1;

    }

    srand(time(NULL));
    Champion *player1 = buildChampionList(numChampions);

    Champion *player2 = buildChampionList(numChampions);

    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
    int round = 1;
    while (player1->next && player2->next) {
        determineOutcome(player1, player2, round++);
    }


    printf("============ GAME OVER =============\n");

    printf("Player 1 ending champion list: ");
    printChampionList(player1->next);
    if (!player2->next) {

        printf("Player 2 ending champion list:\n");
        printf("Player 2 ran out of champions. Player 1 wins.\n");


    } else {
        printf("Player 2 ending champion list: ");
        printChampionList(player2->next);
        printf("Player 1 ran out of champions. Player 2 wins.\n");
    }


       player1 = destroyChampionList(player1);
      player2 = destroyChampionList(player2);

    return 0;
}
