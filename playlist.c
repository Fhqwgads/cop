#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main(){
    Playlist *pl = malloc(sizeof(Playlist));
    playlist_init(pl);
    playlist_load(pl, "test.txt");
    playlist_print(pl);

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
//void playlist_free(Playlist *pl){

//}

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
        newSong->duration_sec = duration_sec;
        newSong->prev = pl->tail;
        newSong->next = NULL;
            if(pl->count == 0){
                pl->tail = newSong;
                pl->head = newSong;
                pl->count++;
                return 0;
            }
        pl->tail->next = newSong;
        pl->tail = newSong;
        pl->count++;
        return 0;

}

/*int playlist_prepend(
    Playlist   *pl,
    const char *title,
    const char *artist,
    int         duration_sec
){

}

int playlist_insert_after(
    Playlist   *pl,
    const char *after_title,
    const char *title,
    const char *artist,
    int         duration_sec
){

}
int playlist_remove(
    Playlist   *pl,
    const char *title
){

}
int playlist_move_up(
    Playlist   *pl,
    const char *title
){

}*/

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
    while (count < pl->count){
        durMinutes = temp->duration_sec / 60;
        durSeconds = temp->duration_sec % 60;
        if (durSeconds < 10){
            printf("%d. %s - %s [%d:0%d]\n", count + 1, temp->title, temp->artist, durMinutes, durSeconds);}
        else{
            printf("%d. %s - %s [%d:%d]\n", count + 1, temp->title, temp->artist, durMinutes, durSeconds);}
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
