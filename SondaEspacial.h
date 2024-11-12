#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H

typedef enum{
    LIGADA = 1,
    DESLIGADA = 0
} StatusSonda;

typedef struct {
    int identificador;
    float latSonda;
    float longSonda;
    int compartimento;
    StatusSonda status; //perguntar se os nomes do especificados no TP tem que ser os mesmos

    int capacidadeSonda;
    int velSonda;
    int combustivelSonda;
} SondaMarte;

void inicializaSonda(SondaMarte* sonda); 
void imprimeSonda(SondaMarte sonda);
void ligaSonda(SondaMarte* sonda);
void desligaSonda(SondaMarte* sonda);
void moveSonda(SondaMarte* sonda);


void setIdentificador(SondaMarte* sonda, int identificador);
void set_long(SondaMarte* sonda, float latSonda);
void set_long(SondaMarte* sonda, float longSonda);
void set_compartimento(SondaMarte* sonda, int compartimento);
void set_status(SondaMarte* sonda, StatusSonda status);


void set_CapacidadeSonda(SondaMarte* sonda, int capacidadeSonda);
void set_VelSonda(SondaMarte* sonda, int vel);
void set_CombustivelSonda(SondaMarte* sonda, int combustivel);



#endif // SONDAESPACIAL_H
