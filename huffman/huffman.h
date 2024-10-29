#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef unsigned char byte;

typedef struct nodeArvore
{
    int                 frequencia;
    byte                c;
    struct nodeArvore   *esquerda;
    struct nodeArvore   *direita;
} nodeArvore;

typedef struct nodeLista
{
    nodeArvore          *n;
    struct nodeLista    *proximo;
} nodeLista;

typedef struct lista
{
    nodeLista   *head;
    int         elementos;
} lista;

char *strdup(const char *s);
nodeLista *novoNodeLista(nodeArvore *nArv);
void insereLista(nodeLista *n, lista *l);
nodeArvore *popMinLista(lista *l);
void getByteFrequency(FILE *entrada, unsigned int *listaBytes);
bool pegaCodigo(nodeArvore *n, byte c, char *buffer, int tamanho);
nodeArvore *BuildHuffmanTree(unsigned *listaBytes);
void FreeHuffmanTree(nodeArvore *n);
int geraBit(FILE *entrada, int posicao, byte *aux);
void erroArquivo();
void CompressFile(const char *arquivoEntrada, const char *arquivoSaida);
void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida);


#endif
