// Project 1 CS-1714-0E5
#ifndef DICEGAME_H //its a .h file...
#define DICEGAME_H

typedef enum { //for types of rouinds
    BONUS,
    DOUBLE,
    REGULAR
} ROUNDTYPE;

int getRandomNumber(int min, int max); //dice game .c stuffs
ROUNDTYPE getRoundType();
int getRoundPoints(ROUNDTYPE roundType);
void printPlayerPoints(int p1, int p2);
void printRoundInfo(ROUNDTYPE t, int dice, int points);

#endif /* DICEGAME_H */
