#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "variables.h"

//cabe�a da lista de vari�veis
static Variable* head = NULL;

//buscar variavel pelo nome
Variable* find_variable(const char* name) {
    Variable* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//atualiza o valor de uma vari�vel
void set_variable(const char* name, int value) {
    Variable* var = find_variable(name);
    if (var) {
        var->value = value; // Atualiza o valor se j� existe
    } else {
        // Cria um novo n� se a vari�vel n�o existe
        Variable* new_var = (Variable*)malloc(sizeof(Variable));
        strcpy(new_var->name, name);
        new_var->value = value;
        new_var->next = head;
        head = new_var;
    }
}

int get_variable(const char* name) {
    Variable* var = find_variable(name);
    if (var) {
        return var->value;
    } else {
        printf("Erro: Vari�vel '%s' n�o encontrada!\n", name);
        return 0;
    }
}

void free_variables() {
    Variable* current = head;
    while (current != NULL) {
        Variable* next = current->next;
        free(current);
        current = next;
    }
}
