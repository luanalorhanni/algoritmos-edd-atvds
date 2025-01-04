#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
    int *data;
    int top;
    int size;
};

Stack* new_stack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
    return s;
}

void stack_push(Stack* s, int value) {
    if (s->top == s->size - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    s->data[++s->top] = value;
}

int stack_pop(Stack* s) {
    if (s->top == -1) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    return s->data[s->top--];
}

void stack_print(Stack* s) {
    if (s->top == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Estado atual da pilha:\n");

    for (int i = s->top; i >= 0; i--) { // Imprime de cima para baixo
        printf("%d\n", s->data[i]);
        printf("------------------------------\n"); // Linha separadora
    }

}

void free_stack(Stack* s) {
    free(s->data);
    free(s);
}
