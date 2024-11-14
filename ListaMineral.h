#ifndef LISTAMINERAL_H
#define LISTAMINERAL_H

#define InicioArranjo 0
#define MaxTam 5

#include "Mineral.h"

typedef TMineral TchaveM;
typedef int ApontadorMineral;

typedef struct 
{
    TchaveM Chave;
} TItemMineral;

typedef struct 
{
    TItemMineral ItemM[MaxTam];
    ApontadorMineral Primeiro, Ultimo;
} TListaMineral;

void FLVaziaM(TListaMineral* pLista);
int LEhVaziaM(TListaMineral* pLista);
int LInsereM(TListaMineral* pLista, TMineral x);
int LRetiraMnome(TListaMineral* pLista, char *nomeM, TItemMineral *pX);
void LimprimeM(TListaMineral* pLista);
void PListaMinerais(TListaMineral* pLista, TMineral* mineral);
int TMListaM(TListaMineral *pLista);

#endif