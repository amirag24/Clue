#include <stdio.h>
#include <string.h>
#include "rooms.h"
#include <stdbool.h>
#include <stdlib.h>

struct Room *playerPosition;
extern Items *inventory;
bool terminate = false;// this ends the game
int clueNum = 0;// If the player guesses correctly 3 times they win
int tries = 10; //player has 3 guess for the command clue

void help() // This is the help command
{
    printf("In this game you must talk to characters to progress in the story. Some items need to be obtained to enter in some rooms if need be.\n");
    printf(" List of commands:\n");
    printf("take\ndrop\ngo [direction]\ntalk to [character's name]\nlook\nclue");
}

void hint (){
    char* hint= getAnwserRoomChar();
    

    if( strcmp (hint,"guard 1")==0){

    }
    else if( strcmp (hint,"guard 2")==0){

    }
    else if( strcmp (hint,"maple")==0){

    }
    else if( strcmp (hint,"alexander")==0){

    }
    else if( strcmp (hint,"mr britania")==0){

    }
    else if( strcmp (hint,"mrs britania")==0){

    }
}



void dialogue(char character[])
{
    // dialouge for the character if the room is correct

    if (strcmp(character, "guard 1") == 0) // if the player wants to speak to guard 1
    {
        if (strcmp(playerPosition->character[0], character) == 0)
        { // if you are in the same room as guard 1
            if (storyProgression("guard 1") == false)
            { // The dialogue if the player has not spoken to guard 1 yet

                printf("You look in the direction of guard 1.\n");
                printf("guard 1's board physique towers over you, he does not wear a expression nor does he seem alive.\n");
                printf("If he did not move to open the gates, you would have mistaken him for a statue.\n");
                printf("You approach guard 1 with the intentions to ask a few questions...\n");
                printf("You: Hello, I am the detective hired to find the missing family heirloom. Might you know any information?\n");
                printf("\n...\n");
                printf("guard 1 does not react or say anything. It is as if you are not there...\n");
                printf("((This is going no where, what should I do next?))\n");
                storyComplete("guard 1");
            }
            else // else this is the dialogue if they have spoken before
            {
                if (checkInventory("Watch"))
                { // if you have the item required you progress
                    printf("The guard suddenly starts to react to you.\n");
                    printf("\n guard 1: That is the watch my brother has lost a few days ago. \n");
                    printf("You hand over the watch and the guard takes it.Then he walks to the second Guard and hands it over.\n");
                    printf("The second guard stops muttering finally and becomes estatic at the sight of the watch.\n");

                    if (anwserRoom())
                    { // If this the random anwser room then you win
                        printf("\nGuard 2: Here I found this shiny object during one of our routine walks around the mansion.\n");
                        printf("The guard hands over the emblem.\n");
                        printf("guard 2: I found it in the garden and thought it was my missing watch.\n");
                        printf("((Good greif...))\n");
                        terminate = true;
                    }
                    else
                    { // if this is not the anwser room then if gives you a clue on who so speak to next
                        printf("\nGuard 2: If you are the detective here for the emblem I suggest you speak to the made or mr britania.\n");
                        printf("The guard hands over the a key.\n");
                        printf("guard 2: I found it in the garden and thought it was my missing watch but it was the key to Mr. Britania's lab in the basement.\n");
                        printf("((Is this allowed?...))\n");
                        add_item("Key");
                    }
                    drop_item("Watch"); // drops the item after you give it to the character
                }
                else // if you have spoken before but you do not have the required item
                {
                    printf("((The guard next to him keeps saying Tik Tok... does this have something to do with time?))");
                }
            }
        }

        else
        {
            printf("((If I want to speak to the guards I should go to the front gates.))");
        }
    }

    if (strcmp(character, "guard 2") == 0)
    { // if you want to speak to guard 2
        if (strcmp(playerPosition->character[1], character) == 0)
        { // if you are in the correct room
            if (storyProgression("guard 2") == false)
            { // if you have not talked to him
                printf("You look in the direction of guard 2.\n");
                printf("guard 2's board physique towers over you, unlike guard 1 he looks preoccupied with his thoughts.\n");
                printf("guard 2 keeps mouthing quietly to himself, maybe he knows something?\n");
                printf("You approach guard 2 with the intentions to ask a few questions...\n");
                printf("\nYou: Hello, I am the detective hired to find the missing family heirloom. Might you know any information?\n");
                printf("\nGuard 2 does not react.\n");
                printf("\nNow that you stand a little closer you are able to just make out what he is muttering..\n");
                printf("guard 2:...Tik Tok... the mouse ran up the clock... Tik Tok...\n");
                printf("You: Hello?\n");
                printf("guard 2: Tik Tok... Tik Tok...\n");
                printf("\n...\n");
                printf("((This is going no where, what should I do next?))");
                storyComplete("guard 2");
            }
            else
            {
                if (checkInventory("Watch"))
                { // if you have the item required you progress
                    printf("The guard suddenly starts to react to you.\n");
                    printf("\n guard 1: That is the watch my brother has lost a few days ago. \n");
                    printf("You hand over the watch and the guard takes it.Then he walks to the second Guard and hands it over.\n");
                    printf("The second guard stops muttering finally and becomes estatic at the sight of the watch.\n");

                    if (anwserRoom())
                    { // if you are in the anwserRoom
                        printf("\nGuard 2: Here I found this shiny object during one of our routine walks around the mansion.\n");
                        printf("The guard hands over the emblem.\n");
                        printf("guard 2: I found it in the garden and thought it was my missing watch.\n");
                        printf("((Good greif...))\n");
                        terminate = true;
                    }
                    else
                    {
                        printf("\nGuard 2: If you are the detective here for the emblem I suggest you speak to the made or mr britania.\n");
                        printf("The guard hands over the a key.\n");
                        printf("guard 2: I found it in the garden and thought it was my missing watch but it was the key to Mr. Britania's lab in the basement.\n");
                        printf("((Is this allowed?...))\n");
                        add_item("Key");
                    }
                    drop_item("Watch");
                }
                else
                {
                    printf("((The guard keeps saying Tik Tok... does this have something to do with time?))");
                }
            }
        }
        else
        {
            printf("((If I want to speak to the guards I should go to the front gates.))");
        }
    }

    if (strcmp(character, "maid 1") == 0)
    {
        if (strcmp(playerPosition->character[0], character) == 0)
        {
            if (storyProgression("maid 1") == false)
            { // if you have not talked to the maid yet
                printf("You approach the Maid who seems to not react until you are right behind her.");
                printf("The maid turns slowly almost as if she is attached to those platforms ballerinas from music boxes spin on.\n");
                printf("\nMaid 1: ...\n");
                printf("You: Hello, I am the defective hired to find the missing heriloom.\n");
                printf("maid 1: ...\n");
                printf("\nYou: ...Might you know any information?\n");
                printf("\nMaid 1: My apologees but I must focus on tonights dinner, if it is not ready by exactly 5pm...\n");
                printf("\nYou: I'm sorry to hear that but I am here for the emblem.\n");
                printf("Maid:... The missing emblem... I don't have time to think about that. I need to find the Rosemary.\n");
                printf("You:... If fetch the Rosemary will you take the time to think about any information?\n");
                printf("maid 1:... deal... it must be the best Rosemary you can pick from the Garden. Please hurry\n");
                printf("\n...\n");
                printf("((I should go to the gardens...))\n");
                storyComplete("maid 1");
            }
            else if (checkInventory("Rosemary") == true)
            { // if you already talked to the maid then if checks if you have the Rosemary.
                if (anwserRoom())
                { // if the anwser room is this room then the you get the item and completed the game.
                    printf("You hand the Rosemary to the maid and she inspects it.\n");
                    printf("maid 1: This herb will do. As for the emblem, I gave it some thought and remembered the kids playing in the room of the emblem.\n");
                    printf("While you were gone it seems as though the emblem was misplaced in one of the cupboards and I found it...\n");
                    printf("You: ...well thank you");
                    terminate = true;
                    
                   
                }
                else
                { // if the anwser room is not this room then keep looking.
                    printf("You hand the Rosemary to the maid and she inspects it.\n");
                    printf("maid 1: This herb will do. As for the emblem, I gave it some thought and remembered the kids playing in the room of the emblem.\n");
                    printf("I also remember mr britania having a serious conversation on the phone when they were not in the room.\n");
                    printf("You: Thank you.\n");
                    printf("The maid nods and quickly goes back to cooking.\n");
                    drop_item("Rosemary");
                }
            }
        }
        else
        {
            printf("((If I want to speak to the maid I believe she is in the kitchen.))");
        }
    }

    if (strcmp(character, "mr britania") == 0)
    {
        if (strcmp(playerPosition->character[0], character) == 0)
        {
            if (storyProgression("mr britania") == false)
            { // if you have not talked to the maid yet
                printf("You apprach a locked door of the basement. You do not hear anything from beyond the door.\n");
                printf("You try turning the handle but it does not budge so you look under to see a green light. \n");
                printf("\n ((I should get a key and or permission))\n");

                storyComplete("mr britania");
            }
            else if (checkInventory("Key") == true)
            { // if you already talked to the maid then if checks if you have the Rosemary.
                if (anwserRoom() == false)
                { // if the anwser room is not this room then keep looking.
                    printf("You apprach a locked door of the basement. You hear a little shuffling this time.\n");
                    printf("You insert the key and open the door slowly.\n");
                    printf("Inside is mr britania he is observing a mouse running in circle and into the walls of its confined box\n");
                    printf("mr britania: who gave you permission to be in here?\n");
                    printf("You: ... I am -\n");
                    printf("mr britania: I know who you are, the emblem is not here leave.\n");
                    printf("You close the door of the basement.\n");
                    printf("((I should not go back.\n))");
                    drop_item("Key");
                }
                else
                { // if the anwser room is this room then the you get the item and completed the game.
                    printf("You apprach a locked door of the basement. You hear a little shuffling this time.\n");
                    printf("You insert the key and open the door slowly.\n");
                    printf("Inside is mr britania he is observing a mouse running in circle and into the walls of its confined box\n");
                    printf("mr britania: who gave you permission to be in here?\n");
                    printf("You: ... I am -\n");
                    printf("mr britania: I know who you are, I have the emblem with me.\n");
                    printf("I told Emily but she does not have her mind intact. She probably forgot and hired you.\n");
                    printf("You:... oh \n");
                    printf("mr Britania: do not worry we will pay you for your time.\n");
                    printf("You: ...well thank you");
                    printf("You close the door of the basement.\n");
                    printf("((I should not go back.\n))");
                    terminate = true;
                }
            }
        }
        else
        {
            printf("((If I want to speak to the mr britania I believe he is in the basement.))");
        }
    }

    if (strcmp(character, "maple") == 0)
    {
        if (strcmp(playerPosition->character[0], character) == 0)
        {
            if (storyProgression("maple") == false)
            { // if you have not talked to the maid yet
                printf("You see what seems to be a 9 year old girl crawl out from under the bed.\n");
                printf("You were confused by this and watch her for a moment more as she flips the sheets of the bed over. She then looks around until her eyes land on you.\n");
                printf("\nMaple: ... Have you seen my dog?\n");
                printf("You: Your dog?\n");
                printf("maple: ... Yes it is small white and has big long ears\n");
                printf("\nYou: No but I am looking for a shiny emblem.\n");
                printf("\nMaple: I dont care about mom and dad's things! \n");
                printf("\nYou: That is not nice\n");
                printf("maple: They never listen to me anyway they keep saying my dog is not alive and it is actually a rabbit. \n");
                printf("I do not care it is a dog to me and I need her!\n");
                printf("You:((If I want her to calm down and get some awnsers I better find the rabbit.))\n");

                storyComplete("maple");
            }
            else if (checkInventory("Rabbit") == true)
            {
                if (anwserRoom() == false)
                { // if the anwser room is not this room then keep looking.
                    printf("My dog!\n");
                    printf("maple runs over to the you and grabs her stuffed rabbit from your hands.\n");
                    printf("You: Now that is out of the way have you see your family emblem?\n");
                    printf("maple: ... That stupid thing? I believe I saw it with %s.\n", getAnwserRoomChar());
                    printf("If not then I have no clue.");

                    printf("((Interesting...))\n");
                    drop_item("Stuffed Rabbit");
                }
                else
                { // if the anwser room is this room then the you get the item and completed the game.
                    printf("My dog!\n");
                    printf("maple runs over to the you and grabs her stuffed rabbit from your hands.\n");
                    printf("You: Now that is out of the way have you see your family emblem?\n");
                    printf("maple: ... That stupid thing?\n");
                    printf("maple looks away a little embarrased before opening the back of her stuffed animal. She then pulls the emblem out and hands it to you.");
                    printf("You stand there confused.\n");
                    printf("maple: I thought by hiding the emblem maybe I could get mom and dad's attention but they only hired you to figure it out.\n");
                    printf("You: Why give it to me then?\n");
                    printf("maple: You stopped searching for the emblem and helped me out... it is more than why they have done in a long time\n");
                    printf("...thank you.\n");
                    printf("As much as you want to scold the child you can not help but feel bad. At least the mystery is solved...");
                    terminate = true;
                }
            }
        }
        else
        {
            printf("((If I want to speak to the maple I believe she is somewhere upstairs.\n))");
        }
    }

    if (strcmp(character, "alexander") == 0)
    {
        if (strcmp(playerPosition->character[0], character) == false)
        {
            if (storyProgression("alexander"))
            { // if you have not talked to the alex yet
                printf("You see a a child that does not seem too far from 15 sitting at the dining room table. \n");
                printf("He looks to be focused with something in his lap until he suddenly winces in pain and looks up at you.\n");
                printf("\n alexander: Who might you be?\n");
                printf("You: I am the detective hired to find you missing family emblem, do you have any information?\n");
                storyComplete("alexander");
            }

            if (anwserRoom() )
            {
                  // if the anwser room is this room then the you get the item and completed the game.
                printf("alexander: ... Yes its up there.\n");
                printf("\nYou look to where alexander is pointing and there the emblem is in the flower case in the middle of the table.\n");
                printf("\n alexander: I told mom but she never listens to me anyways. \n");
                printf("\nYou: well.. mystery solved I guess.\n");
                printf("You take the emblem from to middle of the table and see the object in Alex's hands. \n");

                printf("You: ..What are you up to\n");
                printf("alexander: If you must know I am making my little sister a stuffer dog. S\n");
                printf("You: Thats sweet.\n");
                printf("alexander: She is too stupid for calling a rabbit a dog but at least this might make her shut her mouth about it.\n");
                printf("alexander says quietly but loud enough for you to barely hear\n");
                printf("alexander:.. she has been sad about losing it... hopefully this will make her happy.\n");

                printf("You watch him stuggle to sew as alexander moves the dog up closer so he can see better. His hands has bandages all over.\n");
                printf("((Though he acts tough he cares dearly about his sister... Does not know how to sew yet tries.))\n");

                terminate = true;
            }
            else
            {
                // if the anwser room is not this room then keep looking.
                printf("alexander: ... I am sorry but not I do not have any information about it\n");
                printf("\nYou look alexander up and down and he goes back to looking at his lap\n");
                printf("\n You: The dining room is for eating. \n");
                printf("\n alexander: You sound like my mother the times she actually spares a few words for me.\n");
                printf("You: ..What are you up to\n");
                printf("alexander: If you must know I am making my little sister a stuffer dog. S\n");
                printf("You: thats sweet.\n");
                printf("alexander: She is too stupid for calling a rabbit a dog but at least this might make her shut her mouth about it.\n");
                printf("alexander says quietly but loud enough for you to barely hear\n");
                printf("alexander:.. she has been sad about losing it... hopefully this will make her happy.\n");

                printf("You watch him stuggle to sew as alexander moves the dog up closer so he can see better. His hands has bandages all over.\n");
                printf("((Though he acts tough he cares dearly about his sister... Does not know how to sew yet tries.))\n");

              
            }
        }
        else
        {
            printf("((If I want to speak to the alexander I believe he is in the dining room\n))");
        }
    }

    if (strcmp(character, "mrs britania") == 0)
    {
        if (strcmp(playerPosition->character[0], character) == 0)
        {
            if (storyProgression("mrs britania") == false)
            { // if you have not talked to the alex yet
                printf("You appreach mrs britania and she looks at you with a smile and puts her hand out. \n");
                printf("You take her hand and kiss it before standing back upright.\n");
                printf("\n You: Good evening mrs britania\n");
                printf("mrs britania: good evening, who may you be?\n");
                printf("\n You: ... we have met before you hired me\n");
                printf("mrs britania: oh! I apologize... I can not seem to remember things... in fact I wrote a note on important things to remember.. \n");
                printf("\n She looks around.\n");
                printf("mrs britania: seems I have misplaced it yet again...\n");
                printf("\n ((Maybe that note has information I need...))\n");
                storyComplete("mrs britania");
            }
            else if (checkInventory("Note") == true)
            {
                if (anwserRoom() == false)
                { // if the anwser room is not this room then keep looking.
                    printf("mrs britania seems to be aimlessly wondering about but this time she seems deep into thought\n");
                    printf("\nYou approach her.\n");
                    printf("\n You: Here is your note mrs britania I hope this helps calm your nerves a little bit.\n");
                    printf("\n She looks at you\n");
                    printf("mrs britania: Have you escorted her out?\n");
                    printf("You: exscue me?\n");
                    printf("mrs britania: that women with my husband, did you get rid of her like I said? \n");
                    printf("You: (( Is she confused?))\n");
                    printf("mrs britania: I need to get back to the party.. the guest are waiting, just get rid of her. the public can not know.\n");
                    printf("((I am getting no where with her... the only thing this note says is spend time with Maple and Alexander from a date labeled since last year))\n");
                    drop_item("Note");
                }
                else
                {
                    // if the anwser room is this room then the you get the item and completed the game.
                    printf("mrs britania seems to be aimlessly wondering about but this time she seems deep into thought\n");
                    printf("\nYou approach her.\n");
                    printf("\n You: Here is your note mrs britania I hope this helps calm your nerves a little bit.\n");
                    printf("\n She looks at you\n");
                    printf("mrs britania: Have you escorted her out?\n");
                    printf("You: exscue me?\n");
                    printf("mrs britania: that women with my husband, did you get rid of her like I said? \n");
                    printf("You: (( Is she confused?))\n");
                    printf("mrs britania: I need to get back to the party.. the guest are waiting, just get rid of her. the public can not know.\n");

                    printf("You hand over the note and she looks at it before taking it. She pauses then looks at you\n");
                    printf("mrs britania:... you should go ..\n");
                    printf("You: what about the job\n");
                    printf("mr britania: it will turn up... I will still pay you in full... I should go rest now");
                    printf("With that she walks away and you go your seperate path. You thoughts wonder about her words and you start to put the pieces together. This family and there legacy will vanish soon just like their emblem.\n");

                    terminate = true;
                }
            }
        }
        else
        {
            printf("((If I want to speak to the mrs britania I believe she is upstairs\n))");
        }
    }
}

