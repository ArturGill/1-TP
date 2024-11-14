#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "SondaEspacial.h"
#include "Rocha.h"

typedef TRocha TipoChave;

typedef struct 
{
    TipoChave *Chave;
} TItemRocha;

typedef struct CelulaRocha* ApontadorRocha;
typedef struct CelulaRocha
{
    TItemRocha Item;
    struct CelulaRocha* pProx;
} TCelulaRocha;

typedef struct 
{
    ApontadorRocha pPrimeiro;
    ApontadorRocha pUltimo;
} TLista;

int LTamanhoC(TLista* pLista);
void FLVaziaC(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsereC(TLista* pLista, TItemRocha* pItem, SondaMarte* sonda);
int LRetiraC(TLista* pLista, char *categoria);
void LImprime(TLista* pLista);
double PesoCompartimento(TLista* pLista);
void TrocarRocha(TLista* pLista, TItemRocha *Item);
int CapacidadeMax(TLista* plista, SondaMarte* sonda);

#endif