#ifndef ROOMS_H
#define ROOMS_H
#include <stdio.h>
#include <stdbool.h>
#include "items.h"
#include <stdbool.h>

typedef struct Room
{
      char *name;
      struct Room *North;
      struct Room *South;
      struct Room *East;
      struct Room *West;
      struct Items *item;
      char *character[2];
      bool *talkedTo[2];
} Room;
bool moveRoom(char direction[], struct Room *curRoom);//moves the player to another room
void mapCreation();// make the map
bool check(int array[], int num); /* The function "check" is used to see if the number of the place on the map has been used.
                                     If it has then the function will keep getting another random number*/
void printLocation();// Prints the surrounding location
bool anwserRoom();// contains the room with the anwser in it
void removeItemfromRoom(char curItem[]);// removes the item from the room
void addItemtoRoom(char curItem[]);// adds the item to the room
char *getAnwserRoomChar();//gets the name fo the room with the anwser
// extern Room * playerPosition;
#endif