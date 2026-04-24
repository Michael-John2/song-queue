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

void displayLibrary(void);
void displayMenu(void);
void addSong(void);
void viewPlaylist(void);
void playNext(void);
void totalDuration(void);


int main(void){
    printf("\n+==============================+\n");
    printf("|   Music Playlist Manager     |\n");
    printf("+==============================+\n");
    
    displayLibrary;
    int choice;
do {
        displayMenu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addSong();       break;
            case 2: viewPlaylist();  break;
            case 3: playNext();      break;
            case 4: totalDuration(); break;
            case 5:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\n  Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}



void displayLibrary(void){
  printf("\n--- Song Library ---\n");
    for (int i = 0; i < 10; i++) {
        printf("  [%2d] %-25s - %s\n",
               i + 1, library[i].title, library[i].artist);
    }
    printf("--------------------\n");
}

void displayMenu(void){
printf("\n------ MENU ------\n");
    printf("  1. Add Song\n");
    printf("  2. View Playlist\n");
    printf("  3. Play Next Song\n");
    printf("  4. Show Total Duration\n");
    printf("  5. Exit\n");
    printf("------------------\n");
}

void addSong(void){
displayLibrary();
    printf("\n  Enter song number (1-10): ");
    int num;
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > 10) {
        printf("  Invalid number.\n");
        return;
    }

    /* Create New Song Node */
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("  Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->title,  library[num - 1].title);
    strcpy(newNode->artist, library[num - 1].artist);
    newNode->duration = library[num - 1].duration;
    newNode->next = NULL;

    /* Is Playlist Empty? */
    if (head == NULL) {
        head = newNode;   /* set head = new node */
        tail = newNode;   
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("\n  Song Added: \"%s\" by %s\n",
           newNode->title, newNode->artist);
}

void viewPlaylist(void){

}

void playNext(void){

}

void totalDuration(void){

}
