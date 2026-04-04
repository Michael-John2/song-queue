#include <stdio.h>
#include "playlist.h"


void menu(){
    printf("\n--- Music Playlist ---\n");
    printf("1. Add Song\n");
    printf("2. View Playlist\n");
    printf("3. Play Next Song\n");
    printf("4. Total Duration\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while(1){
        menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addSong();
                break;
            case 2:
                viewPlaylist();
                break;
            case 3:
                playNext();
                break;
            case 4:
                totalDuration();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}