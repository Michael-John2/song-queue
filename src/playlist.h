#ifndef PLAYLIST_H
#define PLAYLIST_H


typedef struct Song {
    char title[100];
    int duration; // in seconds
    struct Song* next;
}

extern struct Song* head;
extern struct Song* tail;

void addSong();
void viewPlaylist();
void playNext();
void totalDuration();

#endif