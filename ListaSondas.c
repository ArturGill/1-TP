#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSondas.h"

void iniciaListaSonda(listaSonda* pLista){ // com cabeça inicia com celula chave.
    pLista->primaSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->primaSonda;
    pLista->primaSonda->pProxSonda = NULL;
}
void insereSonda(listaSonda* pLista, SondaMarte xSonda){
    pLista->ultSonda->pProxSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->ultSonda->pProxSonda;
    pLista->ultSonda->chaveSonda = xSonda;
    pLista->ultSonda->pProxSonda = NULL;

}
void retiraSonda(listaSonda* plista){
    int idRetira;
    celulaSonda* atual = plista->primaSonda;
    celulaSonda* anterior = NULL;

    printf("Digite o ID da sonda para ser retirada: ");
    scanf("%d", &idRetira);

    while (atual != NULL && atual->chaveSonda.identificadorSonda != idRetira)
    {
        anterior = atual;
        atual = atual->pProxSonda;
    }
     if (atual == NULL) { //Olha se a sonda existe mesmo, se não, retorna uma mensagem
        printf("Sonda não existe com esse ID: %d\n", idRetira);
        return;// encerra codigo
    } 
    if(anterior == NULL){
        plista->primaSonda = atual->pProxSonda; //remove primeira
    } else {
        anterior->pProxSonda = atual->pProxSonda; // remove meio ou fim
    }
    free(atual);
    printf("Sonda Removida :)\n");
}

void ImprimeListaSondas(listaSonda* plista){

    celulaSonda* atual = plista->primaSonda->pProxSonda;

    while(atual != NULL){

        imprimeSonda(atual->chaveSonda);
        atual = atual->pProxSonda;
    }
}

SondaMarte* dist_euclidiana(listaSonda* plista, float lat_R, float long_R){ //colocar na .h
    celulaSonda* atual = plista->primaSonda->pProxSonda;
    float menorDist = 1000000;
    float lat_S;
    float lon_S;
    float distAtual = 0;
    SondaMarte* sondaproxima;

    while(atual != NULL){
        lat_S = atual->chaveSonda.latSonda;
        lon_S = atual->chaveSonda.longSonda;
        distAtual = sqrt(pow(lat_R - lat_S, 2) + pow(long_R - lon_S, 2));
        if (menorDist >= distAtual){
            menorDist = distAtual;
            sondaproxima = &atual->chaveSonda;
        }
        atual = atual->pProxSonda;
    }
    return sondaproxima;
}

void AdicionarRochaS(listaSonda *ListaSonda, TRocha *rocha) {
    SondaMarte *sondaAmz = NULL; // armazena uma possível sonda que irá coletar
    float lat_i = rocha->lat_rocha;
    float long_i = rocha->long_rocha;

    apontador pAux = ListaSonda->primaSonda->pProxSonda;
    SondaMarte *sonda = NULL;
    while (pAux != NULL) {
        sonda = &pAux->chaveSonda;
        float verificarcap = sonda->capacidadeSonda - rocha->peso;
// perguntar sobre o contemcategoria
        //verifica a capacidade
        if (verificarcap >= rocha->peso) {
            if (strcmp(pAux->chaveSonda.CompartimentoSonda.pPrimeiro->Item.Chave->categoria, rocha->categoria) == 0) {
                TrocarRocha(&ListaSonda->itemSonda.chaveSonda.CompartimentoSonda, rocha);
            }
            sondaAmz = dist_euclidiana(ListaSonda, lat_i, long_i);
        }
        pAux = pAux->pProxSonda;
    }
    if (sondaAmz == NULL) {
        printf("ERRO! Nao tem sonda perto\n");
        return;
    }
    sondaAmz->latSonda = rocha->lat_rocha;
    sondaAmz->longSonda = rocha->long_rocha; // a sonda vai até o local onde está a rocha
    
    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pPrimeiro = (TCelulaRocha*)malloc(sizeof(TCelulaRocha));
        sondaAmz->CompartimentoSonda.pPrimeiro->pProx = NULL;
        sondaAmz->CompartimentoSonda.pUltimo = sondaAmz->CompartimentoSonda.pPrimeiro;
    }
    TCelulaRocha *novarocha = (TCelulaRocha*) malloc(sizeof(TCelulaRocha));
    novarocha->Item.Chave = rocha;
    novarocha->pProx = NULL;

    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pPrimeiro = novarocha;
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    } 
    else {
        sondaAmz->CompartimentoSonda.pUltimo->pProx = novarocha;
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    }
    sonda->capacidadeSonda -= rocha->peso;
    
    printf("--------------------------------\n");
    printf("Rocha coletada\nSonda: %d\n", sondaAmz->identificadorSonda);
    
}

void pontoComumSondas(listaSonda* sondasLista){ // colocar no .h
    celulaSonda* atual = sondasLista->primaSonda->pProxSonda;
    while(atual != NULL){
        atual->chaveSonda.latSonda = 0;
        atual->chaveSonda.longSonda = 0;
        atual = atual->pProxSonda;
    }
}

void redistribuiPeso(listaSonda* sondasLista){
    celulaSonda* atual = sondasLista->primaSonda->pProxSonda;
    float somaPesos = 0;
    int contador = 0;
    double pesoIndv;
    while(atual != NULL){
        atual->chaveSonda.pesoAtual = PesoCompartimento(&atual->chaveSonda.CompartimentoSonda);
        contador++;
        atual = atual->pProxSonda;
    }
    float pesoMedio = somaPesos/contador;

    atual = sondasLista->primaSonda->pProxSonda;
    while(atual != NULL){
        atual->chaveSonda.pesoAtual = pesoMedio;
        atual = atual->pProxSonda;
    }
}