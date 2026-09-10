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
    int monsterCount = 0;
    int regionCount = 0;
    int trainerCount = 0;
    monster** monsterList = readMonsters(&monsterCount);
    region** regionList = readRegions(&regionCount, monsterList, monsterCount);
    //trainer* trainers = loadTrainers(&trainerCount, regionList, regionCount);

    
}


monster* makeMonster(char *name, char *element, int population)
{
    monster* mon = malloc(sizeof(monster));
    if(mon == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    mon->name = name;
    mon->element = element;
    mon->population = population;
    return mon;
}

monster** readMonsters(int *monsterCount)
{
    scanf("%d", monsterCount);   
    monster** monsterList = malloc(*monsterCount * sizeof(monster*));
    if (monsterList == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    char name[50];
    char element[50];
    int population = 0;

    for(int i = 0; i < *monsterCount; i++)
    {
        scanf("%49s", name);
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }

        strcpy(nameP, name);
        
        scanf("%49s", element);
        char *elementP = malloc((strlen(element) + 1) * sizeof(char));
        if (elementP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }
        
        strcpy(elementP, element);

        scanf("%d", &population);

        if(population > 1000000)
        {
            population = 1000000;
        }
        
        monsterList[i] = makeMonster(nameP, elementP, population);
        
    }
    return monsterList;
}

region** readRegions(int *countRegions, monster** monsterList, int monsterCount)
{
    scanf("%d", countRegions);
    region** regions = malloc(*countRegions * sizeof(region*));
    if(regions == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    char name[50];
    char scanMon[50];
    int k;
    for(int i = 0; i < *countRegions; i++)
    {
        regions[i] = malloc(sizeof(region));
        scanf("%49s", name);
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }
        regions[i]->name = nameP;

        scanf("%d", &regions[i]->monster_cnt);
        for(int j = 0; j < regions[i]->monster_cnt; j++)
        {
            regions[i]->monsters = malloc(regions[i]->monster_cnt*sizeof(monster*));
            if (regions[i]->monsters == NULL)
            {
                perror("malloc failed.");
                return NULL;
                free(regions[i]->monsters);
            }
            scanf("%49s", scanMon);
            for (int k = 0; k < monsterCount; k++)
            {

                if (strcmp(monsterList[k]->name, scanMon))
                {
                    regions[i]->monsters[j] = monsterList[k];
                    regions[i]->total_population += regions[i]->monsters[j]->population;
                }
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
        return NULL;
    }
    for(int i = 0; i<*trainerCount; i++)
    {
        scanf("%49s", trainers[i].name);
        scanf("%d", &trainers[i].visits->captures);
        scanf("%d", &trainers[i].visits->region_cnt);
        for(int j = 0; j<trainers[i].visits->region_cnt; j++)
        {
            int k = 0;
            scanf("%49s", regionName);
            while(regionList[k] != NULL && regionName != regionList[k]->name)
            {
                k++;
            }
            if(regionName == regionList[k]->name)
            {
                trainers[i].visits->regions[j] = regionList[k];
            }
            else
            {
                printf("region not found");
                return NULL;
            }
        }
        
    }

    return trainers;
}

void processInputs(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{
    printf("%49s", trainerList[0].name);
}

/*void processCaptures(trainer* trainers, int trainerCount, region** regionList, int regionCount)
{
    for (int i = 0; i < trainerCount; i++)
    {
        for (int j = 0; j < trainers[i].visits->region_cnt; j++)
        {
            for (int k = 0; k < trainers[i].visits->captures; k++)
            {
                trainers[i].visits->regions[j]->total_population
            }
        }
    }
}*/

int freeMonsterList(monster** monsterList, int monsterCount)
{
    for (int i = 0; i<monsterCount; i++)
    {
        monsterList[i];
    }
}

int freeRegions(region** regionList, int regionCount)
{
    
}
int freeTrainers(trainer* trainerList, int trainerCount)
{
    
}
void releaseMemory(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{

}