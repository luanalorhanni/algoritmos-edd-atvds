#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpret.h"
#include "stack.h"
#include "variables.h"

static Stack* stack;

void interpret(const char *source) {
    char op[10];
    char arg[50];
    int value;

    //comando com variável (ex.: "push var1")
    if (sscanf(source, "%s %s", op, arg) == 2) {
        if (strcmp(op, "push") == 0) {

            if (sscanf(arg, "%d", &value) == 1) {
                stack_push(stack, value);
                printf("Comando: PUSH %d\n", value);
            } else {
                value = get_variable(arg);
                stack_push(stack, value);
                printf("Comando: PUSH %s (valor: %d)\n", arg, value);
            }
        } else if (strcmp(op, "pop") == 0) {
            value = stack_pop(stack);
            set_variable(arg, value);
            printf("Comando: POP %s (valor: %d)\n", arg, value);
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
                printf("Comando: DIV\n");
            }
        } else if (strcmp(op, "print") == 0) {
            value = stack_pop(stack);
            printf("Valor: %d\n", value);
        } else {
            printf("Comando inválido: %s\n", op);
        }
    }

    else {
        printf("Entrada inválida!\n");
    }


    stack_print(stack);
}

//inicializa a pilha
void init_stack(int size) {
    stack = new_stack(size);
}

//libera a pilha e as variáveis
void free_stack_instance() {
    free_stack(stack);
    free_variables();
}
