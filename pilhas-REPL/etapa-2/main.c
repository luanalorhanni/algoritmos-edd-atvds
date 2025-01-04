#include <stdio.h>
#include "interpret.h"
#include "interpret.c"
#include "stack.h"
#include "stack.c"
#include "variables.h"
#include "variables.c"


static void repl() {
    char line[1024];
    for (;;) {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

int main() {
    init_stack(100); //inicializa a pilha com tamanho máximo de 100.

    repl();

    free_stack_instance(); //libera a memória alocada para a pilha.
    return 0;
}
