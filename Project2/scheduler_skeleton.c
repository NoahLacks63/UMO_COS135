/*
 * Name: Noah Lacorazza
 * Program: Process Queue Simulator
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Process {
    int pid;
    int burstTime;
};

// typedef to create a type alias for the structure
// we can just use 'Process' instead of 'struct Process'
typedef struct Process Process;

// Function declarations (DO NOT REMOVE)
int isDuplicatePID(Process *queue, int size, int pid);
void addProcess(Process **queue, int *size);
void displayQueue(Process *queue, int size);
void runScheduler(Process *queue, int size);

int main() {
    Process *queue = NULL;
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- Process Scheduler Menu ---\n");
        printf("1. Add Process\n");
        printf("2. Display Queue\n");
        printf("3. Run Scheduler\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                addProcess(&queue, &size);
                break;

            case 2:
                displayQueue(queue, size);
                break;

            case 3:
                runScheduler(queue, size);
                break;

            case 4:
                free(queue);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

/*
 * Check if PID already exists in queue
 */
int isDuplicatePID(Process *queue, int size, int pid) {
    for (int i = 0; i < size; i++) {
        Process p = queue[i];
        if (p.pid == pid) 
            return 1;
    }

    return 0;
}

/*
 * Add a process to dynamic queue
 */
void addProcess(Process **queue, int *size) {
    // gathers input
    printf("Enter Process ID: ");
    int p = 0;

    // ensures proper input
    while (1) {
        if (scanf(" %d", &p) <= 0) {
            printf("ID must be an integer. Enter Process ID: ");
        } else if (isDuplicatePID(*queue, *size, p)) {
            printf("ID already exists. Enter Process ID: ");
        } else {
            break;
        }

        while (getchar() != '\n');
    }

    // allocates/reallocates memory for the queue
    if (*queue == NULL || size <= 0) {
        *queue = (Process *) calloc(1, sizeof(Process));
        *size = 1;
    } else {
        *queue = realloc(*queue, ++*size * sizeof(Process));
    }


    // gathers input
    printf("Enter Burst Time: ");
    int t = 0;

    // ensures proper input
    while (scanf(" %d", &t) <= 0) {
        printf("Time must be an integer. Enter Burst Time: ");

        while (getchar() != '\n');
    }

    (*queue)[*size-1].pid = p;
    (*queue)[*size-1].burstTime = t;
}

/*
 * Display all processes in queue
 */
void displayQueue(Process *queue, int size) {
    if (size <= 0) {
        printf("Nothing in queue.\n");
        return;
    }

    printf("----------\n");

    for (int i = 0; i < size; i++) {
        Process p = queue[i];

        printf("Process ID: %d\n", p.pid);
    }
}

/*
 * Run FCFS scheduler simulation
 * Use sleep(1) inside loop to implement a simulated delay
 */
void runScheduler(Process *queue, int size) {
    // runs each pid
    for (int i = 0; i < size; i++) {
        printf("Executing PID %d ...\n", queue[i].pid);
        printf("burstTime: %d\n", queue[i].burstTime);

        // runs each burst time
        for (int j = 0; j < queue[i].burstTime; j++) {
            sleep(1);
            printf("Time unit %d\n", j + 1);
        }

        printf("PID Completed\n");
    }
}

