#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main(){
    char selection[4];

    Playlist *pl = malloc(sizeof(Playlist));
    playlist_init(pl);
    playlist_load(pl, "test.txt");

    do{
        fscanf(stdin, "%s", selection);
        if((strcmp(selection, "p") && strcmp(selection, "r") && strcmp(selection, "t") && strcmp(selection, "a") &&
            strcmp(selection, "pre") && strcmp(selection, "ins") && strcmp(selection, "del") && 
            strcmp(selection, "up") && strcmp(selection, "q"))){

                printf("Invalid choice. Try again.\n");
                continue;
        }
        if(!strcmp(selection, "p")){
            playlist_print(pl);
            continue;
        }
        if(!strcmp(selection, "r")){
            playlist_print_reverse(pl);
            continue;
        }
        if(!strcmp(selection, "t")){
            int total = playlist_total_duration(pl);
            int seconds = total % 60;
            int minutes = total / 60;
            int hours = minutes / 60;
            printf("Total: ");
        if (hours < 10){
            printf("0%d:", hours);
        }else{printf("%d:", hours);}
        if (minutes < 10){
            printf("0%d:", minutes);
        }else{printf("%d:", minutes);}
        if (seconds < 10){
            printf("0%d\n", seconds);
        }else{printf("%d\n", seconds);}
        continue;    
        }

        if(!strcmp(selection, "a")){
            char input[256];
            fscanf(stdin, "%s", input);
            char appTitle[64];
            char appArtist[64];
            int appSecond = 0;
            if(sscanf(input, "%63[^|]|%63[^|]|%d", appTitle, appArtist, &appSecond) == 3){
                playlist_append(pl, appTitle, appArtist, appSecond);
                printf("Song added.\n");
            }else{
                printf("input error.\n");
            }
            continue;
        }
        if(!strcmp(selection, "pre")){
            char input[256];
            fscanf(stdin, "%s", input);
            char preTitle[64];
            char preArtist[64];
            int preSecond = 0;
            if(sscanf(input, "%63[^|]|%63[^|]|%d", preTitle, preArtist, &preSecond) == 3){
                playlist_prepend(pl, preTitle, preArtist, preSecond);
                printf("Song added.\n");
            }else{
                printf("input error.\n");
            }
            continue;
        }
        if(!strcmp(selection, "ins")){
            getchar();
            char input[256];
            if (fgets(input, sizeof(input), stdin) != NULL) {
                input[strcspn(input, "\n")] = '\0';
            }
            char insTitle[64];
            char newTitle[64];
            char newArtist[64];
            int newSecond = 0;
            if(sscanf(input, "%63[^|]|%63[^|]|%63[^|]|%d", insTitle, newTitle, newArtist, &newSecond) == 4){
                playlist_insert_after(pl, insTitle, newTitle, newArtist, newSecond);
                printf("Song added.\n");
            }else{
                printf("input error.\n");
            }
            continue;
        } 
        if(!strcmp(selection, "del")){
            char delTitle[64];
            fscanf(stdin, "%s", delTitle);
            if(!playlist_remove(pl, delTitle)){
                printf("song removed.\n");
            }
            continue;
        }
        if(!strcmp(selection, "up")){
            char upTitle[64];
            fscanf(stdin, "%s", upTitle);
            if(playlist_move_up(pl, upTitle)){
                printf("song moved.\n");
            }
            continue;
        } 
        if(!strcmp(selection, "q")){
            playlist_save(pl, "test.txt");
            return 0;
        } 

    }while (strcmp(selection, "q"));
}

void playlist_init(Playlist *pl){
    if(pl == NULL){
        perror("malloc");
        return;
    }
    pl->count = 0;
    pl->head = NULL; 
    pl->tail = NULL;
}
void playlist_free(Playlist *pl){
    int count = 0;
    Song *temp;
    Song *del = pl->head;
    while(count < pl->count){
        temp = del->next;
        free(del);
        del = temp;
    }
    free(pl->head);
    free(pl->tail);
    free(pl);
}

int playlist_append(
    Playlist   *pl,
    const char *title,
    const char *artist,
    int         duration_sec){
        
        Song *newSong = malloc(sizeof(Song));
        if (newSong == NULL){
            perror("malloc");
            return 1;
        }
        strcpy(newSong->title, title);
        strcpy(newSong->artist, artist);
        newSong->artist[63] = '\0';
        newSong->artist[63] = '\0';
        newSong->duration_sec = duration_sec;
        newSong->next = NULL;
            if(pl->count == 0){
                newSong->prev = NULL;
                pl->tail = newSong;
                pl->head = newSong;
                pl->count++;
                return 0;
            }else{
                pl->tail->next = newSong;
                newSong->prev = pl->tail;
                pl->tail = newSong;
                pl->count++;
            }
        return 0;

}

int playlist_prepend(
    Playlist   *pl,
    const char *title,
    const char *artist,
    int         duration_sec
){
    Song *newSong = malloc(sizeof(Song));
        if (newSong == NULL){
            perror("malloc");
            return 1;
        }
        strcpy(newSong->title, title);
        strcpy(newSong->artist, artist);
        newSong->artist[63] = '\0';
        newSong->artist[63] = '\0';
        newSong->duration_sec = duration_sec;
        newSong->prev = NULL;
        newSong->next = pl->head;
            if(pl->count == 0){
                pl->tail = newSong;
                pl->head = newSong;
                pl->count++;
                return 0;
            }else{
                newSong->next = pl->head;
                pl->head->prev = newSong;
                pl->head = newSong;
            }
        pl->count++;
        return 0;
}

