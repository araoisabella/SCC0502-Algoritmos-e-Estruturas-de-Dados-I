#ifndef PILHAOUFILA_H
#define PILHAOUFILA_H

#define MAX 101
#define ERRO -1
#define SEM_ERRO 0

typedef int TipoChave;

typedef struct {
    TipoChave chave;
} TipoItem;

typedef struct TipoNo {
    TipoItem item;
    struct TipoNo* prox;
} TipoNo;

typedef struct {
    TipoNo* ini;
    TipoNo* fim;
} TipoFila;

typedef struct {
    TipoNo* topo;
} TipoPilha;

void CriarPilha(TipoPilha* P);
int PilhaVazia(TipoPilha* P);
int push(TipoPilha* P, TipoItem I);
TipoChave pop(TipoPilha* P);
void reinicializarPilha(TipoPilha *P);


void CriarFila(TipoFila* F);
int FilaVazia(TipoFila* F);
int enfileirar(TipoFila* F, TipoItem I);
TipoChave desenfileirar(TipoFila* F);
void reinicializarFila(TipoFila *F);

#endif
