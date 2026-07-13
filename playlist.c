#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(){
    Playlist pl;
    playlist_load(&pl, "pl.txt");

}

void playlist_init(Playlist *pl){
    pl->count = 0;
    pl->head = NULL;
    pl->tail = NULL;
}
void playlist_free(Playlist *pl){

}
int playlist_append(
    Playlist   *pl,
    const char *title,
    const char *artist,
    int         duration_sec){
        
        Song *newSong = malloc(sizeof(Song));
        if (newSong == NULL){
            perror("malloc");
            return NULL;
        }
        strcpy(newSong->title, title);
        strcpy(newSong->artist, artist);
        newSong->duration_sec = duration_sec;
        newSong->prev = pl->tail;
        newSong->next = NULL;
        if(pl->tail == NULL && pl->head == NULL){
            pl->tail = newSong;
            pl->head = newSong;
            return 0;
        }else{
            pl->tail->next = newSong;
            pl->tail = newSong;
            return 0;
        }
        return 1;

}

int playlist_prepend(
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

}

void playlist_print(
    const Playlist *pl
){

}

void playlist_print_reverse(
    const Playlist *pl
){

}

int playlist_total_duration(
    const Playlist *pl
){

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
    int tempDuration;    
    while (fgets(line, sizeof(line), fp) != NULL){

        if (sscanf(line, "%64s %64s %d", tempTitle, tempArtist, tempDuration) == 3){
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

}
