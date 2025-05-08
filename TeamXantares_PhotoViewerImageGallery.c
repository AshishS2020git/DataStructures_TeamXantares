//Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <string.h>

#define MAX_IMAGES 100

char images[MAX_IMAGES][100];  // Array to store image file names
int imageCount = 0;
int currentIndex = 0;

void addImage() {
    if (imageCount >= MAX_IMAGES) {
        printf("Gallery is full. Cannot add more images.\n");
        return;
    }
    printf("Enter image filename (e.g., img1.jpg): ");
    scanf(" %[^\n]", images[imageCount]);
    imageCount++;
    printf("Image added to gallery.\n");
}

void showCurrentImage() {
    if (imageCount == 0) {
        printf("Gallery is empty.\n");
        return;
    }
    printf("\nCurrently Viewing: %s (%d of %d)\n", images[currentIndex], currentIndex + 1, imageCount);
}

void nextImage() {
    if (currentIndex < imageCount - 1) {
        currentIndex++;
        showCurrentImage();
    } else {
        printf("You are at the last image.\n");
    }
}

void prevImage() {
    if (currentIndex > 0) {
        currentIndex--;
        showCurrentImage();
    } else {
        printf("You are at the first image.\n");
    }
}

void jumpToFirst() {
    if (imageCount == 0) {
        printf("Gallery is empty.\n");
        return;
    }
    currentIndex = 0;
    showCurrentImage();
}

void jumpToLast() {
    if (imageCount == 0) {
        printf("Gallery is empty.\n");
        return;
    }
    currentIndex = imageCount - 1;
    showCurrentImage();
}

void jumpToIndex() {
    int index;
    printf("Enter image index (1 to %d): ", imageCount);
    scanf("%d", &index);
    if (index < 1 || index > imageCount) {
        printf("Invalid index.\n");
        return;
    }
    currentIndex = index - 1;
    showCurrentImage();
}

void listAllImages() {
    if (imageCount == 0) {
        printf("Gallery is empty.\n");
        return;
    }
    printf("\nImage Gallery:\n");
    for (int i = 0; i < imageCount; i++) {
        printf("%d. %s\n", i + 1, images[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Photo Viewer - Image Gallery ---\n");
        printf("1. Add Image\n");
        printf("2. View Current Image\n");
        printf("3. Next Image\n");
        printf("4. Previous Image\n");
        printf("5. Jump to First Image\n");
        printf("6. Jump to Last Image\n");
        printf("7. Jump to Specific Image\n");
        printf("8. List All Images\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addImage(); break;
            case 2: showCurrentImage(); break;
            case 3: nextImage(); break;
            case 4: prevImage(); break;
            case 5: jumpToFirst(); break;
            case 6: jumpToLast(); break;
            case 7: jumpToIndex(); break;
            case 8: listAllImages(); break;
            case 9:
                printf("Exiting Photo Viewer.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
