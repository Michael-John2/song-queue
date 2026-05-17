#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define LIBRARY_SIZE 10

typedef struct Node {
    char  title[100];
    char  artist[100];
    int   duration;   /* stored in total seconds */
=======
typedef struct Node {
    char title[100];
    char artist[100];
    float duration;
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
    struct Node *next;
} Node;

typedef struct {
<<<<<<< HEAD
    char  title[100];
    char  artist[100];
    int   duration;   /* stored in total seconds */
} Song;

Song library[LIBRARY_SIZE] = {
    {"Animals",               "Maroon 5",                          210},
    {"Sacrifice",             "League of Legends, G.E.M.",         248},
    {"Bring Me To Life",      "Evanescence",                       235},
    {"Devil Trigger",         "Casey Edwards",                     405},
    {"Can You Feel My Heart", "Bring Me The Horizon",              227},
    {"Sexy And I Know It",    "LMFAO",                             199},
    {"Bismark",               "Zabaton",                           313},
    {"Thunderstruck",         "AC/DC",                             292},
    {"Pasilyo",               "Sunkissed Lola",                    269},
    {"Fortunate Son",         "Creedence Clearwater Revival",      139}
};

/* Converts seconds into "X min YY sec" format */
void formatDuration(int totalSec, char *buf) {
    int m = totalSec / 60;
    int s = totalSec % 60;
    sprintf(buf, "%d min %02d sec", m, s);
}

/* Reads an integer safely; returns 0 if input is invalid */
int readInt(int *out) {
    char buf[64];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    return sscanf(buf, "%d", out) == 1;
}

=======
    char title[100];
    char artist[100];
    float duration;
} Song;

Song library[10] = {
    {"Animals",       "Maroon 5",            3.50},
    {"Sacrifice",                 "League of Legends, G.E.M.",      4.08},
    {"Bring Me To Life",        "Evanescence",           3.55},
    {"Devil Trigger",           "Casey Edwards",      6.45},
    {"Can You Feel My Heart", "Bring Me The Horizon",          3.47},
    {"Sexy And I Know It",             "LMFAO",  3.19},
    {"Bismark",      "Zabaton",     5.13},
    {"Thunderstruck",    "AC/DC",       4.52},
    {"Pasilyo",  "Sunkissed Lola",  4.29},
    {"Fortunate Son",     "Creedence Clearwater Revival",    2.19}
};

>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
void displayLibrary(Song lib[], int size);
void displayMenu();
void addSong(Node **head, Node **tail, Song lib[]);
void viewPlaylist(Node *head);
<<<<<<< HEAD
void removeSong(Node **head, Node **tail);
void playNext(Node **head, Node **tail);
void totalDuration(Node *head);
void freePlaylist(Node **head, Node **tail);

/* Sets up the playlist and runs the main menu loop */
=======
void playNext(Node **head, Node **tail);
void totalDuration(Node *head);

>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
int main() {
    Node *head = NULL;
    Node *tail = NULL;

    printf("\n+==============================+\n");
    printf("|   Music Playlist Manager     |\n");
    printf("+==============================+\n");

<<<<<<< HEAD
    displayLibrary(library, LIBRARY_SIZE);
=======
    displayLibrary(library, 10);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52

    int choice;
    do {
        displayMenu();
        printf("Enter Choice: ");
<<<<<<< HEAD
        if (!readInt(&choice)) {
            printf("\n  Invalid input. Please enter a number.\n");
            choice = 0;
            continue;
        }
=======
        scanf("%d", &choice);
        getchar();
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52

        switch (choice) {
            case 1: addSong(&head, &tail, library);  break;
            case 2: viewPlaylist(head);               break;
            case 3: playNext(&head, &tail);           break;
            case 4: totalDuration(head);              break;
<<<<<<< HEAD
            case 5: removeSong(&head, &tail);         break;
            case 6:
                freePlaylist(&head, &tail);
=======
            case 5:
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\n  Invalid choice. Try again.\n");
        }
<<<<<<< HEAD
    } while (choice != 6);
=======
    } while (choice != 5);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52

    return 0;
}

