#include "Compartimento.h"
#include "SondaEspacial.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LTamanhoC(TLista *pLista)
{
    int cont = 0;
    TCelulaRocha *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        cont++;
    }
    return cont;
}

void FLVaziaC(TLista *pLista)
{
    pLista->pPrimeiro = (ApontadorRocha)malloc(sizeof(TCelulaRocha));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

int LEhVaziaC(TLista *pLista)
{
    return pLista->pPrimeiro == pLista->pUltimo;
}

int LInsereC(TLista *pLista, TItemRocha *pItem, SondaMarte *sonda)
{
    int peso = CapacidadeMax(pLista, sonda);
    if (peso == 1)
    {
        ApontadorRocha pAux = pLista->pPrimeiro->pProx;

        while (pAux != NULL)
        {
            if (strcmp(pAux->Item.Chave->categoria, pItem->Chave->categoria) == 0)
            {
                TrocarRocha(pLista, pItem);
                return 1;
            }
            pAux = pAux->pProx;
        }

        pLista->pUltimo->pProx = (ApontadorRocha)malloc(sizeof(TCelulaRocha));
        pLista->pUltimo = pLista->pUltimo->pProx;
        pLista->pUltimo->Item = *pItem;
        pLista->pUltimo->pProx = NULL;
        return 1;
    }
    else {
        printf("Capacidade maxima!\n");
        return 0;
    }
}

int LRetiraC(TLista *pLista, char *categoria)
{
    if (LEhVaziaC(pLista))
    {
        return 0;
    }
    TCelulaRocha *aux1 = pLista->pPrimeiro;
    TCelulaRocha *aux2 = NULL;

    while (aux1 != NULL && strcmp(aux1->Item.Chave->categoria, categoria) != 0)
    {
        aux2 = aux1;
        aux1 = aux1->pProx;
    }
    if (aux2 == NULL)
    {
        pLista->pPrimeiro = aux1->pProx;
    }
    aux2 = aux1->pProx;

    free(aux1);
    return 1;
}

void LImprimeC(TLista *pLista)
{
    ApontadorRocha pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("%d\n", pAux->Item.Chave);
        pAux = pAux->pProx; // próxima célula
    }
    if (pAux == pLista->pPrimeiro->pProx)
    {
        printf("A lista é vazia\n");
    }
}

void TrocarRocha(TLista *pLista, TItemRocha *Item)
{
    ApontadorRocha att = pLista->pPrimeiro->pProx;
    while (att != NULL)
    {
        if (strcmp(att->Item.Chave->categoria, Item->Chave->categoria) == 0 && att->Item.Chave->peso < Item->Chave->peso)
        {
            att->Item = *Item;
        }
        att = att->pProx;
    }
}

int CapacidadeMax(TLista *plista, SondaMarte *sonda)
{
    float pesototal = PesoCompartimento(plista);
    if (pesototal <= sonda->capacidadeSonda)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double PesoCompartimento(TLista *pLista)
{
    double PesoT = 0.0;
    ApontadorRocha att = pLista->pPrimeiro->pProx;
    while (att != NULL)
    {
        PesoT += att->Item.Chave->peso;
        att = att->pProx;
    }
    return PesoT;
}