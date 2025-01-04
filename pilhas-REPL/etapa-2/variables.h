#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct variable {
    char name[50];         //nome da variável
    int value;             //valor da variável
    struct variable* next; //próximo nó na lista encadeada
} Variable;

//funções para gerenciar as variáveis
Variable* find_variable(const char* name);
void set_variable(const char* name, int value);
int get_variable(const char* name);

void free_variables(); //liberar a memória da lista de variáveis

#endif
