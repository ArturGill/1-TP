#include "Mineral.h"
#include <stdio.h>
#include <stdlib.h>

void preenche_mineral(TMineral* mineral, char nomeM, int dureza, int reatividade, char cor) {
    set_nomeM
}

char get_nomeM(TMineral* mineral) {
    return mineral->nomeM;
}

int get_dureza(TMineral* mineral) {
    return mineral->dureza;
}

int get_reatividade(TMineral* mineral) {
    return mineral->reatividade;
}

char get_cor(TMineral* mineral) {
    return mineral->cor;
}

void set_nomeM(TMineral* mineral, char *nomeM) {
    strcpy(mineral->nomeM, nomeM);
}

void set_dureza(TMineral* mineral, int dureza) {
    mineral->dureza = dureza;
}

void set_reatividade(TMineral* mineral, int reatividade) {
    mineral->reatividade = reatividade;
}

void set_cor(TMineral* mineral, char *cor) {
    strcpy(mineral->cor, cor);
}