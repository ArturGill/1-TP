#include "ListaMineral.h"
#include <stdio.h>

void FLVazia(TListaMineral* pLista) {
    pLista->Primeiro = InicioArranjo;
    pLista->Ultimo = pLista->Primeiro;
}

int LEhVazia(TListaMineral* pLista) {
    return pLista->Ultimo == pLista->Primeiro;
}

int LInsere(TListaMineral* pLista, TMineral x) {
    if (pLista->Ultimo == MaxTam) {
        return 0;
    }
    pLista->Item[pLista->Ultimo++].Chave = x;
    return 1;
}

int LRetiraMnome(TListaMineral* pLista, char *nomeM, TItem *pX) {
    int cont;
    
    if (LEhVazia(pLista)) {
        return 0;
    }
    for (cont = pLista->Primeiro; cont <= pLista->Ultimo; cont++) {
        if (nomeM == pLista->Item[cont].Chave.nomeM) {
            *pX = pLista->Item[cont];
            for (cont + 1; cont < pLista->Ultimo; cont++) {
                pLista->Item[cont - 1] = pLista->Item[cont];
            }
            pLista->Ultimo--;
        }
    }
    return 1;
}

void Limprime(TListaMineral* pLista) {
    int i;
    for (i = pLista->Primeiro; i < pLista->Ultimo; i++) {
         printf("Nome: %s, Dureza: %.2f, Reatividade: %.2f, Cor: %s\n",
               pLista->Item[i].Chave.nomeM,
               pLista->Item[i].Chave.dureza,
               pLista->Item[i].Chave.reatividade,
               pLista->Item[i].Chave.cor);
    }
}

void PListaMinerais(TListaMineral* pLista, TMineral* mineral) {
    FLVazia(pLista);

    TMineral Ferrolita = preenche_mineral(mineral, "Ferrolita", 0.5, 0.7, "Cinza");
    TMineral Solarium = preenche_mineral(mineral, "Solarium", 0.9, 0.2, "Amarelo");
    TMineral Aquavitae = preenche_mineral(mineral, "Aquavitae", 0.5, 0.8, "Azul");
    TMineral Terranita = preenche_mineral(mineral, "Terranita", 0.7, 0.6, "Marrom");
    TMineral Calaris = preenche_mineral(mineral, "Calaris", 0.6, 0.5, "Vermelho");

    LInsere(pLista, Ferrolita);
    LInsere(pLista, Solarium);
    LInsere(pLista, Aquavitae);
    LInsere(pLista, Terranita);
    LInsere(pLista, Calaris);
}