<<<<<<< HEAD
/* Prints all songs in the library with their index and duration */
void displayLibrary(Song lib[], int size) {
    printf("\n--- Song Library ---\n");
    for (int i = 0; i < size; i++) {
        char dur[32];
        formatDuration(lib[i].duration, dur);
        printf("  [%2d] %-30s - %-35s %s\n",
               i + 1, lib[i].title, lib[i].artist, dur);
=======
void displayLibrary(Song lib[], int size) {
    printf("\n--- Song Library ---\n");
    for (int i = 0; i < size; i++) {
        printf("  [%2d] %-30s - %s\n", i + 1, lib[i].title, lib[i].artist);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
    }
    printf("--------------------\n");
}

<<<<<<< HEAD
/* Prints the menu options */
=======
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
void displayMenu() {
    printf("\n------ MENU ------\n");
    printf("  1. Add Song\n");
    printf("  2. View Playlist\n");
    printf("  3. Play Next Song\n");
    printf("  4. Show Total Duration\n");
<<<<<<< HEAD
    printf("  5. Remove a Song\n");
    printf("  6. Exit\n");
    printf("------------------\n");
}

/* Picks a song from the library and appends it to the end of the playlist */
void addSong(Node **head, Node **tail, Song lib[]) {
    displayLibrary(lib, LIBRARY_SIZE);
    printf("\n  Enter song number (1-%d): ", LIBRARY_SIZE);

    int num;
    if (!readInt(&num) || num < 1 || num > LIBRARY_SIZE) {
=======
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
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
        printf("  Invalid number.\n");
        return;
    }

<<<<<<< HEAD
    /* Reject if the song is already queued */
    Node *cur = *head;
    while (cur) {
        if (strcmp(cur->title, lib[num - 1].title) == 0) {
            printf("\n  \"%s\" is already in your playlist!\n", lib[num - 1].title);
            return;
        }
        cur = cur->next;
    }

=======
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("  Memory allocation failed.\n");
        return;
    }

    strcpy(newNode->title,  lib[num - 1].title);
    strcpy(newNode->artist, lib[num - 1].artist);
    newNode->duration = lib[num - 1].duration;
<<<<<<< HEAD
    newNode->next     = NULL;

    /* Link to end; if list was empty, also set head */
=======
    newNode->next = NULL;

>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
<<<<<<< HEAD
        *tail         = newNode;
    }

    char dur[32];
    formatDuration(newNode->duration, dur);
    printf("\n  Song Added: \"%s\" by %s (%s)\n",
           newNode->title, newNode->artist, dur);
}

/* Traverses and prints every song currently in the playlist */
=======
        *tail = newNode;
    }

    printf("\n  Song Added: \"%s\" by %s\n", newNode->title, newNode->artist);
}

>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
void viewPlaylist(Node *head) {
    printf("\n=== Your Playlist ===\n");

    if (head == NULL) {
        printf("  (Playlist is empty)\n");
        return;
    }

    Node *current = head;
<<<<<<< HEAD
    int   i       = 1;
    while (current != NULL) {
        char dur[32];
        formatDuration(current->duration, dur);
        printf("  [%d] %-30s - %-35s %s\n",
               i++, current->title, current->artist, dur);
=======
    int i = 1;
    while (current != NULL) {
        printf("  [%d] %-30s - %-20s %.2f min\n",
               i++, current->title, current->artist, current->duration);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
        current = current->next;
    }
    printf("=====================\n");
}

<<<<<<< HEAD
/* Removes a song at a chosen position by re-linking the surrounding nodes */
void removeSong(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("\n  Playlist is empty.\n");
        return;
    }

    viewPlaylist(*head);
    printf("\n  Enter song number to remove: ");

    int num;
    if (!readInt(&num) || num < 1) {
        printf("  Invalid number.\n");
        return;
    }

    Node *prev    = NULL;
    Node *current = *head;
    int   i       = 1;

    /* Walk to the target position */
    while (current != NULL && i < num) {
        prev    = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("  Song number out of range.\n");
        return;
    }

    if (prev == NULL)
        *head = current->next;      /* removing the head */
    else
        prev->next = current->next; /* skip over the removed node */

    if (current == *tail)
        *tail = prev;               /* update tail if last node was removed */

    printf("\n  Removed: \"%s\" by %s\n", current->title, current->artist);
    free(current);
}

/* Plays and removes the first song in the queue (FIFO order) */
=======
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
void playNext(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("\n  Playlist is empty. Add songs first!\n");
        return;
    }

    Node *temp = *head;
<<<<<<< HEAD
    *head      = (*head)->next;

    char dur[32];
    formatDuration(temp->duration, dur);
    printf("\n  >> Now Playing: \"%s\" by %s (%s)\n",
           temp->title, temp->artist, dur);
=======
    *head = (*head)->next;

    printf("\n  >> Now Playing: \"%s\" by %s (%.2f min)\n",
           temp->title, temp->artist, temp->duration);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52

    free(temp);

    if (*head == NULL) {
        *tail = NULL;
        printf("  (Playlist is now empty)\n");
    }
}

<<<<<<< HEAD
/* Adds up all song durations and prints the total */
=======
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
void totalDuration(Node *head) {
    if (head == NULL) {
        printf("\n  Playlist is empty.\n");
        return;
    }

<<<<<<< HEAD
    int   total   = 0;
    Node *current = head;
    while (current != NULL) {
        total  += current->duration;
        current = current->next;
    }

    char dur[32];
    formatDuration(total, dur);
    printf("\n  Total Playlist Duration: %s\n", dur);
}

/* Frees all nodes in the playlist to avoid memory leaks on exit */
void freePlaylist(Node **head, Node **tail) {
    Node *current = *head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    *tail = NULL;
=======
    float total = 0;
    Node *current = head;
    while (current != NULL) {
        total += current->duration;
        current = current->next;
    }

    printf("\n  Total Playlist Duration: %.2f minutes\n", total);
>>>>>>> 99cce9e4a4dd3a69da3a9a1091b05da7008cdf52
}