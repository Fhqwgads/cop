/* COP 3502C PA1 
This program is written by: Nicholas Anthony Hernandez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
int processCaptures(trainer* trainers, int trainerCount, int regionCount, int monsterCount);

int main(void)
{
    int monsterCount = 0;//initializes the variables keeping track of the number of structs
    int regionCount = 0;
    int trainerCount = 0;
    monster** monsterList = readMonsters(&monsterCount);//creates a list of pointers to monster pointers
    region** regionList = readRegions(&regionCount, monsterList, monsterCount);//creates a list of pointers to region pointers
    trainer* trainers = loadTrainers(&trainerCount, regionList, regionCount);//creates a list of trainers
    processInputs(monsterList, monsterCount, regionList, regionCount, trainers, trainerCount); //reads through lists to print values
    releaseMemory(monsterList, monsterCount, regionList, regionCount, trainers, trainerCount); //frees all memory tied up in the heap
}


monster* makeMonster(char *name, char *element, int population)
{
    monster* mon = malloc(sizeof(monster)); //creates space for a monster pointer that the function will return
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
    monster** monsterList = malloc(*monsterCount * sizeof(monster*));//creates space for a list of monster pointers
    if (monsterList == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    char name[50];//temp space for the name held in the stack
    char element[50];//same thing here
    int population = 0;

    for(int i = 0; i < *monsterCount; i++)
    {
        scanf("%49s", name);//reads name from input
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));//creates a character pointer to hold the name dynamically
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }

        strcpy(nameP, name);
        
        scanf("%49s", element);//scans string from file
        char *elementP = malloc((strlen(element) + 1) * sizeof(char));//dynamically allocated space for string
        if (elementP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }
        
        strcpy(elementP, element);//copies string into the heap

        scanf("%d", &population);

        if(population > 1000000)
        {
            population = 1000000;
        }
        
        monsterList[i] = makeMonster(nameP, elementP, population); //all values get passed to makemonster function to populate the list
        
    }
    return monsterList;
}

region** readRegions(int *countRegions, monster** monsterList, int monsterCount)
{
    scanf("%d", countRegions);
    region** regions = malloc(*countRegions * sizeof(region*));//allocates space for the list of region pointers
    if(regions == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    char name[50];
    char scanMon[50];//temp char array to scan and test the input against the monsterList 

    
    for(int i = 0; i < *countRegions; i++)//iterates through the regions i
    {
        regions[i] = malloc(sizeof(region));
        if (regions[i] == NULL)
        {
            printf("malloc failed.");
            return NULL;
        }
        regions[i]->total_population = 0;//initializes the total population value.
        scanf("%49s", name);
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }
        strcpy(nameP, name);
        regions[i]->name = nameP;
        scanf("%d", &regions[i]->monster_cnt);
        regions[i]->monsters = malloc(regions[i]->monster_cnt * sizeof(monster*));
        for(int j = 0; j < regions[i]->monster_cnt; j++)//iterates through the monsters in the region j
        {
            if (regions[i]->monsters == NULL)
            {
                perror("malloc failed.");
                return NULL;
                free(regions[i]->monsters);
            }
            scanf("%49s", scanMon);

            for (int k = 0; k < monsterCount; k++)//iterates through the whole list of monsters k
            {
                    
                if (!strcmp(monsterList[k]->name, scanMon))//if monster[k] matches scanMon it will link the region[i]monster[j] to that monster[k]
                {
                    regions[i]->monsters[j] = monsterList[k];
                    regions[i]->total_population += regions[i]->monsters[j]->population;//updates total pop of a region
                    
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
    char name[50];
    
    trainer* trainers =  malloc(*trainerCount * sizeof(trainer));
    if(trainers == NULL)
    {
        perror("malloc failed.");
        return NULL;
    }
    for(int i = 0; i<*trainerCount; i++)//iterates though trainers[i]
    {
        trainers[i].visits = malloc(sizeof(itinerary));//creates space for each trainer's itinerary
        if(trainers[i].visits == NULL)
        {
            perror("malloc failed");
            return NULL;
        }
        scanf("%49s", name);
        char *nameP = malloc((strlen(name) + 1) * sizeof(char));
        if (nameP == NULL)
        {
            perror("malloc failed.");
            return NULL;
        }
        strcpy(nameP, name);
        trainers[i].name = nameP;
        scanf("%d", &trainers[i].visits->captures);
        scanf("%d", &trainers[i].visits->region_cnt);
        trainers[i].visits->regions = malloc(trainers[i].visits->region_cnt * sizeof(region*));//creates space for each itinerary's region list
        if (trainers[i].visits->regions == NULL) 
        {
            perror("malloc failed.");
            return NULL;
        }
        for(int j = 0; j<trainers[i].visits->region_cnt; j++)//iterates through visit->regions[j]
        {
            scanf("%49s", regionName);
            for(int k = 0; k < countRegions; k++)
            {
                if(regionList[k] == NULL)
                    {
                         printf("\nRegion not found.");
                    }
                if(regionList[k] != NULL && !strcmp(regionName, regionList[k]->name))//links a trainer[i]region[j] to a region on the list [k]
                    {
                        trainers[i].visits->regions[j] = regionList[k];
                    }   
            }
            
        }
        
    }

    return trainers;
}

void processInputs(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{
    for(int i = 0; i < trainerCount; i++)//iterates through the trainers
    {
        printf("%s\n", trainerList[i].name);
        for(int j = 0; j<trainerList[i].visits->region_cnt; j++)//iterates through each trainer's iteneraries
        {
            printf("%s\n", trainerList[i].visits->regions[j]->name);
            for(int k = 0; k<trainerList[i].visits->regions[j]->monster_cnt; k++)
            {
                if(processCaptures(trainerList, i, j, k) != 0)//function that calculates each trainer's caught pokemon if it returns 0 it skips the print function
                {
                    printf("%d-" , processCaptures(trainerList, i, j, k));
                    printf("%s\n", trainerList[i].visits->regions[j]->monsters[k]->name);
                }
               
            }
        }
        printf("\n");
    }
}

int processCaptures(trainer* trainers, int trainerCount, int regionCount, int monsterCount)
{
    double relativePop = 0;
    double totalPop = 0;
    double totalCaptures = 0;
    int captures = 0;
    //values are taken from out of the function to access specific data from each trainer
    relativePop = trainers[trainerCount].visits->regions[regionCount]->monsters[monsterCount]->population;
    totalPop = trainers[trainerCount].visits->regions[regionCount]->total_population;
    totalCaptures = trainers[trainerCount].visits->captures;
    captures = round(totalCaptures * (relativePop / totalPop));//calculates the capture of the specific monster
    return captures;
}

void releaseMemory(monster** monsterList, int monsterCount, region** regionList, int regionCount, trainer* trainerList, int trainerCount)
{
    for(int i = 0; i < monsterCount; i++)
    {
        free(monsterList[i]->name);
        free(monsterList[i]->element);
        free(monsterList[i]);
    }
    free(monsterList);
    for(int i = 0; i < regionCount; i++)
    {
        free(regionList[i]->name);
        free(regionList[i]->monsters);
    }
    free(regionList);
    for(int i = 0; i < trainerCount; i++)
    {
        free(trainerList[i].name);
        free(trainerList[i].visits->regions);
        free(trainerList[i].visits);
    }
    free(trainerList);
}