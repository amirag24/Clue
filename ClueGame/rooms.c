#include <stdio.h>
#include <stdlib.h>
#include "rooms.h"
#include <stdbool.h>
#include <time.h>
#include <string.h>

//#include <conio.h>

struct Room *playerPosition;
Room *rooms[9];
int anwserNum;

void mapCreation()
{ // This function makes the map

    for (int x = 0; x < 9; x++)
    {
        rooms[x] = calloc(1, sizeof(Room)); // Memory allocation for the 9 rooms.
    }

    char *roomList[9] = {"Dining Room", "Living Room", "Garden", "Upstairs", "A Room", "Front Gates", "Lobby", "Basement", "Kitchen"}; // Names of the rooms.

    // starting point is the front gates that will always be at block 7 on the map. The rest is randomize.
    rooms[7]->name = "Front Gates";
    rooms[7]->character[0] = "guard 1";
    rooms[7]->character[1] = "guard 2";

    playerPosition = rooms[7];
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Random assignment of rooms on the map.

    srand(time(0));
    int randNum = 0;
    anwserNum = rand() % 9;

    int usedNums[9] = {5, 9, 9, 9, 9, 9, 9, 9, 9}; // since room list with index 5 is the front gates and already used, it will automatically be on the list.

    // This is the loop that randomizes the rooms
    for (int i = 1; i < 9; i++)
    {

        randNum = rand() % 9;
        bool val = check(usedNums, randNum);
        while (val)
        {
            randNum = rand() % 9;
            val = check(usedNums, randNum);
        }

        // Then assign the name to the room.
        usedNums[i] = randNum;
        if (i >= 8)
        {
            rooms[i]->name = roomList[randNum];
        }
        else
        {
            rooms[i - 1]->name = roomList[randNum];
        }

        if (i != 7)
        {
            if (i >= 8)
            {
                if (randNum == 0)
                {
                    printf("%i\n\n", i);
                    printf("%i\n\n", randNum);
                    rooms[i]->character[0] = "alexander";
                }
                else if (randNum == 3)
                {
                    rooms[i]->character[0] = "mrs britania";
                }

                else if (randNum == 4)
                {
                    rooms[i]->character[0] = "maple";
                }

                else if (randNum == 7)
                {
                    rooms[i]->character[0] = "mr britania";
                }

                else if (randNum == 8)
                {
                    rooms[i]->character[0] = "maid 1";
                }
            }
            else
            {
                if (randNum == 0)
                {
                    printf("%i\n\n", i);
                    printf("%i\n\n", randNum);
                    rooms[i - 1]->character[0] = "alexander";
                }
                else if (randNum == 3)
                {
                    rooms[i - 1]->character[0] = "mrs britania";
                }

                else if (randNum == 4)
                {
                    rooms[i - 1]->character[0] = "maple";
                }

                else if (randNum == 7)
                {
                    rooms[i - 1]->character[0] = "mr britania";
                }

                else if (randNum == 8)
                {
                    rooms[i - 1]->character[0] = "maid 1";
                }
            }
        }
    }

    // This section links all the rooms together in the map.
    //  Room 0 is the top left of the board and each block to the right is another room.
    //  It is a 3x3 board. Last room on the board is room 7.
    (*rooms[0]).North = NULL;
    (*rooms[0]).East = rooms[1];
    (*rooms[0]).South = rooms[3];
    (*rooms[0]).West = NULL;

    (*rooms[1]).North = NULL;
    (*rooms[1]).East = rooms[2];
    (*rooms[1]).South = rooms[4];
    (*rooms[1]).West = rooms[0];

    (*rooms[2]).North = NULL;
    (*rooms[2]).East = NULL;
    (*rooms[2]).South = rooms[5];
    (*rooms[2]).West = rooms[1];

    (*rooms[3]).North = rooms[0];
    (*rooms[3]).East = rooms[4];
    (*rooms[3]).South = rooms[6];
    (*rooms[3]).West = NULL;

    (*rooms[4]).North = rooms[1];
    (*rooms[4]).East = rooms[5];
    (*rooms[4]).South = rooms[7];
    (*rooms[4]).West = rooms[3];

    (*rooms[5]).North = rooms[2];
    (*rooms[5]).East = NULL;
    (*rooms[5]).South = rooms[8];
    (*rooms[5]).West = rooms[4];

    (*rooms[6]).North = rooms[3];
    (*rooms[6]).East = rooms[7];
    (*rooms[6]).South = NULL;
    (*rooms[6]).West = NULL;

    (*rooms[7]).North = rooms[4];
    (*rooms[7]).East = rooms[8];
    (*rooms[7]).South = NULL;
    (*rooms[7]).West = rooms[6];

    (*rooms[8]).North = rooms[5];
    (*rooms[8]).East = NULL;
    (*rooms[8]).South = NULL;
    (*rooms[8]).West = rooms[7];
}

