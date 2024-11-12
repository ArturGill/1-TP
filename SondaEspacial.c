#include <stdio.h>
#include <stdlib.h>
#include "SondaEspacial.h"
#define parteNulaSonda 0

void inicializaSonda(SondaMarte* sonda){
    int identificador;
    printf("Digite o codigo de identificacao da sonda:\n");
    scanf("%d", &identificador);
    setIdentificador(sonda, identificador);
    set_status(sonda, 0); //Apartir da struct Status já inicio a sonda como desligada 
    sonda->capacidadeSonda = parteNulaSonda;
    sonda->velSonda = parteNulaSonda;
    sonda->combustivelSonda = parteNulaSonda;
}
void ligaSonda(SondaMarte* sonda){
    set_status(sonda, 1);
}
void desligaSonda(SondaMarte* sonda){
    set_status(sonda, 0);
}


void setIdentificador(SondaMarte* sonda, int identificador){
    sonda->identificador = identificador;
}
void set_lat(SondaMarte* sonda, float lat){
    sonda->latSonda = lat;
}
void set_long(SondaMarte* sonda, float longS){
    sonda->longSonda = longS;
}
void setCompartimento(SondaMarte* sonda, int compartimento){
    sonda->compartimento = compartimento;
}
void set_status(SondaMarte* sonda, StatusSonda status){
    sonda->status = status;
}

void set_CapacidadeSonda(SondaMarte* sonda, int capacidadeSonda){
    sonda->capacidadeSonda = capacidadeSonda;
}
void set_VelSonda(SondaMarte* sonda, int vel){
    sonda->velSonda = vel;
}
void set_CombustivelSonda(SondaMarte* sonda, int combustivel){
    sonda->combustivelSonda = combustivel;
}
void moveSonda(SondaMarte* sonda){
    float lat;
    float longS;

    printf("Digite a nova Latitude:  \n");
    scanf("%f", &lat);
    printf("Digite a nova Longitude:  \n");
    scanf("%f", &longS);
    set_lat(sonda, lat);
    set_long(sonda, longS);
}

void imprimeSonda(SondaMarte sonda) {
    printf("Identificador: %d\n", sonda.identificador);
    printf("Latitude da Sonda: %f\n", sonda.latSonda);
    printf("Longitude da Sonda: %f\n", sonda.longSonda);
    printf("Compartimento: %d\n", sonda.compartimento);
    printf("Status da Sonda: ");
    switch (sonda.status) {
        case 0: printf("Desligada\n"); break;
        case 1: printf("Ligada\n"); break;
    }

    printf("Capacidade da Sonda: %d\n", sonda.capacidadeSonda);
    printf("Velocidade da Sonda: %d\n", sonda.velSonda);
    printf("Combustível da Sonda: %d\n", sonda.combustivelSonda);
}
