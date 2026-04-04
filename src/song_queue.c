#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typdedef struct Song {
    char title[100];
    int duration; // in seconds
    struct Song* next;
} Song;

Song*head = NULL;
Song*tail = NULL;


void addSong(){
    Song *newNode = (Song*)malloc(sizeof(Song));
    printf("Enter song title: ");
    getchar();
    fgets(newNode->title, 100, stdin);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &newNode->duration);
    newNode->next = NULL;

    if(head == NULL){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("Song added: %s", newNode->title);
    printf("Duration: %d seconds\n", newNode->duration);
}

void viewPlaylist(){
    if(head == NULL){
        printf("Playlist is empty.\n");
        return;
    }

    Song* current = head;
    int index = 1;
    while(current != NULL){
        printf("%d. %s - %d seconds\n", index, current->title, current->duration);
        current = current->next;
        index++;
    }
}

void playNext(){
    if(head == NULL){
        printf("No songs to play.\n");
        return;
    }

    Song* temp = head;
    printf("Now playing: %s - %d seconds\n", temp->title, temp->duration);
    head = head->next;
    free(temp);

    if(head == NULL){
        tail = NULL;
    }
}

 void totalDuration(){
    if(head == NULL){
        printf("Playlist is empty.\n");
        return;
    }

    int total = 0;
    Song* current = head;
    while(current != NULL){
        total += current->duration;
        current = current->next;
    }

    printf("Total playlist duration: %d seconds\n", total);
}