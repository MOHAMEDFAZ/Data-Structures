#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int st[MAX], stTop = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            st[++stTop] = postfix[i] - '0';
        } else {
            int b = st[stTop--];
            int a = st[stTop--];
            switch (postfix[i]) {
                case '+': st[++stTop] = a + b; break;
                case '-': st[++stTop] = a - b; break;
                case '*': st[++stTop] = a * b; break;
                case '/': st[++stTop] = a / b; break;
                case '^': st[++stTop] = pow(a, b); break;
            }
        }
        i++;
    }
    return st[stTop];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
