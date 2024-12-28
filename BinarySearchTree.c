#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct node {
    int data;
    struct node *lc; // Left child
    struct node *rc; // Right child
};

// Initialize pointers for root and temporary nodes
struct node *root = NULL;

// Function prototypes
void insert();
void search();
void inorder(struct node *p);
void preorder(struct node *p);
void postorder(struct node *p);

int main() {
    int ch;
    do {
        // Display menu
        printf("\n****************");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        // Perform action based on user choice
        if (ch == 1) insert();
        else if (ch == 2) search();
        else if (ch == 3) { printf("\nInorder: "); inorder(root); }
        else if (ch == 4) { printf("\nPreorder: "); preorder(root); }
        else if (ch == 5) { printf("\nPostorder: "); postorder(root); }
        else if (ch == 6) break;
        else printf("\nInvalid option");
    } while (ch != 6);
    return 0;
}

// Function to insert a new node into the BST
void insert() {
    int d;
    printf("\nEnter data to insert: ");
    scanf("%d", &d);

    // Create a new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->lc = temp->rc = NULL;

    // If tree is empty, new node becomes root
    if (root == NULL) {
        root = temp;
    } else {
        struct node *ptr = root, *parent = NULL;

        // Find the correct spot for the new node
        while (ptr != NULL) {
            parent = ptr;
            if (d < ptr->data) ptr = ptr->lc; // Move to left child
            else ptr = ptr->rc;               // Move to right child
        }

        // Link new node to the appropriate parent's child
        if (d < parent->data) parent->lc = temp;
        else parent->rc = temp;
    }
    printf("Element inserted\n");
}

// Function to search for an element in the BST
void search() {
    int item, found = 0;
    printf("\nEnter element to search: ");
    scanf("%d", &item);

    struct node *ptr = root;

    // Traverse the tree until the item is found or reach end
    while (ptr != NULL) {
        if (item == ptr->data) { // Item found
            found = 1;
            break;
        } else if (item < ptr->data) {
            ptr = ptr->lc; // Move to left child
        } else {
            ptr = ptr->rc; // Move to right child
        }
    }

    // Display result of search
    if (found) printf("%d is found in the tree\n", item);
    else printf("%d not found\n", item);
}

// Inorder traversal: left, root, right
void inorder(struct node *p) {
    if (p != NULL) {
        inorder(p->lc);
        printf("%d ", p->data);
        inorder(p->rc);
    }
}

// Preorder traversal: root, left, right
void preorder(struct node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
}

// Postorder traversal: left, right, root
void postorder(struct node *p) {
    if (p != NULL) {
        postorder(p->lc);
        postorder(p->rc);
        printf("%d ", p->data);
    }
}
