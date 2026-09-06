/* COP 3502C PA1 
This program is written by: Nicholas Anthony Hernandez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct monster  
{ 
char *name; 
char *element; 
int population; 
} monster; 

typedef struct region  
{ 
char *name; 
int monster_cnt; 
int total_population; 
monster **monsters; 
} region; 

typedef struct itinerary  
{ 
int region_cnt; 
region **regions; 
int captures; 
} itinerary;

typedef struct trainer  
{ 
char *name; 
itinerary *visits;
} trainer;  

monster* makeMonster(char *name, char *element, int population);
monster** readMonsters(int *monsterCount);
region** readRegions(int *countRegions, monster** monsterList, int monsterCount);
trainer* loadTrainers(int *trainerCount, region** regionList, int countRegions);
void processInputs(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount);
void releaseMemory(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount);

int main(void)
{

}

monster* makeMonster(char *name, char *element, int population)
{
    monster* mon = malloc(sizeof(monster));
    mon->name = *name;
    mon->element = *element;
    mon->population = population;
}

monster** readMonsters(int *monsterCount)
{
    monster** monsterList = malloc(*monsterCount * sizeof(monster*));
    char name[50];
    char element[50];
    int population;

    for(int i = 0; i < *monsterCount; i++)
    {
        scanf("%49s", name);
        int len = strlen(name) + 1;
        char *nameP = malloc(len * sizeof(char));
        strcpy(*nameP, name); 
        
        scanf("%49s", element);
        len = strlen(element) + 1;
        char *elementP = malloc(len * sizeof(char));
        strcpy(*elementP, element); 

        scanf("%d", &population);

        if(population > 1000000)
        {
            population = 1000000;
        }
        monsterList[i] = makeMonster(*nameP, *elementP, population);

    }
    return monsterList;
}

region** readRegions(int *countRegions, monster** monsterList, int monsterCount)
{
    
}

trainer* loadTrainers(int *trainerCount, region** regionList, int countRegions)
{

}

void processInputs(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{

}

void releaseMemory(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{

}