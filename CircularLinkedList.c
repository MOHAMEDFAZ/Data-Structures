#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the node
struct node {
    int data;          // Data of the node
    struct node* link; // Link to the next node
};

// Initializing the head and tail to NULL, indicating an empty list
struct node* head = NULL;
struct node* tail = NULL;

// Function to create and add a new node to the circular linked list
void create() {
    int value;
    printf("ENTER THE VALUE TO BE STORED: ");
    scanf("%d", &value);  // Input the value to be added
    
    // Allocate memory for the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = value;  // Assign the input value to the node's data

    // If the list is empty, the new node will be the only node (head and tail point to it)
    if (head == NULL) {
        head = temp;    // Set head to the new node
        tail = temp;    // Set tail to the new node
        temp->link = temp; // The link of the single node points to itself (circular link)
    } else {
        tail->link = temp;  // The current tail points to the new node
        temp->link = head;  // The new node's link points to the head (circular link)
        tail = temp;        // Update the tail to point to the new node
    }

    // Inform the user that the value has been added
    printf("THE VALUE %d IS ADDED TO THE CIRCULAR LINKED LIST\n", value);
}

// Function to remove the node at the head (the first node in the circular linked list)
void remove1() {
    if (head == NULL) {  // If the list is empty
        printf("THE CIRCULAR LINKED LIST IS EMPTY!\n");
    } else {
        struct node* temp = head;  // Store the current head
        
        printf("%d HAS BEEN REMOVED!\n", head->data);  // Print the value being removed
        
        // If there's only one node in the list
        if (head == tail) {
            free(head);  // Free the memory of the node
            head = tail = NULL;  // Set both head and tail to NULL (empty list)
        } else {
            head = head->link;   // Move head to the next node
            tail->link = head;   // Update the tail's link to point to the new head (circular)
            free(temp);          // Free the memory of the old head
        }
    }
}

// Function to display all nodes in the circular linked list
void display() {
    if (head == NULL) {  // If the list is empty
        printf("LIST IS EMPTY\n");
    } else {
        struct node* temp = head;  // Start from the head
        do {
            printf("%d ", temp->data);  // Print the current node's data
            temp = temp->link;  // Move to the next node
        } while (temp != head);  // Stop when we circle back to the head
        printf("\n");
    }
}

// Main function with menu options for user interaction
int main() {
    int ch;
    do {
        // Display the menu
        printf("MENU\n1.CREATE\n2.REMOVE\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER THE CHOICE [1-4]: ");
        scanf("%d", &ch);  // Get the user's choice
        
        if (ch == 1) {
            create();  // Call the create function if the user chose option 1
        } else if (ch == 2) {
            remove1();  // Call the remove function if the user chose option 2
        } else if (ch == 3) {
            display();  // Call the display function if the user chose option 3
        } else if (ch == 4) {
            printf("THE PROGRAM HAS BEEN TERMINATED!\n");  // Exit message
        } else {
            printf("ENTER A VALID CHOICE!\n");  // Error message for invalid choice
        }
    } while (ch != 4);  // Continue until the user chooses to exit (option 4)
    
    return 0;  // End of program
}
