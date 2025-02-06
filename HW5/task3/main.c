#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    int body[STACK_SIZE];
    int head;
} stack_t;

stack_t* stack_init()
{
    stack_t* stack = malloc(sizeof(stack_t));

    stack->head = -1;

    return stack;
}

void push(stack_t *stack, int num)
{
    if(stack->head == STACK_SIZE){
        printf("Stack is full");
        abort();
    }

    stack->body[++(stack->head)] = num;
}

int pop(stack_t *stack)
{
    if(stack->head == -1){
        printf("Stack is empty");
        abort();
    }

    return stack->body[(stack->head)--];
}

int count_RPN(char expr[])
{
    stack_t* stack = stack_init(&stack);

    char* token = strtok(expr, " ");
    while(token != NULL){
        if(!isdigit(token[0])){

            int b = pop(stack);
            int a = pop(stack);

            int c;
            switch (token[0]) {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = a / b;
                    break;
            }

            push(stack, c);
        }
        else{
            push(stack,atoi(token));
        }
        token = strtok(NULL, " ");
    }

    int value = pop(stack);
    free(stack);
    return value;
}

int main() {
    char expression[100000];

    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 2] = '\0';
    }

    int result = count_RPN(expression);
    printf("%d\n", result);

    return 0;
}
