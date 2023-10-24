#include <stdio.h>
#include "items.h"
#include "rooms.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern Room *rooms[9];

struct Items *inventory;

char *itemList[5];
bool compCharacters[7];
//{"guard 1"}, {"guard 2"}, {"maid 1",, {"maple"}, {"alexander"}, {"mrs britania"}, {"mr britania"}

void itemsAssignment()
{
   // This file is to inplement functions for items

   inventory = NULL;
   // inventory = NULL;

   char *itemList[] = {"Key", "Rosemary", "Watch", "Stuffed Rabbit", "Note"};

   for (int x = 0; x < 8; x++)
   {
      compCharacters[x] = malloc(sizeof(bool));
      compCharacters[x] = false;
      // printf("Stage 1");
   }

   for (int x = 0; x < 9; x++)
   { // This loop assigns the items to the rooms by looking for the names
      char *temp = rooms[x]->name;
      if (strcmp(temp, "Dining Room") == 0)
      {
         rooms[x]->item = malloc(sizeof(struct Items));
         rooms[x]->item->name = itemList[0];
         rooms[x]->item->inventory = NULL;
      }
      else if (strcmp(temp, "Living Room") == 0)
      {
      }
      else if (strcmp(temp, "Garden") == 0)
      {
         rooms[x]->item = malloc(sizeof(struct Items));
         rooms[x]->item->name = itemList[1];
         rooms[x]->item->inventory = NULL;
      }
      else if (strcmp(temp, "Upstairs") == 0)
      {
      }
      else if (strcmp(temp, "My Room") == 0)
      {
         rooms[x]->item = malloc(sizeof(struct Items));

         rooms[x]->item->name = itemList[4];
         rooms[x]->item->inventory = NULL;
      }
      else if (strcmp(temp, "Front Gates") == 0)
      {
      }
      else if (strcmp(temp, "Lobby") == 0)
      {
      }
      else if (strcmp(temp, "Basement") == 0)
      {
         rooms[x]->item = malloc(sizeof(struct Items));

         rooms[x]->item->name = itemList[2];
         rooms[x]->item->inventory = NULL;
      }
      else if (strcmp(temp, "Kitchen") == 0)
      {
         rooms[x]->item = malloc(sizeof(struct Items));
         rooms[x]->item->inventory = NULL;
         rooms[x]->item->name = itemList[3];
      }
   }
}

void add_item(char adItem[])
{
  struct Items *curItem ;
 
   //  adds item to inventory
   curItem = inventory;

   for (int i = 0; i < 5; i++)
   {
      if(curItem == NULL){
         inventory = malloc(sizeof(struct Items));
         inventory ->name = adItem;
         inventory ->inventory = NULL;
         break;
      }
      if (curItem->inventory == NULL)
      { // curItem = malloc(sizeof(struct Items));
         curItem->inventory = malloc(sizeof(struct Items));
         curItem->inventory->name =  adItem;
         curItem->inventory->inventory = NULL;
         break;
      }
      else
      {
         curItem = curItem->inventory;
      }
   }

   removeItemfromRoom(adItem);
}
void drop_item(char name[])
{
   Items *curItem = inventory;
   char *temp;
   for (int i = 0; i < 5; i++)
   {
      temp = curItem->name;
      if (strcmp(temp, name) == 0)
      {
         curItem->acquired = false;
      }
      else
      {
         curItem = curItem->inventory;
      }
   }
   addItemtoRoom(name);
}

void printInventory()
{

   Items *curItem = inventory;
   char *temp;
   if (curItem != NULL)
   {

      for (int i = 0; i < 6; ++i)
      {

         temp = curItem->name;
         printf("%i: %s    \n", i, temp);
         curItem = curItem->inventory;
         if (curItem == NULL)
         {
            break;
         }
      }
   }
   else
   {

      printf("You do not have anything on you.\n");
   }

}

bool storyProgression(char storyCharacter[])
{
   //{"guard 1"}, {"guard 2"}, {"maid 1", {"maple"}, {"alexander"}, {"mrs britania"}, {"mr britania"}

   if (strcmp(storyCharacter, "guard 1") == 0)
   {
      printf("%d", compCharacters[0]);
      return compCharacters[0];
   }
   else if (strcmp(storyCharacter, "guard 2") == 0)
   {
      return compCharacters[1];
   }
   else if (strcmp(storyCharacter, "maid 1") == 0)
   {
      return compCharacters[2];
   }
   else if (strcmp(storyCharacter, "maple") == 0)
   {
      return compCharacters[3];
   }
   else if (strcmp(storyCharacter, "alexander") == 0)
   {
      return compCharacters[4];
   }
   else if (strcmp(storyCharacter, "mrs britania") == 0)
   {
      return compCharacters[5];
   }
   else if (strcmp(storyCharacter, "mr britania") == 0)
   {
      return compCharacters[6];
   }
   return true;
}
void storyComplete(char talkedTo[])
{
   //{"guard 1"}, {"guard 2"}, {"maid 1",, {"maple"}, {"alexander"}, {"mrs britania"}, {"mr britania"}

   if (strcmp(talkedTo, "guard 1") == 0)
   {
      compCharacters[0] = true;
   }
   else if (strcmp(talkedTo, "guard 2") == 0)
   {
      compCharacters[1] = true;
   }
   else if (strcmp(talkedTo, "maid 1") == 0)
   {
      compCharacters[2] = true;
   }
   else if (strcmp(talkedTo, "maple") == 0)
   {
      compCharacters[3] = true;
   }
   else if (strcmp(talkedTo, "alexander") == 0)
   {
      compCharacters[4] = true;
   }
   else if (strcmp(talkedTo, "mrs britania") == 0)
   {
      compCharacters[5] = true;
   }
   else if (strcmp(talkedTo, "mr britania") == 0)
   {
      compCharacters[6] = true;
   }
}
bool checkInventory(char invItem[])
{
   Items *curItem = inventory;

   for (int i = 0; i < 6; ++i)
   {
      if (curItem->name == NULL)
      {
         return false;
      }
      if (strcmp(invItem, curItem->name) == 0)
      {
         return curItem->acquired;
      }
      curItem = curItem->inventory;
   }
   return false;
}
