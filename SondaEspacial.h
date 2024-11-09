#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H

typedef struct {
    char latlong[30];
    int capacidadeSonda;
    int velSonda;
    int combustivelSonda;
} SondaMarte;

void set_Latlong(SondaMarte* sonda, char latlong, int velSonda, int combustivelSonda);
void set_CapacidadeSonda(SondaMarte* sonda, int capacidadeSonda);
void set_VelSonda(SondaMarte* sonda, int vel);
void set_CombustivelSonda(SondaMarte* sonda, int combustivel);
void inicializaSonda(SondaMarte* sonda, char latlong, int capacidadeSonda);

#endif // SONDAESPACIAL_H