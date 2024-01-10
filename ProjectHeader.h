#include <stdio.h>
// #define _label_loop1
#ifndef Player
#define Player
int totalPlayers=0;
int size=10;
typedef struct Players
{
    int jerseyNo;
    char playerName[20];
    int noOfMatchPlayed;
    int noOfRuns;
    int noOfWickets;
}Players;
void doOperation(Players*,int*);
Players* resizeStructArray(Players*,int);
// int totalCountofPlayers( Players *);
// Players storePlayersInfo(Players *,int);
void printPlayersInfo(Players *);
int searchPlayerByJerseyNo(Players *, int);
void sortPlayerBy(Players *,int);
void removePlayerByJerseyNo(Players*,int);
int searchPlayerByName(Players *, char *);
void updatePlayerByJerseyNo(Players *, int);
void addPlayerInfo(Players *);
#endif