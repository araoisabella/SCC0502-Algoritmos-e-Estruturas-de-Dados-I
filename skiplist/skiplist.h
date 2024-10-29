#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAX_NOME 11
#define MAX_TELEFONE 10
#define MAX_NIVEL 5 // inserir, pesquisar, remover, alterar, sair

typedef struct TipoNo{
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    struct TipoNo *prox_nivel[MAX_NIVEL];
} TipoNo;

typedef struct TipoSkiplist{
    TipoNo *cabeca;
    int nivel;
} TipoSkiplist;

TipoSkiplist *CriarSkiplist();
TipoNo *CriarNo(char *nome, char *telefone, int nivel);
int NivelAleatorio();
void Insercao(TipoSkiplist *lista, char *nome, char *telefone);
TipoNo *Procura(TipoSkiplist *lista, char *nome);
void Remocao(TipoSkiplist *lista, char *nome);
void AtualizarContatinho(TipoSkiplist *lista, char *nome, char *novo_tel);
void ReinicializarSkiplist(TipoSkiplist *lista);

#endif