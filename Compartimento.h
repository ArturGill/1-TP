#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "Rocha.h"

typedef TRocha TipoChave;

typedef struct 
{
    TipoChave Chave;
} TItem;

typedef struct Celula* Apontador;
typedef struct Celula
{
    TItem Item;
    struct Celula* pProx;
} TCelula;

typedef struct 
{
    Apontador pPrimeiro;
    Apontador pUltimo;
} TLista;

int LTamanho(TLista* pLista);
void FLVazia(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem* pItem);
int LRetira(TLista* pLista, TItem* pItem);
void LImprime(TLista* pLista);
float PesoCompartimento(TLista* pLista);
void TrocarRocha(TLista* pLista);

#endif

/*Criar: inicializa a lista vazia;
● Retornar tamanho, isto é, o número atual de rochas minerais no compartimento;
● Verificar se está vazia;
● Exibir: imprime o conteúdo do compartimento, sendo necessário indicar quando a lista
está vazia;
● Retornar peso atual do compartimento;
● Trocar rocha (Adiciona uma rocha mais leve no lugar da rocha mais pesada do mesmo
tipo)
● Inserir rocha: armazenar nova Rocha Mineral encontrada na localização dada seguindo
as regras que indicam que não poderão haver rochas repetidas e de acordo com o peso
máximo permitido;
● Remover rocha (Pela categoria);*/
