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
    if(mon == NULL)
    {
        perror("malloc failed.");
        return 1;
    }
    mon->name = *name;
    mon->element = *element;
    mon->population = population;
}

monster** readMonsters(int *monsterCount)
{
    monster** monsterList = malloc(*monsterCount * sizeof(monster*));
    if (monsterList == NULL)
    {
        perror("malloc failed.");
        return 1;
    }
    char name[50];
    char element[50];
    int population;

    for(int i = 0; i < *monsterCount; i++)
    {
        scanf("%49s", name);
        int len = strlen(name) + 1;
        char *nameP = malloc(len * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return 1;
        }

        strcpy(*nameP, name);
         
        
        scanf("%49s", element);
        len = strlen(element) + 1;
        char *elementP = malloc(len * sizeof(char));
        if (elementP == NULL)
        {
            perror("malloc failed.");
            return 1;
        }
        
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
    scanf("%d", *countRegions);
    region** regions = malloc(*countRegions * sizeof(region));
    if(regions == NULL)
    {
        perror("malloc failed.");
        return 1;
    }
    char name[50];
    char scanMon[50];
    int k = 0;
    for(int i = 0; i < *countRegions; i++)
    {
        scanf("%49s", name);
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return 1;
        }
        regions[i]->name = *nameP;
        scanf("%d", regions[i]->monster_cnt);
        for(int j = 0; j < regions[i]->monster_cnt; j++)
        {
            scanf("%49s", scanMon);
            k = 0;
            while(monsterList[k] != NULL && !strcmp(monsterList[k]->name, scanMon))
            {
                k++;
            }
            if (strcmp(monsterList[k]->name, scanMon))
            {
                regions[i]->monsters[j] = monsterList[k];
            }else
            {
                printf("monster name could not be found.");
                regions[i]->monsters[j] = monsterList[0];
            }
        }

    }
 return regions;   
}

trainer* loadTrainers(int *trainerCount, region** regionList, int countRegions)
{
    scanf("%d", trainerCount);
    char regionName[50];

    trainer* trainers =  malloc(*trainerCount * sizeof(trainer));
    if(trainers == NULL)
    {
        perror("malloc failed.");
        return 1;
    }
    for(int i = 0; i<*trainerCount; i++)
    {
        scanf("%49s", trainers[i].name);
        scanf("%d", trainers[i].visits->region_cnt);
        for(int j = 0; j<trainers[i].visits->region_cnt; j++)
        {
            int k = 0;
            scanf("%49s", regionName);
            while(regionList[k] != NULL && !strcmp(regionName, regionList[k]->name))
            {
                k++;
            }
            if(strcmp(regionName, regionList[k]->name))
            {
                trainers[i].visits->regions[j] = regionList[k];
            }
            else
            {
                printf("region not found");
                return 1;
            }
        }
        
    }

    return trainers;
}

void processInputs(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{
    int *monsterCount = 0;
    int *regionCount = 0;
    readMonsters(monsterCount);
    readRegions(regionCount, monsterList, monsterCount)
    
}

void releaseMemory(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{

}