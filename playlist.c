#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(){
    Playlist p1;
    playlist_init(&p1);

}

void playlist_init(Playlist *pl){
    p1.head =
}
void playlist_free(Playlist *pl){

}
int playlist_append(
    Playlist   *pl,
    const char *title,
    const char *artist,
    int         duration_sec){

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

}

int playlist_save(
    const Playlist *pl,
    const char     *path
){

}
