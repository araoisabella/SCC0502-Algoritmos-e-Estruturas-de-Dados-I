#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "skiplist.h"

TipoSkiplist *CriarSkiplist()
{
    TipoSkiplist *lista = (TipoSkiplist *)malloc(sizeof(TipoSkiplist));
    lista->cabeca = (TipoNo *)malloc(sizeof(TipoNo));
    lista->nivel = 0;

    for (int i = 0; i < MAX_NIVEL; i++)
    {
        lista->cabeca->prox_nivel[i] = NULL;
    }

    srand(time(NULL));

    return lista;
}

TipoNo *CriarNo(char *nome, char *telefone, int nivel)
{
    TipoNo *no = (TipoNo *)malloc(sizeof(TipoNo));

    strncpy(no->nome, nome, sizeof(no->nome) - 1);
    strncpy(no->telefone, telefone, sizeof(no->telefone) - 1);

    for (int i = 0; i < nivel; i++)
    {
        no->prox_nivel[i] = NULL;
    }

    return no;
}

int NivelAleatorio()
{
    return (rand() % MAX_NIVEL) + 1;
}

void Insercao(TipoSkiplist *lista, char *nome, char *telefone)
{
    if (lista == NULL)
    {
        printf("Skiplist vazia\n");
        CriarSkiplist();
    }

    TipoNo *atualizar[MAX_NIVEL];
    TipoNo *c_atual = lista->cabeca;

    for (int i = lista->nivel - 1; i >= 0; i--)
    {
        while (c_atual->prox_nivel[i] != NULL && strcmp(c_atual->prox_nivel[i]->nome, nome) < 0)
        {
            c_atual = c_atual->prox_nivel[i];
        }
        atualizar[i] = c_atual;
    }

    c_atual = c_atual->prox_nivel[0];

    if (c_atual == NULL || strcmp(c_atual->nome, nome) != 0)
    {
        int novo_nivel = NivelAleatorio();

        if (novo_nivel > lista->nivel)
        {
            for (int i = lista->nivel; i < novo_nivel; i++)
            {
                atualizar[i] = lista->cabeca;
            }
            lista->nivel = novo_nivel;
        }

        TipoNo *novo_no = CriarNo(nome, telefone, novo_nivel);

        for (int i = 0; i < novo_nivel; i++)
        {
            novo_no->prox_nivel[i] = atualizar[i]->prox_nivel[i];
            atualizar[i]->prox_nivel[i] = novo_no;
        }
    }
    else
    {
        printf("Contatinho ja inserido\n");
    }
}

TipoNo *Procura(TipoSkiplist *lista, char *nome)
{
    TipoNo *c_atual = lista->cabeca;
    for (int i = lista->nivel - 1; i >= 0; i--)
    {
        while (c_atual->prox_nivel[i] != NULL && strcmp(c_atual->prox_nivel[i]->nome, nome) < 0)
        {
            c_atual = c_atual->prox_nivel[i];
        }
    }

    c_atual = c_atual->prox_nivel[0];

    if (c_atual != NULL && strcmp(c_atual->nome, nome) == 0)
    {
        return c_atual;
    }

    return NULL;
}

void Remocao(TipoSkiplist *lista, char *nome)
{
    TipoNo *atualizar[MAX_NIVEL];
    TipoNo *c_atual = lista->cabeca;

    if (lista == NULL)
    {
        printf("Nao tem contatinhos aqui\n");
        return;
    }

    for (int i = lista->nivel - 1; i >= 0; i--)
    {
        while (c_atual->prox_nivel[i] != NULL && strcmp(c_atual->prox_nivel[i]->nome, nome) < 0)
        {
            c_atual = c_atual->prox_nivel[i];
        }
        atualizar[i] = c_atual;
    }

    c_atual = c_atual->prox_nivel[0];

    if (c_atual != NULL && strcmp(c_atual->nome, nome) == 0)
    {
        for (int i = 0; i < lista->nivel; i++)
        {
            if (atualizar[i]->prox_nivel[i] != c_atual)
            {
                break;
            }
            atualizar[i]->prox_nivel[i] = c_atual->prox_nivel[i];
        }
        free(c_atual);
    }
    else
    {
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
}

void AtualizarContatinho(TipoSkiplist *lista, char *nome, char *novo_tel)
{
    TipoNo *contatinho = Procura(lista, nome);
    if (contatinho != NULL)
    {
        strcpy(contatinho->telefone, novo_tel);
    }
    else
    {
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
}

void ReinicializarSkiplist(TipoSkiplist *lista)
{
    TipoNo *c_atual = lista->cabeca->prox_nivel[0];

    while (c_atual != NULL)
    {
        TipoNo *aux = c_atual;
        c_atual = c_atual->prox_nivel[0];
        free(aux);
    }

    free(lista->cabeca);
    free(lista);
}