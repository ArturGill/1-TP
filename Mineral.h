#ifndef MINERAL_H
#define MINERAL_H

typedef struct 
{
    char nomeM[50], cor[50];
    int dureza, reatividade;
} TMineral;

void preenche_mineral(TMineral* mineral, char nomeM, int dureza, int reatividade, char cor);

char get_nomeM(TMineral* mineral);
int get_dureza(TMineral* mineral);
int get_reatividade(TMineral* mineral);
char get_cor(TMineral* mineral);

void set_nomeM(TMineral* mineral, char nomeM);
void set_dureza(TMineral* mineral, int dureza);
void set_reatividade(TMineral* mineral, int reatividade);
void set_cor(TMineral* mineral, char cor);

#endif // MINERAL_H