bool check(int array[], int num)
{
    // This function checks to see if the number on the map has been used.
    // If it has it will return true
    for (int x = 0; x < 9; x++)
    {

        if (array[x] == num)
        {
            return true;
        }
    }
    return false;
}

bool moveRoom(char direction[], struct Room *curRoom)
{
    // This function moves the player from the current room to a different room using the direction

    // These condition statements checks what direction the player is trying to go and checks the room to see if it's
    //  a valid action. It then moves the player to that room if it is valid else it prints "You can not go there."
    

    if (strcmp(direction, "north") == 0)
    {
        
        if (curRoom->North != NULL)
        {
            if(strcmp(curRoom->North->name, "Basement") == 0){
                printf("You walk towards the basement.\n");
                playerPosition = playerPosition->North;
            return true;
        }
            playerPosition = playerPosition->North;
            printf("You walk into the next area north.\n");
            printf("This seems to be the %s\n", playerPosition->name);
            printf("The other person in the room is %s \n", playerPosition->character[0]);
            return true;
        }
        else
        {
            printf("You can not go there.");
        }
    }
    else if (strcmp(direction, "south") == 0)
    {
        if (curRoom->South != NULL)
        {if(strcmp(curRoom->South->name, "Basement")==0){
             printf("You walk towards the basement.\n");

            playerPosition = playerPosition->South;
            return true;
        }
            playerPosition = playerPosition->South;
            printf("You walk into the next area south.\n");
            printf("This seems to be the %s\n", playerPosition->name);
            printf("The other person in the room is %s\n ", playerPosition->character[0]);
            return true;
        }
        else
        {
            printf("You can not go there.");
        }
    }
    else if (strcmp(direction, "east") == 0)
    {
        printf("stage 2\n");
        printf("%s\n", direction);
        if (curRoom->East != NULL)
        {
            if(strcmp(curRoom->East->name, "Basement")==0){
                printf("You walk towards the basement.\n");

                playerPosition = playerPosition->East;
            return true;
        }
            playerPosition = playerPosition->East;
            printf("You walk into the next area east.\n");
            printf("This seems to be the %s\n", playerPosition->name);
            printf("The other person in the room is %s\n ", playerPosition->character[0]);
            return true;
        }
        else
        {
            printf("You can not go there.");
        }
    }
    else if (strcmp(direction, "west") == 0)
    {
        if (curRoom->West != NULL)
        {
            if(strcmp(curRoom->West->name, "Basement")==0){
                printf("You walk towards the basement.\n");

                playerPosition = playerPosition->West;
            return true;
        }
            playerPosition = playerPosition->West;
            printf("You walk into the next area west.\n");
            printf("This seems to be the %s\n", playerPosition->name);
            printf("The other person in the room is %s \n", playerPosition->character[0]);
            return true;
        }
        else
        {
            printf("You can not go there.");
        }
    }
    return false;
}

void printLocation()
{
    Room *temp = playerPosition->North;
    if (temp != NULL)
    {
        printf("To the north there seems to be the %s \n", (playerPosition)->North->name);
    }
    else
    {
        printf("To the north there seems to be a wall\n");
    }

    temp = playerPosition->East;

    if (temp != NULL)
    {
        printf("To the east there seems to be the %s \n", (playerPosition)->East->name);
    }
    else
    {
        printf("To the east there seems to be a wall\n");
    }
    temp = playerPosition->South;
    if (temp != NULL)
    {
        printf("To the south there seems to be the %s \n", (playerPosition)->South->name);
    }
    else
    {
        printf("To the south there seems to be a wall\n");
    }

    temp = playerPosition->West;
    if (temp != NULL)
    {
        printf("To the west there seems to be the %s \n", (playerPosition)->West->name);
    }
    else
    {
        printf("To the west there seems to be a wall\n");
    }
}

bool anwserRoom()
{

    if (strcmp(playerPosition->name, rooms[anwserNum]->name) == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *getAnwserRoomChar()
{
    return rooms[anwserNum]->character[0];
}

void removeItemfromRoom(char curItem[])
{
    Items *curNode = playerPosition->item;
    Items *prevNode = NULL;

    while (curNode!= NULL)
    {
        if (strcmp(curItem, curNode->name) == 0)
        {
            if(prevNode == NULL){
                playerPosition->item = NULL;
                return;
            }
            prevNode ->inventory = curNode->inventory;
            playerPosition->item = NULL;
            return;
        }
        prevNode = curNode;
        curNode = curNode->inventory;
    }
    if (strcmp(curItem, playerPosition->item->name) != 0)
    {
        printf("The item is not in the room.\n");
    }

}

void addItemtoRoom(char curItem[])
{

    Items *curNode = playerPosition->item;

    while (curNode->inventory != NULL)
    {
        curNode = curNode->inventory;
    }

    curNode->inventory->name = curItem;
    printf("1.3");

}

