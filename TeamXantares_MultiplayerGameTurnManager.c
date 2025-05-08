////Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100

char players[MAX_PLAYERS][50];
int playerCount = 0;
int currentPlayerIndex = 0;

void addPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Cannot add more players.\n");
        return;
    }
    printf("Enter player name: ");
    scanf(" %[^\n]", players[playerCount]);
    playerCount++;
    printf("Player added.\n");
}

void removePlayer() {
    if (playerCount == 0) {
        printf("No players to remove.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the player to remove: ");
    scanf(" %[^\n]", name);

    int found = -1;
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i], name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Player not found.\n");
        return;
    }

    for (int i = found; i < playerCount - 1; i++) {
        strcpy(players[i], players[i + 1]);
    }

    playerCount--;
    if (currentPlayerIndex >= playerCount) {
        currentPlayerIndex = 0;
    }

    printf("Player removed.\n");
}

void showPlayers() {
    printf("\nCurrent Players:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%d. %s\n", i + 1, players[i]);
    }
}

void nextTurn() {
    if (playerCount == 0) {
        printf("No players in the game.\n");
        return;
    }

    printf("\n>> It's %s's turn.\n", players[currentPlayerIndex]);
    currentPlayerIndex = (currentPlayerIndex + 1) % playerCount;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Multiplayer Game Turn Manager ---\n");
        printf("1. Add Player\n");
        printf("2. Remove Player\n");
        printf("3. Show Players\n");
        printf("4. Next Turn\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                removePlayer();
                break;
            case 3:
                showPlayers();
                break;
            case 4:
                nextTurn();
                break;
            case 5:
                printf("Exiting Game Turn Manager.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
