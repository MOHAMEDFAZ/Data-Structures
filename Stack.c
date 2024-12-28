#include <stdio.h>

// functions
void Create();
void Push();
void Pop();
void Display();
void Peek();
void isFull();
void isEmpty();

// global variables
int maxsize = 10;
int n;
int top = -1;
int stack[10];

// main functions
int main()
{
    int ch;
    do
    {
        printf("\n------------[STACK-OPERATIONS]------------");
        printf("\n1.CREATE()\n2.PUSH()\n3.POP()\n4.DISPLAY\n5.PEEK()\n6.isEmpty()\n7.isFull()\n8.EXIT");
        printf("\nENTER YOUR CHOICE [1-8]: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            Create();
        }
        else if (ch == 2)
        {
            Push();
        }
        else if (ch == 3)
        {
            Pop();
        }
        else if (ch == 4)
        {
            Display();
        }
        else if (ch == 5)
        {
            Peek();
        }
        else if (ch == 6)
        {
            isEmpty();
        }
        else if (ch == 7)
        {
            isFull();
        }
        else if (ch > 8)
        {
            printf("ENTER A VALID INPUT !");
        }
    } while (ch != 8);
    return 0;
}

void Create()
{
    printf("ENTER THE STACK SIZE [MAXSIZE = 10]: ");
    scanf("%d", &n);
    if (n > maxsize)
    {
        printf("STACK SIZE EXCEEDS MAXIMUM SIZE OF 10.\n");
        return;
    }
    printf("ENTER THE STACK ELEMENTS: ");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        stack[++top] = e;
    }
    printf("STACK CREATED!\n");
}

void Push()
{
    if (top == maxsize - 1)
    {
        printf("STACK OVERFLOW!\n");
        return;
    }
    int e;
    printf("ENTER THE ELEMENT: ");
    scanf("%d", &e);
    stack[++top] = e;
    printf("ELEMENT INSERTED!\n");
}

void Pop()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW!\n");
        return;
    }
    printf("%d IS THE TOP ELEMENT. IT HAS BEEN POPPED FROM STACK\n", stack[top--]);
}

void Display()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY!\n");
        return;
    }
    printf("\nTHE CURRENT STACK IS:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void isFull()
{
    if (top == maxsize - 1)
    {
        printf("STACK IS FULL!\n");
    }
    else
    {
        printf("STACK IS NOT FULL!\n");
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY!\n");
    }
    else
    {
        printf("STACK IS NOT EMPTY!\n");
    }
}

void Peek()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY!\n");
    }
    else
    {
        printf("THE TOP ELEMENT IS %d\n", stack[top]);
    }
}
