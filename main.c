#include "ListaSondas.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char operacao;
    srand(time(NULL));
    SondaMarte sonda1;
    listaSonda sondasL;
    iniciaListaSonda(&sondasL);

    FILE *arq = NULL;
    arq = fopen("teste.txt", "r");
    if(arq == NULL){
        printf("falha leitura");
        exit(0);
    }
    int N_Sondas; 
    float lat_i,lon_i,c_i,v_i,nc_i;
    fscanf(arq, "%d", &N_Sondas);

    for(int i = 0; i<N_Sondas;i++){
        fscanf(arq,"%f %f %f %f %f", &lat_i,&lon_i,&c_i,&v_i,&nc_i);
        insereSonda(&sondasL, inicializaSondaTexto(&sonda1,lat_i,lon_i,c_i,v_i,nc_i));
    }
    int qntdOperacoes;
    fscanf(arq,"%d", &qntdOperacoes);

    // for(int i=0; i<qntdOperacoes; i++){
    //     printf("Selecione a operacao: (R, I, E)\n")/
    //     scanf(" %c", &operacao);
    //     TRocha novarocha;

    //     switch (operacao)
    //     {
    //     case 'R':
    //         printf("Digite a latitude, longitude, peso e minerais\n");
    //         float lat, long_i, peso;
    //         char minerais[100] = "ferrolita Ferrom";
    //         scanf("%f %f %f", &lat, &long_i, &peso);
            
    //         const char delim[2] = " ";
    //         char *parte;

    //         parte = strtok(minerais, delim);
    //         preenche_rocha(&novarocha, lat, long_i, peso, &novarocha.lista_mineral);

    //         while (parte != NULL) 
    //         {
    //             strcpy(novarocha.lista_mineral->ItemM->Chave.nomeM, parte);
    //             printf("%s\n", novarocha.lista_mineral->ItemM->Chave.nomeM);
    //             parte = strtok(NULL, delim); 
    //         }
            
            

    //         break;
    //     case 'E':

    //     pontoComumSondas(&sondasL);
        
        
        
    //     break;
    //     default:
    //         break;
    //     }
    // }

    for (int i = 0; i < qntdOperacoes; i++) {
        printf("Selecione a operacao: (R, I, E)\n");
        scanf(" %c", &operacao);
        TRocha novarocha;

        switch (operacao) {
            case 'R': {
                printf("Digite a latitude, longitude, peso e minerais\n");
                float lat, long_i, peso;
                char minerais[100];
                scanf("%f %f %f\n", &lat, &long_i, &peso);
                getchar();
                fgets(minerais, sizeof(minerais), stdin);
                // minerais[strcspn(minerais, "\n")] = '\0';

                // Inicializa a rocha

                // Quebra os minerais em partes e adiciona à lista
                const char delim[] = " ";
                char *parte = strtok(minerais, delim);
                int i = 0
                while (parte != NULL) {
                    
                    parte = strtok(NULL, delim);
                    i++;
                }
                TRocha rocha = preenche_rocha(&novarocha, lat, long_i, peso, novarocha.lista_mineral);
                printf("%s", rocha.categoria);
                break;
            }
            case 'E':
                pontoComumSondas(&sondasL);
                break;
            default:
                break;
        }
    }

    return 0;
}