////Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100

char players[MAX_PLAYERS][50]; //2D Array to store names of players , each name is upto 49 characters.
int playerCount = 0; //Current number of players
int currentPlayerIndex = 0; //Current Player Index value for traversal & tracking
//Adding Player in the game
void addPlayer() {
    if (playerCount >= MAX_PLAYERS) { //Checks if player limit has been reached
        printf("Cannot add more players.\n");
        return;
    }
    printf("Enter player name: "); //Enter Player details
    scanf(" %[^\n]", players[playerCount]); //Read full line including spaces into player array
    playerCount++;
    printf("Player added.\n");
}
//Remove player from game
void removePlayer() { 
    if (playerCount == 0) {
        printf("No players to remove.\n");  //No player present in game
        return;
    }

    char name[50];
    printf("Enter the name of the player to remove: ");
    scanf(" %[^\n]", name);

    int found = -1; //Initialize index to track
    for (int i = 0; i < playerCount; i++) { //Traverse loop and find player
        if (strcmp(players[i], name) == 0) { //Compare strings
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Player not found.\n");
        return;
    }

    for (int i = found; i < playerCount - 1; i++) { //Shift remaining players up in arrau
        strcpy(players[i], players[i + 1]); //Overwrite Current with next
    }

    playerCount--; //Decrementing player count because player has been removed
    if (currentPlayerIndex >= playerCount) {
        currentPlayerIndex = 0;
    }

    printf("Player removed.\n");
}
//Displays all players
void showPlayers() {
    printf("\nCurrent Players:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%d. %s\n", i + 1, players[i]);
    }
}
//Shows which players turn is next
void nextTurn() { 
    if (playerCount == 0) {
        printf("No players in the game.\n");
        return;
    }

    printf("\n>> It's %s's turn.\n", players[currentPlayerIndex]);
    currentPlayerIndex = (currentPlayerIndex + 1) % playerCount; //Move to next player
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
