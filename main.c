#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectDefinition.c"
#include "DummyPlayerData.c"
void main()
{
    Players *player;
    player = (Players*)malloc(sizeof(Players) * size);   //3000 3024 3048
    char choice[20];
    int ch;
    char *str;
    DummyPlayerData(player);
    _label_loop1:
    do
    {
        // printf("\n%d", sizeof(Players));
        printf("\n*******************************************************************\n");
        printf("\nWelcome To Player Management System.\nPlease Select Your Choice.\n");
        printf("1. Add Player to Team.\n2. Display All Players Info.\n3. Search Player by Jersey No\n4. Search Player by Name ");
        printf("\n5. Remove Player from Team\n6. Total Players in Team\n7. Update Players Info\n8. Sort Players\n0. Exit");
        printf("\nChoice = ");
        scanf("%s", &choice);
        str = choice;
        ch = atoi(str);
        if (!(ch > 0 && ch < 11))
        {
            printf("\nOops...!!! Something Went Wrong Please Try Again Later.");
            goto _label_loop1;
        }
        else if (ch > 0 && ch < 11)
        {
            doOperation(player, &ch);
        }
    } while (ch > 0 && ch < 11);
    free(player);
}