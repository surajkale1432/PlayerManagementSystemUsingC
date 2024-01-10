#include <stdio.h>

#ifndef Player
#define Player
int totalPlayers=0;
typedef struct Players
{
    int jerseyNo;
    char playerName[20];
    int noOfMatchPlayed;
    int noOfRuns;
    int noOfWickets;
}Players;
void doOperation(Players*,int*);
// int totalCountofPlayers( Players *);
// Players storePlayersInfo(Players *,int);
void printPlayersInfo(Players *);
int searchPlayerByJerseyNo(Players *, int);

void removePlayerByJerseyNo(Players*,int);
int searchPlayerByName(Players *, char *);
void updatePlayerByJerseyNo(Players *, int);
// void searchPlayersByCategory(Players *, char *);
// void doOperation (Players*,int);
void addPlayerInfo(Players *);
// void printPlayersInfobyIndex(Players *, int);
// void sortBookBy(Players*,int);
#endif