#ifndef LISTASONDAS_H
#define LISTASONDAS_H
#include "SondaEspacial.h"


typedef SondaMarte Tsonda;
typedef struct Celula* apontador;

typedef struct Celula {
    Tsonda chaveSonda;
    struct Celula* pProxSonda;
}celulaSonda;

typedef struct{
    celulaSonda itemSonda;
    apontador primaSonda, ultSonda;
}listaSonda;

void iniciaListaSonda(listaSonda* pLista);
void insereSonda(listaSonda* plista, SondaMarte xSonda);
void retiraSonda(listaSonda* plista);
void ImprimeListaSondas(listaSonda* plista);
void quantidadeSondasTexto(listaSonda* sondasL,int N_sondas);
SondaMarte *dist_euclidiana(listaSonda* plista, float lat_R, float long_R);
void Operacao_R_Imprime(listaSonda* plista);
void AdicionarRochaS(listaSonda *sonda, TRocha *rocha);
void pontoComumSondas(listaSonda* sondasLista);
void redistribuiPeso(listaSonda* sondasLista);

#endif