void nxtMove(char action[], struct Room *position)
{
    // check if in the correct room first
    bool validMove = true;
    playerPosition = position;

    if (strcmp(action, "talk to guard 1") == 10)
    {
        dialogue("guard 1"); //"dialogue" is a function that checks the player position to see if they are in the same room then prints dialouge of char
    }
    else if (strcmp(action, "talk to guard 2") == 10)
    {
        dialogue("guard 2");
    }
    else if (strcmp(action, "talk to maid 1") == 10)
    {
        dialogue("maid 1");
    }
    else if (strcmp(action, "talk to maple") == 10)
    {
        dialogue("maple");
    }
    else if (strcmp(action, "talk to alexander") == 10)
    {
        dialogue("alexander");
    }
    else if (strcmp(action, "talk to mrs britania") == 10)
    {
        dialogue("mrs britania");
    }
    else if (strcmp(action, "talk to mr britania") == 10)
    {
        dialogue("mr britania");
    }
    else if (strcmp(action, "go north") == 10)
    {
        validMove = moveRoom("north", playerPosition);

        if (!validMove)
        {
            printf("\nThis is not a valid action.\n");
        }
    }
    else if (strcmp(action, "go south") == 10)
    {
        validMove = moveRoom("south", playerPosition);

        if (!validMove)
        {
            printf("\nThis is not a valid action.\n");
        }
    }
    else if (strcmp(action, "go east") == 10)
    {
        validMove = moveRoom("east", playerPosition);

        if (!validMove)
        {
            printf("\nThis is not a valid action.\n");
        }
    }
    else if (strcmp(action, "go west") == 10)
    {
        validMove = moveRoom("west", playerPosition);

        if (!validMove)
        {
            printf("\nThis is not a valid action.\n");
            // updatePosition(playerPosition);
        }
    }
    else if (strcmp(action, "drop") == 10)
    {
        char item[25];
        printf("What do you want to drop?\n");
        printInventory();
        fgets(item, 25, stdin);
        drop_item(item);
    }
    else if (strcmp(action, "take") == 10)
    {
        Room *tempPlay = playerPosition;
        char *playerAnwser = (char *)malloc(64);

        if (tempPlay->item != NULL)
        {
            if (tempPlay->item->name != NULL)
            {
                printf("Do you want to pick up the %s ?\n", tempPlay->item->name);
                printf("yes or no?\n");
                
                //free(action);
                scanf("%s", playerAnwser);
                if (strcmp(playerAnwser, "yes") == 0)
                {
                    
                    add_item(tempPlay->item->name);
                    free(playerAnwser);
                }
                else if (strcmp(playerAnwser, "Yes") == 0)
                {
                    // Room * tempPlay = playerPosition;
                    add_item(tempPlay->item->name);
                }
            }
        }
    }
    else if (strcmp(action, "help") == 10)
    {
        help();
    }
    else if (strcmp(action, "list") == 10)
    {
        Items *curItem = playerPosition->item;
        Room *n1 = playerPosition;

        printf("List of characters: guard 1, guard 2, maid 1, maple, alexander, mr britania, mrs britania.\n");

        if (n1->character[0] == NULL)
        {
            printf("Current characters is the room: none");
        }
        else if (n1->character[1] == NULL)
        {
            printf("Current character is the room:%s\n", n1->character[0]);
        }
        else
        {
            printf("Current characters is the room: %s %s\n", n1->character[0], n1->character[1]);
        }

        printf("\nList of items: key, rosemary, watch, stuffed rabbit, note\n");
        printf("Items currently in the room you are in:");
        if (curItem == NULL)
        {
            printf("none\n");
        }
        while (curItem != NULL)
        {
            printf(" %s  \n", curItem->name);

            curItem = curItem->inventory;
        }
        printLocation();
        // status();
    }
    else if (strcmp(action, "inventory") == 10)
    {
        printInventory();
    }
    else if (strcmp(action, "action") == 10)
    {
        printf("The inputs are: \n go [direction] - Used to move rooms \n take - used to pick up items\n drop - used to drop items \n talk to [character] - to talk to someone in your current room\n list - to get list of characters and items and also current location\n inventory - what you have on you\n");
    }
    else if (strcmp(action, "clue") == 10)
    {
        printf("Who has the emblem? You have 3 guesses.\n ");

         tries = tries-1;
        int three =3;
        char clue[50];
        while((clueNum<3 )& (tries>0)){
        fgets(clue, 50, stdin);
        if (strcmp(clue, getAnwserRoomChar()) == 10)
        {
            clueNum= clueNum+1;
           // terminate = true;
        }
        else if (anwserRoom())
        {
            clueNum = clueNum+1;
           // terminate = true;
        }
        else if(strcmp(clue, "quit") == 10){
            return;
        }
        else {
            printf("incorrect\n");
            three= three-1;
        }

        clueNum = clueNum + 1;
        }
        if (clueNum >= 3){
            printf("You won!\n");
            terminate = true;
            return;
        }
        else if (tries <=0){
            printf("You are a loser !\n");
            terminate = true;
        }
    }
    else if (strcmp(action, "look") == 10)
    {
        printLocation();
    }
    else if(strcmp(action, "quit") == 10)
    {
        terminate = true;
    }
    else if(strcmp(action,"\n")==0){
        return;
    }
    else
    {
        printf("Input is invalid or unrecognizable. If help is needed on valid inputs type action.\n");
    }
}

int main()
{
    // The main function gets and interprets the user input

    mapCreation();

    itemsAssignment();

    printf("You are a perstige detective standing before the front gates of the well-known Britania mansion.\n");
    printf("This mansion is home to none other than the Britania family who has hired you to find their missing family heirloom, an emblem of gold and emerald green, the proud colors of the Britania family.\n");
    printf("All you were told is that one night while they had family dinner they noticed that the emblem was gone from the shelf above the fireplace.\n");
    printf("At the gates, there stands two guards. One of the guards does not say a word while the other seems to be mouthing to himself. They, in unison, open the gates to let you in.\n");
    printf("\nAs you walk through you make a note of your surroundings:\n");
    printLocation();

    printf("\n guard 1 & guard 2 stares down the road leading into the forest that surrounds the mansion.\n");

    char action[50]; // Player's input actions should not exceed 50 characters.
    
    while (terminate == false)
    { // while player does not have the anwser/has not lost then the game will continue taking input and interpretting the actions
        fgets(action, 50, stdin);        // This is the user input
        nxtMove(action, playerPosition); // This function takes in the player input and interps it.
    }
    printf("\nGame over!\n"); // This is the endgame
    free(inventory);
    free(playerPosition);
}

// free when after the the game terminates
