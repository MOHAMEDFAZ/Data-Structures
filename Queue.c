#include <stdio.h>

int f = -1, r = -1;
const int maxsize = 20;

void Create();
void Enqueue(int q[]);
void Dequeue(int q[]);
void Fpeak(int q[]);
void Rpeak(int q[]);
void Display(int q[]);
void isFull();
void isEmpty();

int main() {
    int q[maxsize];
    int ch;
    do {
        printf("\n====================================\n");
        printf("           QUEUE OPERATIONS         \n");
        printf("====================================\n");
        printf("1. CREATE QUEUE\n");
        printf("2. ENQUEUE\n");
        printf("3. DEQUEUE\n");
        printf("4. DISPLAY QUEUE\n");
        printf("5. VIEW FRONT ELEMENT (FPEAK)\n");
        printf("6. VIEW REAR ELEMENT (RPEAK)\n");
        printf("7. CHECK IF FULL\n");
        printf("8. CHECK IF EMPTY\n");
        printf("9. EXIT\n");
        printf("------------------------------------\n");
        printf("Please enter your choice [1-9]: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                Create();
                break;
            case 2:
                Enqueue(q);
                break;
            case 3:
                Dequeue(q);
                break;
            case 4:
                Display(q);
                break;
            case 5:
                Fpeak(q);
                break;
            case 6:
                Rpeak(q);
                break;
            case 7:
                isFull();
                break;
            case 8:
                isEmpty();
                break;
            case 9:
                printf("Thank you for using the Queue program. Goodbye!\n");
                break;
            default:
                printf("Invalid input! Please enter a number between 1 and 9.\n");
                break;
        }
    } while (ch != 9);
    return 0;
}

void Create() {
    f = -1;
    r = -1;
    printf("QUEUE INITIALIZED SUCCESSFULLY.\n");
}

void Enqueue(int q[]) {
    if (r == maxsize - 1) {
        printf("QUEUE IS FULL! Cannot add more elements.\n");
        return;
    }

    int value;
    printf("Enter the element to enqueue: ");
    scanf("%d", &value);

    if (f == -1) {
        f = 0;
    }
    r++;
    q[r] = value;
    printf("Element %d added to the queue.\n", value);
}

void Dequeue(int q[]) {
    if (f == -1 || f > r) {
        printf("QUEUE IS EMPTY! No elements to dequeue.\n");
        return;
    }
    printf("Element %d removed from the queue.\n", q[f]);
    f++;
    if (f > r) { // Reset queue when empty
        f = r = -1;
    }
}

void Fpeak(int q[]) {
    if (f == -1) {
        printf("QUEUE IS EMPTY! No front element.\n");
    } else {
        printf("Front element is: %d\n", q[f]);
    }
}

void Rpeak(int q[]) {
    if (r == -1) {
        printf("QUEUE IS EMPTY! No rear element.\n");
    } else {
        printf("Rear element is: %d\n", q[r]);
    }
}

void Display(int q[]) {
    if (f == -1 || f > r) {
        printf("QUEUE IS EMPTY! No elements to display.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void isFull() {
    if (r == maxsize - 1) {
        printf("QUEUE IS FULL.\n");
    } else {
        printf("QUEUE IS NOT FULL.\n");
    }
}

void isEmpty() {
    if (f == -1 || f > r) {
        printf("QUEUE IS EMPTY.\n");
    } else {
        printf("QUEUE IS NOT EMPTY.\n");
    }
}
