#ifndef LISTAMINERAL_H
#define LISTAMINERAL_H

#define InicioArranjo 0
#define MaxTam 5

#include "Mineral.h"

typedef TMineral Tchave;
typedef int Apontador;

typedef struct 
{
    Tchave Chave;
} TItem;

typedef struct 
{
    TItem Item[MaxTam];
    Apontador Primeiro, Ultimo;
} TListaMineral;

void FLVazia(TListaMineral* pLista);
int LEhVazia(TListaMineral* pLista);
int LInsere(TListaMineral* pLista, TMineral x);
int LRetiraMnome(TListaMineral* pLista, char *nomeM, TItem *pX);
void Limprime(TListaMineral* pLista);
void PListaMinerais(TListaMineral* pLista, TMineral* mineral);

#endif