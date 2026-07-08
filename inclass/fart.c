#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    LEFT, RIGHT, U_TURN, MERGE_LEFT, MERGE_RIGHT
}Direction;

typedef struct Waypoint{
    char *street;
    char *zipcode;
    Direction dir;
    double distance;
    Waypoint *next;
}Waypoint;

Waypoint *initlist(Waypoint *head, Waypoint newNode);
Waypoint *addWaypoint(Waypoint *head, Waypoint newNode);
Waypoint *searchByStreet(Waypoint *head, Waypoint newNode);
Waypoint *updateWaypoint(Waypoint *head, Waypoint newNode);
Waypoint *deleteWaypoint(Waypoint *head, Waypoint newNode);
void deleteList(Waypoint *head);
void printDirections(Waypoint *head);

int main(void){
    int choice = 0;
    do{
        printf("1 - Initialize Directions\n");
        printf("2 - Add a waypoint\n");
        printf("3 - Update a waypoint\n");
        printf("4 - delete a waypoint\n");
        printf("5 - Find a waypoint by street\n");
        printf("6 - print directions\n");
        printf("7 - delete all directions\n");
        printf("8 - Exit\n");
        fscanf(stdin, "%d", &choice);
    }(while choice != 8);
    switch(choice){
        case 1: 
            Waypoint newNode ={
                .city = "",
                .dir = "",
                
            }
            head = addWaypoint(head, )
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
    }
} 

Waypoint *addWaypoint(Waypoint *head, Waypoint newNode){
    Waypoint *n = malloc(sizeof(Waypoint));
    if (!n){
        perror("malloc");
        return NULL;
    }
    n->zipcode = newNode.zipcode;
    n->distance = newNode.distance;
    n->dir = newNode.dir;
    n->next = newNode.next;

}