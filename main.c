/* COP 3502C PA0 
This program is written by: Nicholas Anthony Hernandez */ 
#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    Monster monsters[MAX_MONSTERS]; //initializing monster array
    int count = 0;                  //initializing a few variables for input
    int *countptr = &count;
    int index = 0;

    scanf("%d", &count);                    //scans for input to populate the array x number of times
    readAllMonsters(monsters, countptr);    //function popluates the array
    printAllMonster(monsters, count);       //prints the contents of the array
    fscanf(stdin, "%d", &index);            //scans for index number of a monster within the array
    trainMonster(&monsters[index]);         //function trains the indicated monster
    printf("=== TRAINING ===\n");
    printf("Training Monster %d...\n", index);
    printf("Name: %s\nType: %s\nLevel: %d\nHP: %d\nAttack: %d\nDefense: %d\n\n", monsters[index].name, monsters[index].type, monsters[index].level, monsters[index].hp, monsters[index].attack, monsters[index].defense);
    int strongestIndex = findStrongest(monsters, count); //function returns an index number of strongest monster
    printf("=== STRONGEST MONSTER ===\n");
    printf("Name: %s\nType: %s\nLevel: %d\nHP: %d\nAttack: %d\nDefense: %d\n\n", monsters[strongestIndex].name, monsters[strongestIndex].type, monsters[strongestIndex].level, monsters[strongestIndex].hp, monsters[strongestIndex].attack, monsters[strongestIndex].defense);
}


void readAllMonsters(Monster monsters[], int *count)
{
    int newCount = 0;
    for(int i = 0; i < *count; i++)
    {
        fscanf(stdin, "%19s", monsters[i].name);
        fscanf(stdin, "%19s", monsters[i].type);
        fscanf(stdin, "%d", &monsters[i].level);
        fscanf(stdin, "%d", &monsters[i].hp);
        fscanf(stdin, "%d", &monsters[i].attack);
        fscanf(stdin, "%d", &monsters[i].defense);

        newCount += 1;
    }
    *count = newCount;
}

void printAllMonster(Monster *monsters, int count)
{
    printf("=== MONSTER TEAM ===\n"); 
    for(int i = 0; i < count; i++)
    {
        printf("Monster %d:\nName: %s\nType: %s\nLevel: %d\nHP: %d\nAttack: %d\nDefense: %d\n\n", 
            i, monsters[i].name, monsters[i].type, monsters[i].level, 
            monsters[i].hp, monsters[i].attack, monsters[i].defense);
    }
}

void trainMonster(Monster *monster)
{
    monster->level += 1;
    monster->hp += monster->name[0] - 'A' + 1;
    monster->attack += 5;
    monster->defense += 3;
    
}

int findStrongest(Monster monsters[], int count)
{
    int largestStat = 0;
    int returnIndex = 0;
    for(int i = 0; i < count; i++)
    {
        if (monsters[i].level + monsters[i].attack + monsters[i].defense > largestStat)
        {
            largestStat = monsters[i].level + monsters[i].attack + monsters[i].defense;
            returnIndex = i;
        }    
    }
    return returnIndex;
}