#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int jobId;
    char documentName[50];
    int numPages;
} PrintJob;

typedef struct {
    PrintJob jobs[MAX_QUEUE_SIZE];
    int front;
    int rear;
} PrintQueue;

void initializeQueue(PrintQueue* pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isQueueFull(PrintQueue* pq) {
    return pq->rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty(PrintQueue* pq) {
    return pq->front == -1;
}

void enqueue(PrintQueue* pq, PrintJob job) {
    if (isQueueFull(pq)) {
        printf("Error: Print queue is full. Cannot add new job.\n");
        return;
    }
    if (isQueueEmpty(pq)) {
        pq->front = 0;
    }
    pq->rear++;
    pq->jobs[pq->rear] = job;
    printf("Added job: %s (ID: %d, Pages: %d)\n", job.documentName, job.jobId, job.numPages);
}

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