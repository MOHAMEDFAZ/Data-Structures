#include <stdio.h>

#define MAX_SIZE 20
int f = -1;
int r = -1;

struct pqr {
    int data;      // Queue element
    int priority;  // Priority of the element
};

struct pqr pq[MAX_SIZE];

// Function declarations
void enqueue(struct pqr pq[]);
void dequeue(struct pqr pq[]);
void display(struct pqr pq[]);

void enqueue(struct pqr pq[]) {
    if (r == MAX_SIZE - 1) {
        printf("\nERROR: The Queue is Full!\n");
        return;
    }

    int element, prio;
    printf("Enter the element: ");
    scanf("%d", &element);
    printf("Enter its priority: ");
    scanf("%d", &prio);

    if (f == -1 && r == -1) {
        f = r = 0;
    } else {
        r++;
    }

    pq[r].data = element;
    pq[r].priority = prio;

    // Sorting elements by priority (bubble sort)
    for (int i = f; i <= r; i++) {
        for (int j = f; j < r - i + f; j++) {
            if (pq[j].priority < pq[j + 1].priority) {
                // Swap the data elements
                int temp_data = pq[j].data;
                pq[j].data = pq[j + 1].data;
                pq[j + 1].data = temp_data;

                // Swap the priorities
                int temp_priority = pq[j].priority;
                pq[j].priority = pq[j + 1].priority;
                pq[j + 1].priority = temp_priority;
            }
        }
    }
    printf("\nSUCCESS: Element added and sorted by priority.\n");
}

void dequeue(struct pqr pq[]) {
    if (f == -1 && r == -1) {
        printf("\nERROR: The Queue is Empty!\n");
        return;
    }
    
    printf("\nDELETED: Element %d with Priority %d\n", pq[f].data, pq[f].priority);
    
    if (f == r) { // Reset queue if empty
        f = r = -1;
    } else {
        f++;
    }
}

void display(struct pqr pq[]) {
    if (f == -1 && r == -1) {
        printf("\nThe Queue is Empty!\n");
        return;
    }

    printf("\nCurrent Queue (from highest to lowest priority):\n");
    printf("------------------------------\n");
    printf("|   Element   |   Priority   |\n");
    printf("------------------------------\n");
    for (int i = f; i <= r; i++) {
        printf("|     %d       |      %d       |\n", pq[i].data, pq[i].priority);
    }
    printf("------------------------------------------\n");
}

int main() {
    int choice;
    
    do {
        printf("\n====================================\n");
        printf("          PRIORITY QUEUE MENU        \n");
        printf("====================================\n");
        printf("1. ENQUEUE (Add Element)\n");
        printf("2. DEQUEUE (Remove Highest Priority)\n");
        printf("3. DISPLAY (Show Queue)\n");
        printf("4. EXIT\n");
        printf("Enter your choice [1-4]: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue(pq);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
