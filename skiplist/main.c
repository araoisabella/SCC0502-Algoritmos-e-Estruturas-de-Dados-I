#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "skiplist.h"

int main()
{
    TipoSkiplist *lista_contatinhos = CriarSkiplist();

    char operacao, nome[MAX_NOME], telefone[MAX_TELEFONE];

    do
    {
        scanf(" %c", &operacao);

        if (operacao == 'I')
        {

            scanf("%s %s", nome, telefone);
            Insercao(lista_contatinhos, nome, telefone);
        }
        else if (operacao == 'P')
        {

            scanf("%s", nome);
            TipoNo *contatinho = Procura(lista_contatinhos, nome);
            if (contatinho)
            {
                printf("Contatinho encontrado: telefone %s\n", contatinho->telefone);
            }
            else
            {
                printf("Contatinho nao encontrado\n");
            }
        }
        else if (operacao == 'A')
        {

            scanf("%s %s", nome, telefone);
            AtualizarContatinho(lista_contatinhos, nome, telefone);
        }
        else if (operacao == 'R')
        {

            scanf("%s", nome);
            Remocao(lista_contatinhos, nome);
        }

    } while (operacao != '0');

    ReinicializarSkiplist(lista_contatinhos);

    return 0;
}
