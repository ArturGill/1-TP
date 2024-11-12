
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Rocha.h"
#include "ListaMineral.h"

void iniciarRocha(TRocha *rocha, int identificador,double peso,char localizacao,int data) {

    set_identificador(rocha, identificador) 
    set_localizacao(rocha, localizacao) 
    set_peso(rocha, peso) 
    set_data(rocha, data) 
} 

double get_peso(TRocha *rocha) {
    return rocha->peso
}

int get_data(TRocha *rocha) {
 return rocha->data
}

char get_localizacao(TRocha *rocha) {
 return rocha->localizacao
}

const char* classificar(TRocha *rocha, char categoria) {

    const char *Ferrom[]= {'Ferrolita'};
    const char *Solaris[] = {'Solarium'};
    const char *Aquaferro[] = {'Ferrolita','Aquavitae'};
    const char *Terrolis[]= {'Terranita','Calaris'};
    const char *Terrasol[]= {'Terranita, Solarium'};
    const char *Aquaterra[]= {'Aquavitae, Terranita'};
    const char *Calquer[] = {'Calaris', 'Aquavitae'};
    const char *Solarisfer[]= {'Solarium','Ferrolita'};
    const char *Terralis[]= {'Terranita','Ferrolita'};
    const char *Aquacalis[]= {'Aquavitae','Calaris','Ferrolita'};

    for (int i=0; i < 5 ; i++){
        if('Ferrom' == lista_mineral){
            return (rocha->categoria = "Ferrom");
        }
        else if(Solaris == lista_mineral){
            return rocha->categoria = "Solaris";
        }
        if(Aquaferro == lista_mineral){
            return rocha->categoria = "Aquaferro";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
        if(Ferrom == lista_mineral){
            return rocha->categoria = "Ferrom";
        }
    }
}