int playlist_insert_after(
    Playlist   *pl,
    const char *after_title,
    const char *title,
    const char *artist,
    int         duration_sec
){
    int count = 0;
    Song *temp = pl->head;
    Song *newSong = malloc(sizeof(Song));
    if(newSong == NULL){
        perror("malloc");
        return 1;
    }
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->title[63] = '\0';
    newSong->artist[63] = '\0';
    newSong->duration_sec = duration_sec;
    while(temp != NULL && count < pl->count){
        if(!strcmp(temp->title, after_title)){
            if(temp == pl->tail){
                newSong->next = NULL;
                newSong->prev = temp;
                temp->next = newSong;
                pl->tail = newSong;
                pl->count++;
                return 0;
            }else{
                newSong->next = temp->next;
                temp->next->prev = newSong;
                newSong->prev = temp;
                temp->next = newSong;
                pl->count++;
                return 0;
            }
        }
        temp = temp->next;
        count++;
    }
    printf("Title not found.\n");
    free(newSong);
    return 1;
}

int playlist_remove(
    Playlist   *pl,
    const char *title
){
    int count = 0;
    Song* temp = pl->head;
    while(temp != NULL && count < pl->count){
        if(!strcmp(temp->title, title)){
            if(temp->next == NULL){
                pl->tail = temp->prev;
            }else{
                temp->next->prev = temp->prev;
            }
            if(temp->prev == NULL){
                pl->head = temp->next;
            }else{
                temp->prev->next = temp->next;
            }
            free(temp);
            pl->count--;
            return 0;
        }
        temp = temp->next;
        count++;
    }
    printf("title not found");
    return -1;

}
int playlist_move_up(
    Playlist   *pl,
    const char *title
){
    int count = 0;
    Song *temp = pl->head;
    while(temp != NULL && count < pl->count){
        if(!strcmp(temp->title, title)){
            if(temp->prev == NULL){
                printf("Song is already at the top of the list.\n");
                return 0;
            }else{
                char tempTitle[64];
                char tempArtist[64];
                int tempDur = 0;
                strcpy(tempTitle, temp->title);
                strcpy(tempArtist, temp->artist);
                tempDur = temp->duration_sec; 
                strcpy(temp->title, temp->prev->title);
                strcpy(temp->artist, temp->prev->artist);
                temp->duration_sec = temp->prev->duration_sec;
                strcpy(temp->prev->title, tempTitle);
                strcpy(temp->prev->artist, tempArtist);
                temp->prev->duration_sec = tempDur;
                return 1;
            }
        }
        temp = temp->next;
        count++;
    }
    return 0;
    
}

void playlist_print(
    const Playlist *pl
){
    int count = 0;
    Song *temp = pl->head;
    int durMinutes = 0;
    int durSeconds = 0;

    printf("= Playlist (%d songs) =\n", pl->count);
    while (count < pl->count){
        durMinutes = temp->duration_sec / 60;
        durSeconds = temp->duration_sec % 60;
        if (durSeconds < 10){
            printf("%d. %s - %s [%d:0%d]\n", count + 1, temp->title, temp->artist, durMinutes, durSeconds);}
        else{
            printf("%d. %s - %s [%d:%d]\n", count + 1, temp->title, temp->artist, durMinutes, durSeconds);}
        temp = temp->next;
        count++;
    }   

}

void playlist_print_reverse(
    const Playlist *pl
){
    int count = 0;
    Song *temp = pl->tail;
    int durMinutes = 0;
    int durSeconds = 0;

    printf("= Playlist (%d songs) =\n", pl->count);
    while (temp != NULL && count < pl->count){
        durMinutes = temp->duration_sec / 60;
        durSeconds = temp->duration_sec % 60;
        if (durSeconds < 10){
            printf("%d. %s - %s [%d:0%d]\n", (pl->count - count), temp->title, temp->artist, durMinutes, durSeconds);}
        else{
            printf("%d. %s - %s [%d:%d]\n", (pl->count - count), temp->title, temp->artist, durMinutes, durSeconds);}
        temp = temp->prev;
        count++;
    }   

}

int playlist_total_duration(
    const Playlist *pl
){
    Song *temp = pl->head;
    int totalDur = 0;
    int count = 0;
    while(count < pl->count){
        totalDur += temp->duration_sec;
        temp = temp->next;
        count++;
    }
    return totalDur;

}

int playlist_load(
    Playlist   *pl,
    const char *path
){

    FILE *fp;

    fp = fopen(path, "r");
    
    if (fp == NULL) {
        perror("fopen failed");
        return 1;
    }
    char line[256];
    char tempTitle[64];
    char tempArtist[64];
    int tempDuration = 0;    
    while (fgets(line, sizeof(line), fp) != NULL){

        if (sscanf(line, "%63[^|]|%63[^|]|%d", tempTitle, tempArtist, &tempDuration) == 3){
            playlist_append(pl, tempTitle, tempArtist, tempDuration);
        }

    }

    fclose(fp);
    return 0;
    

}

int playlist_save(
    const Playlist *pl,
    const char     *path
){
FILE *fp;

    fp = fopen(path, "w");
    
    if (fp == NULL) {
        perror("fopen failed");
        return 1;
    }
    int count = 0;
    Song *temp = pl->head;

    while (count < pl->count){
        fprintf(fp, "%s|%s|%d\n", temp->title, temp->artist, temp->duration_sec);
        temp = temp->next;
        count++;
    }

    fclose(fp);
    return 0;
}
