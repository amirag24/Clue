#include <stdio.h>
#ifndef ITEMS_H
#define ITEMS_H
#include <stdbool.h>

// this file is for the data structures of the items

typedef struct Items
{
    char *name;
    struct Items *inventory;
    bool acquired;
} Items;
void drop_item(char name[]);// drops item from inventory
void printInventory();// prints items in inventory
void add_item(char addItem[]);// adds item to inventory
void itemsAssignment();// assgins items to room
bool storyProgression(char storyCharacter[]);// checks if you have talked to the character already
void storyComplete(char talkedTo[]);// after you talk to a character for the first time it takes note of that
bool checkInventory(char invItem[]);// cheack to see if you have the item passed in, inside your inventory

#endif