#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link; // pointer to the next node
};

// global pointers
struct node *head, *ptr, *ptr1;

// declaring all the functions
void create_list();
void display_list();
void insert_begin();
void insert_end();
void insert_position();
void delete_begin();
void delete_end();
void delete_position();

int main()
{
    int ch;
    do
    {
        // menu-driven - all options displayed
        printf("\nSINGLY LINKED - LIST OPERATIONS\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT @BEGIN\n");
        printf("4. INSERT @END\n");
        printf("5. INSERT @POSITION\n");
        printf("6. DELETE @BEGIN\n");
        printf("7. DELETE @END\n");
        printf("8. DELETE @POSITION\n");
        printf("9. EXIT\n");
        printf("ENTER YOUR CHOICE [1-9]: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            create_list();
        }
        else if (ch == 2)
        {
            display_list();
        }
        else if (ch == 3)
        {
            insert_begin();
        }
        else if (ch == 4)
        {
            insert_end();
        }
        else if (ch == 5)
        {
            insert_position();
        }
        else if (ch == 6)
        {
            delete_begin();
        }
        else if (ch == 7)
        {
            delete_end();
        }
        else if (ch == 8)
        {
            delete_position();
        }
        else if (ch == 9)
        {
            printf("THE PROGRAM HAS BEEN TERMINATED!\n");
        }
        else
        {
            printf("INVALID CHOICE!\n");
        }
    } while (ch != 9);
    return 0;
}

void create_list()
{
    struct node *new_node;
    int i, n;

    printf("ENTER THE NUMBER OF NODES IN THE LIST: ");
    scanf("%d", &n);

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("MEMORY NOT ALLOCATED!\n");
        return;
    }

    printf("ENTER FIRST DATA: ");
    scanf("%d", &head->data);
    head->link = NULL;
    ptr = head;

    for (i = 1; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL)
        {
            printf("MEMORY NOT ALLOCATED!\n");
            return;
        }

        printf("ENTER DATA: ");
        scanf("%d", &new_node->data);
        new_node->link = NULL;
        ptr->link = new_node;
        ptr = new_node;
    }
}

void display_list()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY!\n");
        return;
    }

    ptr = head;
    printf("LINKED LIST: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

void insert_begin()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("MEMORY NOT ALLOCATED!\n");
        return;
    }

    printf("ENTER THE DATA TO BE INSERTED: ");
    scanf("%d", &new_node->data);
    new_node->link = head;
    head = new_node;
}

void insert_end()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("MEMORY NOT ALLOCATED!\n");
        return;
    }

    printf("ENTER THE DATA TO BE INSERTED: ");
    scanf("%d", &new_node->data);
    new_node->link = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new_node;
    }
}

void insert_position()
{
    int pos, i;
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("MEMORY NOT ALLOCATED!\n");
        return;
    }

    printf("ENTER THE POSITION TO INSERT: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_begin();
        return;
    }

    printf("ENTER THE DATA TO BE INSERTED: ");
    scanf("%d", &new_node->data);

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("POSITION NOT FOUND!\n");
    }
    else
    {
        new_node->link = temp->link;
        temp->link = new_node;
    }
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY!\n");
        return;
    }

    ptr = head;
    head = head->link;
    free(ptr);
}

void delete_end()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY!\n");
        return;
    }

    if (head->link == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    ptr = head;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }

    free(ptr->link);
    ptr->link = NULL;
}

void delete_position()
{
    int pos, i;
    struct node *temp, *del_node;

    printf("ENTER THE POSITION TO DELETE: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("LIST IS EMPTY!\n");
        return;
    }

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL || temp->link == NULL)
    {
        printf("POSITION NOT FOUND!\n");
    }
    else
    {
        del_node = temp->link;
        temp->link = del_node->link;
        free(del_node);
    }
}
