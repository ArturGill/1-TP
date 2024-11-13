#ifndef ROCHA_H
#define ROCHA_H

#include "ListaMineral.h"

typedef struct
{
    int identificador;
    char categoria[50];
    TListaMineral lista_mineral;
    double peso;
    char localizacao[50];
    int data;
} TRocha;

void iniciarRocha(TRocha *rocha, int identificador,double peso, char localizacao,int data);
double get_peso(TRocha *rocha);
int get_data(TRocha *rocha);
char *get_localizacao(TRocha *rocha);
void set_identificador(TRocha *rocha, int indentificador);
void set_localizacao(TRocha *rocha, char localizacao);
void set_peso(TRocha *rocha, double peso);
void set_data(TRocha *rocha, int data);
const char* classificar(TRocha *rocha, char categoria);

#endif // ROCHA_H
