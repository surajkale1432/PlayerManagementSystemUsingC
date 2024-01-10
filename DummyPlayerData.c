#include "ProjectHeader.h"
void DummyPlayerData(Players *player)
{
    player[0].jerseyNo=1;
    strcpy(player[0].playerName,"Virat Kohli");
    player[0].noOfMatchPlayed=12;
    player[0].noOfRuns=356;
    player[0].noOfWickets=32;
    totalPlayers++;

    player[1].jerseyNo=2;
    strcpy(player[1].playerName,"Sachin Tendulkar");
    player[1].noOfMatchPlayed=112;
    player[1].noOfRuns=386;
    player[1].noOfWickets=72;
    totalPlayers++;

    player[2].jerseyNo=3;
    strcpy(player[2].playerName,"M. S. Dhoni");
    player[2].noOfMatchPlayed=156;
    player[2].noOfRuns=3565;
    player[2].noOfWickets=92;
    totalPlayers++;

}


