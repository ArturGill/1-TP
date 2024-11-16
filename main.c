#include "ListaSondas.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    TListaMineral lista;
    TMineral mineral;
    FLVaziaM(&lista);
    preenche_mineral(&mineral, "Ferrolita", 0.5, 0.7, "Cinza");


    printf("fsf\n");
    
    LInsereM(&lista, mineral);
    

    char teste[25];

    strcpy(teste, classificar(&lista));

    printf("Resultado da classificacao: %s\n", &teste);
    int a = TMListaM(&lista);
    printf("%d", a);

    return 0;
}