#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[100];
    char artist[100];
    float duration;
    struct Node *next;
} Node;

typedef struct {
    char title[100];
    char artist[100];
    float duration;
} Song;

Song library[10] = {
    {"Bohemian Rhapsody",       "Queen",            5.55},
    {"Imagine",                 "John Lennon",      3.03},
    {"Hotel California",        "Eagles",           6.30},
    {"Hey Jude",                "The Beatles",      7.11},
    {"Smells Like Teen Spirit", "Nirvana",          5.01},
    {"Billie Jean",             "Michael Jackson",  4.54},
    {"Stairway to Heaven",      "Led Zeppelin",     8.02},
    {"Like a Rolling Stone",    "Bob Dylan",        6.13},
    {"I Will Always Love You",  "Whitney Houston",  4.31},
    {"Sweet Child O' Mine",     "Guns N' Roses",    5.56}
};

void displayLibrary(Song lib[], int size);
void displayMenu();
void addSong(Node **head, Node **tail, Song lib[]);
void viewPlaylist(Node *head);
void playNext(Node **head, Node **tail);
void totalDuration(Node *head);

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    printf("\n+==============================+\n");
    printf("|   Music Playlist Manager     |\n");
    printf("+==============================+\n");

    displayLibrary(library, 10);

    int choice;
    do {
        displayMenu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addSong(&head, &tail, library);  break;
            case 2: viewPlaylist(head);               break;
            case 3: playNext(&head, &tail);           break;
            case 4: totalDuration(head);              break;
            case 5:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\n  Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayLibrary(Song lib[], int size) {
    printf("\n--- Song Library ---\n");
    for (int i = 0; i < size; i++) {
        printf("  [%2d] %-30s - %s\n", i + 1, lib[i].title, lib[i].artist);
    }
    printf("--------------------\n");
}

void displayMenu() {
    printf("\n------ MENU ------\n");
    printf("  1. Add Song\n");
    printf("  2. View Playlist\n");
    printf("  3. Play Next Song\n");
    printf("  4. Show Total Duration\n");
    printf("  5. Exit\n");
    printf("------------------\n");
}

void addSong(Node **head, Node **tail, Song lib[]) {
    displayLibrary(lib, 10);
    printf("\n  Enter song number (1-10): ");
    int num;
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > 10) {
        printf("  Invalid number.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("  Memory allocation failed.\n");
        return;
    }

    strcpy(newNode->title,  lib[num - 1].title);
    strcpy(newNode->artist, lib[num - 1].artist);
    newNode->duration = lib[num - 1].duration;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("\n  Song Added: \"%s\" by %s\n", newNode->title, newNode->artist);
}

void viewPlaylist(Node *head) {
    printf("\n=== Your Playlist ===\n");

    if (head == NULL) {
        printf("  (Playlist is empty)\n");
        return;
    }

    Node *current = head;
    int i = 1;
    while (current != NULL) {
        printf("  [%d] %-30s - %-20s %.2f min\n",
               i++, current->title, current->artist, current->duration);
        current = current->next;
    }
    printf("=====================\n");
}

void playNext(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("\n  Playlist is empty. Add songs first!\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    printf("\n  >> Now Playing: \"%s\" by %s (%.2f min)\n",
           temp->title, temp->artist, temp->duration);

    free(temp);

    if (*head == NULL) {
        *tail = NULL;
        printf("  (Playlist is now empty)\n");
    }
}

void totalDuration(Node *head) {
    if (head == NULL) {
        printf("\n  Playlist is empty.\n");
        return;
    }

    float total = 0;
    Node *current = head;
    while (current != NULL) {
        total += current->duration;
        current = current->next;
    }

    printf("\n  Total Playlist Duration: %.2f minutes\n", total);
}