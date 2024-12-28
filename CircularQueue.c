#include <stdio.h>

int maxsize = 30;
int f = -1, r = -1;

void Enqueue(int cq[]);
void Dequeue(int cq[]);
void Display(int cq[]);
void isFull();
void isEmpty();

void Enqueue(int cq[]) {
    int e;
    if (f == (r + 1) % maxsize) {
        printf("THE CIRCULAR QUEUE IS FULL!\n");
    } else {
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &e);
        if (f == -1 && r == -1) {
            f = r = 0;
        } else {
            r = (r + 1) % maxsize;
        }
        cq[r] = e;
        printf("Element %d added to the queue.\n", e);
    }
}

void Dequeue(int cq[]) {
    if (f == -1) {
        printf("THE QUEUE IS EMPTY!\n");
    } else {
        printf("ELEMENT DELETED IS: %d\n", cq[f]);
        if (f == r) { // Reset queue when empty
            f = r = -1;
        } else {
            f = (f + 1) % maxsize;
        }
    }
}

void Display(int cq[]) {
    if (f == -1) {
        printf("THE QUEUE IS EMPTY!\n");
    } else {
        printf("Queue elements: ");
        int i = f;
        while (1) {
            printf("%d ", cq[i]);
            if (i == r) break;
            i = (i + 1) % maxsize;
        }
        printf("\n");
    }
}

void isFull() {
    if (f == (r + 1) % maxsize) {
        printf("THE QUEUE IS FULL!\n");
    } else {
        printf("THE QUEUE IS NOT FULL!\n");
    }
}

void isEmpty() {
    if (f == -1) {
        printf("THE QUEUE IS EMPTY!\n");
    } else {
        printf("THE QUEUE IS NOT EMPTY!\n");
    }
}

int main() {
    int q[maxsize];
    int ch;
    do {
        printf("\n====================================\n");
        printf("           QUEUE OPERATIONS         \n");
        printf("====================================\n");
        
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY QUEUE\n");
        printf("4. CHECK IF FULL\n");
        printf("5. CHECK IF EMPTY\n");
        printf("6. EXIT\n");
        printf("------------------------------------\n");
        printf("Please enter your choice [1-6]: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                Enqueue(q);
                break;
            case 2:
                Dequeue(q);
                break;
            case 3:
                Display(q);
                break;
            case 4:
                isFull();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                printf("Thank you for using the Queue program. Goodbye!\n");
                break;
            default:
                printf("Invalid input! Please enter a number between 1 and 6.\n");
                break;
        }
    } while (ch != 6);
    return 0;
}
