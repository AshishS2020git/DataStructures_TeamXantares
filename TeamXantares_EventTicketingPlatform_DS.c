//Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 5
#define MAX_QUEUE_SIZE 100
//Structure to store event details
typedef struct {
    int id;
    char name[50];
    int totalSeats;
    int availableSeats;
    float price;
} Event;
//Structure to store booking details
typedef struct {
    int bookingId;
    int eventId;
    char customerName[50];
    int seatsBooked;
    float totalPrice;
} Booking;
//Structure to store booking queue
typedef struct {
    Booking bookings[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} BookingQueue;

// Initialize events (Premade Events that are available)
Event events[MAX_EVENTS] = {
    {1, "Music Concert", 100, 100, 500.0},
    {2, "Art Exhibition", 50, 50, 300.0},
    {3, "Tech Conference", 200, 200, 1000.0},
    {4, "Food Festival", 150, 150, 250.0},
    {5, "Stand-up Comedy", 80, 80, 400.0}
};

// Initialize booking queue
BookingQueue bookingQueue = {.front = 0, .rear = -1, .count = 0};
int bookingIdCounter = 1;

// Function to display available events
void displayEvents() {
    printf("\nAvailable Events:\n");
    printf("ID\tEvent Name\t\tAvailable Seats\tPrice per Ticket\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        printf("%d\t%-20s\t%d\t\t%.2f\n", events[i].id, events[i].name, events[i].availableSeats, events[i].price);
    }
}

// Function to enqueue a booking
void enqueueBooking(BookingQueue *q, Booking b) {
    if (q->count == MAX_QUEUE_SIZE) { //checking if queue is full for booking
        printf("Booking queue is full. Cannot add more bookings.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //Increment rear in circular method
    q->bookings[q->rear] = b; //Ensures booking is added to queue
    q->count++;//Booking count incremented
}

// Function to display booking summary
void displayBookingSummary(BookingQueue *q) {
    if (q->count == 0) { //No bookings made
        printf("\nNo bookings made.\n");
        return;
    }

    printf("\nBooking Summary:\n");
    printf("Booking ID\tCustomer Name\tEvent Name\tSeats Booked\tTotal Price\n"); //Header
    int index = q->front; //Start from front of queue
    for (int i = 0; i < q->count; i++) {
        Booking b = q->bookings[index]; //gets current booking
        Event *event = NULL;
        for (int j = 0; j < MAX_EVENTS; j++) { //Find which event is associated with respective booking
            if (events[j].id == b.eventId) {
                event = &events[j];
                break;
            }
        }
        if (event != NULL) { //Prints booking details along with event name
            printf("%d\t\t%-15s\t%-15s\t%d\t\t%.2f\n",
                   b.bookingId,
                   b.customerName,
                   event->name,
                   b.seatsBooked,
                   b.totalPrice);
        }
        index = (index + 1) % MAX_QUEUE_SIZE; //Moves to next booking
    }
}

// Function to book tickets
void bookTickets() {
    displayEvents(); //Show avaolable events

    int eventId;
    printf("\nEnter Event ID to book tickets: "); //Start booking process for tickets
    scanf("%d", &eventId);

    Event *selectedEvent = NULL;
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (events[i].id == eventId) { //Verifies for matching event using event id
            selectedEvent = &events[i];
            break;
        }
    }

    if (selectedEvent == NULL) {
        printf("Invalid Event ID.\n");
        return;
    }

    if (selectedEvent->availableSeats == 0) { //Check if event is sold out
        printf("Sorry, no seats available for this event.\n");
        return;
    }

    char customerName[50];
    int seats;
    printf("Enter your name: ");
    scanf(" %[^\n]", customerName);
    printf("Enter number of tickets to book: ");
    scanf("%d", &seats);

    if (seats <= 0 || seats > selectedEvent->availableSeats) { //Check if seat request is available
        printf("Invalid number of seats. Only %d seats available.\n", selectedEvent->availableSeats);
        return;
    }

    float totalPrice = seats * selectedEvent->price; //Calculate total price
    printf("Total Price: %.2f\n", totalPrice);

    char confirm; //Confirmation
    printf("Confirm booking? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') { //Perform booking if booking has been confirmed
        selectedEvent->availableSeats -= seats;
        Booking newBooking;
        newBooking.bookingId = bookingIdCounter++;
        newBooking.eventId = selectedEvent->id;
        strcpy(newBooking.customerName, customerName);
        newBooking.seatsBooked = seats;
        newBooking.totalPrice = totalPrice;

        enqueueBooking(&bookingQueue, newBooking);

        printf("Booking confirmed!\n");
    } else {
        printf("Booking cancelled.\n");
    }
}

int main() {
    char continueBooking;

    do {
        bookTickets();
        printf("\nDo you want to book another ticket? (Y/N): "); //Ask if user wants to continue booking.
        scanf(" %c", &continueBooking);
    } while (continueBooking == 'Y' || continueBooking == 'y');

    displayBookingSummary(&bookingQueue);
    printf("\nThank you for your purchase!\n");

    return 0;
}
