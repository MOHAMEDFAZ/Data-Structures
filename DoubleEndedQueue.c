#include <stdio.h>

#define MAXSIZE 20

int f = -1, r = -1;
int q[MAXSIZE];

void fenqueue(int q[]) {
    if (f == 0) {
        printf("ENQUEUE AT FRONT NOT POSSIBLE! QUEUE IS FULL AT THE FRONT.\n");
    } else {
        int e;
        if (f == -1) {  // If the queue is empty, initialize f and r to the last index
            f = r = MAXSIZE - 1;
        } else {
            f--;  // Move front pointer one position back
        }
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &e);
        q[f] = e;
        printf("Element %d added to the front of the queue.\n", e);
    }
}

void renqueue(int q[]) {
    if (r == MAXSIZE - 1) {
        printf("ENQUEUE AT REAR NOT POSSIBLE! QUEUE IS FULL AT THE REAR.\n");
    } else {
        int e;
        if (f == -1) {  // If the queue is empty, initialize f and r
            f = r = 0;
        } else {
            r++;  // Move rear pointer one position forward
        }
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &e);
        q[r] = e;
        printf("Element %d added to the rear of the queue.\n", e);
    }
}

void fdequeue(int q[]) {
    if (f == -1 && r == -1) {
        printf("QUEUE IS EMPTY! NO ELEMENTS TO DEQUEUE FROM FRONT.\n");
    } else {
        printf("Element %d removed from the front of the queue.\n", q[f]);
        if (f == r) {  // If the queue becomes empty after dequeuing
            f = r = -1;
        } else {
            f++;  // Move front pointer one position forward
        }
    }
}

void rdequeue(int q[]) {
    if (f == -1 && r == -1) {
        printf("QUEUE IS EMPTY! NO ELEMENTS TO DEQUEUE FROM REAR.\n");
    } else {
        printf("Element %d removed from the rear of the queue.\n", q[r]);
        if (f == r) {  // If the queue becomes empty after dequeuing
            f = r = -1;
        } else {
            r--;  // Move rear pointer one position back
        }
    }
}

void display(int q[]) {
    if (f == -1 && r == -1) {
        printf("QUEUE IS EMPTY! NO ELEMENTS TO DISPLAY.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;

    do {
        printf("\n================ QUEUE OPERATIONS ================\n");
        printf("1. ENQUEUE AT FRONT\n");
        printf("2. ENQUEUE AT REAR\n");
        printf("3. DEQUEUE FROM FRONT\n");
        printf("4. DEQUEUE FROM REAR\n");
        printf("5. DISPLAY QUEUE\n");
        printf("6. EXIT\n");
        printf("Enter your choice [1-6]: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                fenqueue(q);
                break;
            case 2:
                renqueue(q);
                break;
            case 3:
                fdequeue(q);
                break;
            case 4:
                rdequeue(q);
                break;
            case 5:
                display(q);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (ch != 6);

    return 0;
}
