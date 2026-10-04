#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

// makes new champ guy
Champion *createChampion() {
    Champion *champion = (Champion *)malloc(sizeof(Champion));
    if (champion == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    //makes randowm
    champion->role = rand() % 4;
    switch (champion->role) {
        case MAGE:
            champion->level = rand() % 8 + 1; // level 1-8
            break;
        case FIGHTER:
            champion->level = rand() % 6 + 2; // level 2-7
            break;
        case SUPPORT:
            champion->level = rand() % 4 + 3; // level 3-6
            break;
        case TANK:
            champion->level = rand() % 4 + 6; // level 6-9
            break;
    }
    champion->next = NULL;
     return champion;
}

// puts a new guy into the list
Champion *addChampion(Champion *head, Champion *c) {
    if (head == NULL) {
        return c;
    }
    Champion *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = c;
         return head;
}

// builds the list for champs
Champion *buildChampionList(int n) {
    Champion *head = NULL;
    for (int i = 0; i < n; i++) {
        Champion *newChampion = createChampion();
        head = addChampion(head, newChampion);
    }
     return head;
}

// actually prints champion lsit
void printChampionList(Champion *head) {
    Champion *current = head;

    while (current != NULL) {
        printf("%c%d ", current->role + 'A', current->level);

        current = current->next;
    }


    printf("\n");

}
// gets rid of champs in list when loss
Champion *removeChampion(Champion *head) {
    if (head == NULL) {
        return NULL;
    }


     Champion *temp = head;
      head = head->next;
    free(temp);

    return head;

}

// nukes everything to clean up

Champion *destroyChampionList(Champion *head) {

    while (head != NULL) {
         head = removeChampion(head);
    }

    return NULL;
}
