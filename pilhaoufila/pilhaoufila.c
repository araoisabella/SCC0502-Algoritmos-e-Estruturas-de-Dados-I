#include <stdio.h>
#include <stdlib.h>
#include "pilhaoufila.h"

void CriarPilha(TipoPilha* P) {
    P->topo = NULL;
}

int PilhaVazia(TipoPilha* P) {
    return P->topo == NULL;
}

int push(TipoPilha* P, TipoItem I) {
    TipoNo* p = (TipoNo*)malloc(sizeof(TipoNo));

    if (p == NULL) {
        printf("Erro: Não foi possível alocar memória para a pilha.\n");
        return ERRO;
    }

    p->item = I;

    if (PilhaVazia(P)) {
        p->prox = NULL;
        P->topo = p;
    } else {
        p->prox = P->topo;
        P->topo = p;
    }
    return SEM_ERRO;
}

TipoChave pop(TipoPilha* P) {
    if (PilhaVazia(P)) {
        printf("Erro: Pilha está vazia.\n");
        return ERRO;
    }

    TipoNo* p = P->topo;
    TipoChave chave = p->item.chave;
    P->topo = P->topo->prox;
    free(p);

    return chave;
}

void CriarFila(TipoFila* F) {
    F->ini = NULL;
    F->fim = NULL;
}

int FilaVazia(TipoFila* F) {
    return F->ini == NULL;
}

int enfileirar(TipoFila* F, TipoItem I) {
    TipoNo* p = (TipoNo*)malloc(sizeof(TipoNo));
    if (p == NULL) {
        printf("Erro: Não foi possível alocar memória para a fila.\n");
        return ERRO;
    }

    p->item = I;
    p->prox = NULL;

    if (FilaVazia(F)) {
        F->ini = p;
    } else {
        F->fim->prox = p;
    }

    F->fim = p;
    return SEM_ERRO;
}

TipoChave desenfileirar(TipoFila* F) {
    if (FilaVazia(F)) {
        printf("Erro: Fila está vazia.\n");
        return ERRO;
    }

    TipoNo* p = F->ini;
    TipoChave chave = p->item.chave;
    F->ini = F->ini->prox;
    free(p);

    if (F->ini == NULL) {
        F->fim = NULL;
    }

    return chave;
}

void reinicializarFila(TipoFila* F) {
    while (FilaVazia(F) == 0) {
        TipoNo* aux = F->ini;
        F->ini = F->ini->prox;
        free(aux);
    }

    F->fim = NULL;
}

void reinicializarPilha(TipoPilha* P) {
    while (PilhaVazia(P) == 0) {
        TipoNo* aux = P->topo;
        P->topo = P->topo->prox;
        free(aux);
    }
}

