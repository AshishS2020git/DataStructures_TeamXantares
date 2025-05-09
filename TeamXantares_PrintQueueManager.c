////Team Xantares- Ashish Sujesh, Avani Jain, Darsh Chandran
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5
//Structure to represent a print job
typedef struct {
    int jobId;
    char documentName[50];
    int numPages;
} PrintJob;
//Structure to represent print queue
typedef struct {
    PrintJob jobs[MAX_QUEUE_SIZE];
    int front;
    int rear;
} PrintQueue;

void initializeQueue(PrintQueue* pq) { //Queue is empty during initialization
    pq->front = -1;
    pq->rear = -1;
}

int isQueueFull(PrintQueue* pq) { //Queue is full
    return pq->rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty(PrintQueue* pq) { //Queue is empty
    return pq->front == -1;
}
//Function to add new print job to queue
void enqueue(PrintQueue* pq, PrintJob job) { //Check if queue is full
    if (isQueueFull(pq)) {
        printf("Error: Print queue is full. Cannot add new job.\n");
        return;
    }
    if (isQueueEmpty(pq)) {//If queue was empty initialize front as 0
        pq->front = 0;
    }
    pq->rear++;
    pq->jobs[pq->rear] = job;
    printf("Added job: %s (ID: %d, Pages: %d)\n", job.documentName, job.jobId, job.numPages);
}
//Displays print queue
void printQueue(PrintQueue* pq) {
    if (isQueueEmpty(pq)) {
        printf("No jobs in the print queue.\n");
        return;
    }
    printf("\nCurrent Print Queue:\n");
    printf("ID\tDocument Name\t\tPages\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("%d\t%-20s\t%d\n", pq->jobs[i].jobId, pq->jobs[i].documentName, pq->jobs[i].numPages);
    }
}

int main() {
    PrintQueue pq;
    initializeQueue(&pq);

    int numJobs;
    printf("Enter the number of print jobs to add: ");
    scanf("%d", &numJobs);

    for (int i = 0; i < numJobs; i++) {
        if (isQueueFull(&pq)) {
            printf("Queue is full. Cannot add more jobs.\n");
            break;
        }
        PrintJob job;
        printf("\nEnter details for job %d:\n", i + 1);
        printf("Enter job ID: ");
        scanf("%d", &job.jobId);
        printf("Enter document name: ");
        scanf(" %[^\n]", job.documentName);
        printf("Enter number of pages: ");
        scanf("%d", &job.numPages);
        enqueue(&pq, job);
    }

    printQueue(&pq);

    printf("\nThank you for using the Print Queue Manager.\n");

    return 0;
}
