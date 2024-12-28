#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin() {
    int data;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->prev = NULL;

    printf("Enter the element: ");
    scanf("%d", &data);
    new_node->data = data;

    if (head == NULL) {
        new_node->next = NULL;
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    printf("%d inserted at the beginning\n", data);
}

void insert_end() {
    int data;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    new_node->next = NULL;
    printf("Enter the element: ");
    scanf("%d", &data);
    new_node->data = data;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("%d inserted at the end\n", data);
}

void delete_begin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("%d deleted from the beginning\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;

    printf("%d deleted from the end\n", temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 6);

    return 0;
}
