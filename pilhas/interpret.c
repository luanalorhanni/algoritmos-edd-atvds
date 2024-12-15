#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpret.h"
#include "stack.h"


static Stack* stack;

//interpreta e executa os comandos fornecidos pelo usuário.
void interpret(const char *source) {
    char op[10];
    int value;


    if (sscanf(source, "%s %d", op, &value) == 2) {
        if (strcmp(op, "push") == 0) {
            stack_push(stack, value);
            printf("Comando: PUSH %d\n", value);
        } else {
            printf("Comando inválido: %s\n", op);
        }
    }

    else if (sscanf(source, "%s", op) == 1) {
        if (strcmp(op, "add") == 0) {
            int a = stack_pop(stack);
            int b = stack_pop(stack);
            stack_push(stack, a + b);
            printf("Comando: ADD\n");
        } else if (strcmp(op, "sub") == 0) {
            int a = stack_pop(stack);
            int b = stack_pop(stack);
            stack_push(stack, a - b);
            printf("Comando: SUB\n");
        } else if (strcmp(op, "mul") == 0) {
            int a = stack_pop(stack);
            int b = stack_pop(stack);
            stack_push(stack, a * b);
            printf("Comando: MUL\n");
        } else if (strcmp(op, "div") == 0) {
            int a = stack_pop(stack);
            int b = stack_pop(stack);
            if (b == 0) {
                printf("Erro: Divisão por zero!\n");
                stack_push(stack, a);
                stack_push(stack, b);
            } else {
                stack_push(stack, a / b);
            }
            printf("Comando: DIV\n");
        } else if (strcmp(op, "print") == 0) {
            int value = stack_pop(stack);
            printf("Valor: %d\n", value);
        } else {
            printf("Comando inválido: %s\n", op);
        }
    }

    else {
        printf("Entrada inválida!\n");
    }

    //mostra o estado atual da pilha
    stack_print(stack);
}

//inicializa a pilha.
void init_stack(int size) {
    stack = new_stack(size);
}

//libera a pilha.
void free_stack_instance() {
    free_stack(stack);
}
