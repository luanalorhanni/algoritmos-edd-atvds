#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct variable {
    char name[50];         //nome da vari�vel
    int value;             //valor da vari�vel
    struct variable* next; //pr�ximo n� na lista encadeada
} Variable;

//fun��es para gerenciar as vari�veis
Variable* find_variable(const char* name);
void set_variable(const char* name, int value);
int get_variable(const char* name);

void free_variables(); //liberar a mem�ria da lista de vari�veis

#endif
