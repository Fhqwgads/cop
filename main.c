/* COP 3502C PA0 
This program is written by: Nicholas Anthony Hernandez */ 
#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    Monster *monsters[MAX_MONSTERS];
    int count = 0;

    scanf("%d", &count);
    readAllMonsters(monsters, &count);
    printAllMonsters(monsters, count);

    
}


void readAllMonsters(Monster monsters[], int *count)
{
    int newCount = 0;
    for(int i = 0; i < *count; i++)
    {
        
        fscanf(stdin, "%s %s %d %d %d %d", monsters[i].name, monsters[i].type, &monsters[i].level, &monsters[i].hp, &monsters[i].attack, &monsters[i].defense);
        newCount += 1;
    }
    *count = newCount;
}

void printAllMonster(Monster *monsters, int count)
{
    for(int i = 0; i < count; i++)
    {
        
    }
}

void trainMonster(Monster *monster)
{

}

int getStrongestMonster(Monster monsters[], int count)
{

}