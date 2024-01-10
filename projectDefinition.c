#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjectHeader.h"

void printPlayersInfo(Players *player)
{
    int i;
    for (i = 0; i < totalPlayers; i++)
    {
        printf("\n-----------------------------------------------------------\n");
        printf("\nJersey No             = %d", player[i].jerseyNo);
        printf("\nPlayer Name           = %s", player[i].playerName);
        printf("\nNo. Of Matches Played = %d", player[i].noOfMatchPlayed);
        printf("\nNo. Of Runs by Player = %d", player[i].noOfRuns);
        printf("\nNo. Of Wickets taken  = %d", player[i].noOfWickets);
    }
}
Players* resizeStructArray(Players *player,int totalSize)
{
    printf("\nEnter New SIZE = ");
    scanf("%d",&size);
    player=(Players*)realloc(player,(size+totalSize)*sizeof(Players));
}
void addPlayerInfo(Players *player)
{
    int i;
    for (i = 0; i < 1; i++)
    {
        printf("\nEnter Players information");
        printf("\nJersey No             = ");
        scanf("%d", &player[totalPlayers].jerseyNo);
        printf("\nPlayer Name           = ");
        fflush(stdin);
        gets(player[totalPlayers].playerName);
        printf("\nNo. Of Matches Played = ");
        scanf("%d", &player[totalPlayers].noOfMatchPlayed);
        printf("\nNo. Of Runs by Player = ");
        scanf("%d", &player[totalPlayers].noOfRuns);
        printf("\nNo. Of Wickets taken  = ");
        scanf("%d", &player[totalPlayers].noOfWickets);
        totalPlayers++;
        printf("\nPlayer Added Successfully ...!!!");
    }
}
int searchPlayerByJerseyNo(Players *player, int jerseyNo)
{

    int i, foundIndex = -1;
    for (i = 0; i < totalPlayers; i++)
    {
        if (player[i].jerseyNo == jerseyNo)
        {
            foundIndex++;
            return i;
        }
    }
    if (foundIndex == -1)
    {
        printf("\nError : Player Not Found");
        return foundIndex;
    }
}
int searchPlayerByName(Players *player, char *searchPlayerName)
{
    int i, foundIndex = -1;
    for (i = 0; i < totalPlayers; i++)
    {
        if (strcasecmp(player[i].playerName, searchPlayerName) == 0)
        {
            foundIndex++;
            return i;
        }
    }
    if (foundIndex == -1)
    {
        printf("\nError : Player Not Found ...!!!");
        return foundIndex;
    }
}
void removePlayerByJerseyNo(Players *player, int i)
{
    for (i; i < totalPlayers; i++)
    {
        player[i] = player[i + 1];
    }
    printf("\nPlayer Removed Successfully");
    totalPlayers--;
}
void updatePlayerByJerseyNo(Players *player, int i)
{
    printf("\nEnter Details to Update\nNo. Of Matches Played = ");
    scanf("%d", &player[i].noOfMatchPlayed);
    printf("\nNo. Of Runs by Player = ");
    scanf("%d", &player[i].noOfRuns);
    printf("\nNo. Of Wickets taken  = ");
    scanf("%d", &player[i].noOfWickets);
    printf("\nDetails Updated Successfully ...!!!");
}
void sortPlayerBy(Players *player, int ch)
{
    int order, i, j;
    printf("\n1. Ascending\n2. Descending\nChoice = ");
    scanf("%d", &order);
    for (i = 0; i < totalPlayers; i++)
    {
        for (j = i + 1; j < totalPlayers; j++)
        {
            if(ch==1 && order==1)
            {
                if(player[i].jerseyNo>player[j].jerseyNo)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
            else if(ch==1 && order==2)
            {
                if(player[i].jerseyNo<player[j].jerseyNo)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
            else if(ch==2 && order==1)
            {
                if(player[i].noOfWickets>player[j].noOfWickets)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
            else if(ch==2 && order==2)
            {
                if(player[i].noOfWickets<player[j].noOfWickets)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
            else if(ch==3 && order==1)
            {
                if(player[i].noOfRuns>player[j].noOfRuns)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
            else if(ch==3 && order==2)
            {
                if(player[i].noOfRuns<player[j].noOfRuns)
                {
                    Players temp=player[i];
                    player[i]=player[j];
                    player[j]=temp;
                }
            }
        }
    }
}
void printPlayerInfoByIndex(Players *player, int i)
{
    printf("\nJersey No             = %d", player[i].jerseyNo);
    printf("\nPlayer Name           = %s", player[i].playerName);
    printf("\nNo. Of Matches Played = %d", player[i].noOfMatchPlayed);
    printf("\nNo. Of Runs by Player = %d", player[i].noOfRuns);
    printf("\nNo. Of Wickets taken  = %d", player[i].noOfWickets);
}

void doOperation(Players *player, int *ch)
{
    int totalPlayer, searchJerseyNo, foundIndex = -1;
    char *searchPlayerName;
    switch (*ch)
    {
    case 1:
        addPlayerInfo(player);
        break;

    case 2:
        printPlayersInfo(player);
        break;
    case 3:

        printf("\nEnter Jersey No    = ");
        scanf("%d", &searchJerseyNo);
        foundIndex = searchPlayerByJerseyNo(player, searchJerseyNo);
        if (foundIndex != -1)
        {
            printPlayerInfoByIndex(player, foundIndex);
        }
        break;

    case 4:
        printf("\nEnter Player Name  = ");
        fflush(stdin);
        gets(searchPlayerName);
        foundIndex = searchPlayerByName(player, searchPlayerName);
        if (foundIndex != -1)
        {
            printPlayerInfoByIndex(player, foundIndex);
        }
        break;

    case 5:
        printf("\nEnter Jersey No to Remove Player = ");
        scanf("%d", &searchJerseyNo);
        foundIndex = searchPlayerByJerseyNo(player, searchJerseyNo);
        if (foundIndex != -1)
        {
            removePlayerByJerseyNo(player, foundIndex);
        }
        break;

    case 6:
        totalPlayer = totalPlayers;
        printf("\nTotal Players in Team = %d", totalPlayer);
        break;

    case 7:
        printf("\nEnter JerseyNo to Update PlayerDetails = ");
        scanf("%d", &searchJerseyNo);
        foundIndex = searchPlayerByJerseyNo(player, searchJerseyNo);
        if (foundIndex != -1)
        {
            updatePlayerByJerseyNo(player, foundIndex);
        }
        break;

    case 8:
        printf("\n\n1. Sort By Runs\n2. Sort By Wickets\n3. Sort By Matches\nChoice = ");
        scanf("%d", &*ch);
        sortPlayerBy(player, *ch);
        break;
    }
}
