#include <stdio.h>
#include <stdlib.h>
#include "pilhaoufila.h"


int main() {
    int n;
    scanf("%d", &n);

    TipoPilha pilha;
    TipoFila fila;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        CriarPilha(&pilha);
        CriarFila(&fila);

        int Pila = 1;
        int Filha = 1;

        for (int j = 0; j < k; j++) {
            char op;
            int val;
            scanf(" %c %d", &op, &val);

            if (op == 'i') {
                TipoItem item;
                item.chave = val;
                push(&pilha, item);
                enfileirar(&fila, item);
            } else if (op == 'r') {
                TipoChave chave_pilha = pop(&pilha);
                TipoChave chave_fila = desenfileirar(&fila);

                if (chave_pilha != val) {
                    Pila = 0;
                }

                if (chave_fila != val) {
                    Filha = 0;
                }
            }
        }

        if (Pila && !Filha) {
            printf("pilha\n");
        } else if (!Pila && Filha) {
            printf("fila\n");
        } else if (!Pila && !Filha) {
            printf("impossivel\n");
        } else {
            printf("indefinido\n");
        }
    }

    reinicializarPilha(&pilha);
    reinicializarFila(&fila);
    return 0;
}
