//Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 //Inventory size
//Structure to store details 
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

Item stack[MAX];
int top = -1; //Initialize top
//Push item into inventory
void push() {
    if (top == MAX - 1) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    top++;
    stack[top] = newItem;
    printf("Item added to inventory.\n");
}
//Remove latest item added in inventory
void pop() {
    if (top == -1) {
        printf("Inventory is empty. No items to remove.\n");
        return;
    }
    Item removedItem = stack[top];
    top--;
    printf("Removed item: %s\n", removedItem.name);
}
//Display inventory summary
void displaySummary() {
    if (top == -1) {
        printf("Inventory is empty.\n");
    } else {
        printf("\nInventory Summary:\n");
        printf("--------------------------------------------------\n");
        printf("S.No\tItem Name\tQuantity\tPrice\n");
        printf("--------------------------------------------------\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\t%-15s\t%d\t\t%.2f\n", i + 1, stack[i].name, stack[i].quantity, stack[i].price);
        }
        printf("--------------------------------------------------\n");
    }
    printf("Thank you for using the Warehouse Inventory System.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Inventory System\n");
        printf("1. Add Item to Inventory\n");
        printf("2. Remove Item from Inventory\n");
        printf("3. View Inventory Summary and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displaySummary();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
