
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Rocha.h"
#include "ListaMineral.h"

void iniciarRocha(TRocha *rocha, int identificador,double peso,char localizacao,int data) {

    set_identificador(rocha, identificador);
    set_localizacao(rocha, localizacao);
    set_peso(rocha, peso);
    set_data(rocha, data);
} 

double get_peso(TRocha *rocha) {
    return rocha->peso;
}

int get_data(TRocha *rocha) {
 return rocha->data;
}

char* get_localizacao(TRocha *rocha) {
 return rocha->localizacao;
}

const char* classificar(TListaMineral *pLista, TRocha *rocha, char categoria) {

    FLVazia(pLista);
    PListaMinerais(&pLista, );

}

void set_identificador(TRocha *rocha, int indentificador) {
    rocha->identificador = indentificador;
}

void set_localizacao(TRocha *rocha, char localizacao) {
    strcpy(rocha->localizacao = localizacao);
}

void set_peso(TRocha *rocha, double peso) {
    rocha->peso = peso;
}

void set_data(TRocha *rocha, int data) {
    rocha->data = data;
}