#include "ListaSondas.h"
#include "SondaEspacial.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){

    SondaMarte sonda1;
    listaSonda sondasL;
    iniciaListaSonda(&sondasL);

    FILE *arq = NULL;
    arq = fopen("testerocha.txt", "r");
    if(arq == NULL){
        printf("falha leitura");
        exit(0);
    }
    int N_Sondas; 
    float lat_i,lon_i,c_i,v_i,nc_i;
    fscanf(arq, "%d", &N_Sondas);

    for(int i = 0; i<N_Sondas;i++){
        fscanf(arq,"%f %f %f %f %f", &lat_i,&lon_i,&c_i,&v_i,&nc_i);
        insereSonda(&sondasL, inicializaSondaTexto(&sonda1,lat_i,lon_i,c_i,v_i,nc_i));
    }
    
    ImprimeListaSondas(&sondasL);
    
    TMineral x;
    TListaMineral lista;

    FLVaziaM(&lista);
    PListaMinerais(&lista, &x);

    LimprimeM(&lista);

    return 0;
}