#include "ListaSondas.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int compilar;

    printf("Digite 1-Teste com aquivo ou 2-Teste no terminal:\n");
    scanf("%d", &compilar);

    if (compilar == 1)
    {
        char operacao;
        int qntdOperacoes;
        srand(time(NULL));
        SondaMarte sonda1;
        listaSonda sondasL;
        iniciaListaSonda(&sondasL);

        FILE *arq = NULL;
        arq = fopen("teste.txt", "r");
        if (arq == NULL)
        {
            printf("falha leitura");
            exit(0);
        }
        int N_Sondas;
        float lat_i, lon_i, c_i, v_i, nc_i;
        fscanf(arq, "%d", &N_Sondas);

        for (int i = 0; i < N_Sondas; i++)
        {
            fscanf(arq, "%f %f %f %f %f", &lat_i, &lon_i, &c_i, &v_i, &nc_i);
            insereSonda(&sondasL, inicializaSondaTexto(&sonda1, lat_i, lon_i, c_i, v_i, nc_i));
        }
        fscanf(arq, "%d", &qntdOperacoes);

        ImprimeListaSondas(&sondasL);

        for (int i = 0; i < qntdOperacoes; i++)
        {
            fscanf(arq, " %c", &operacao);
            TRocha novarocha;

            switch (operacao)
            {
            case 'R':
            {
                float lat, long_i, peso;
                char minerais[100];
                fscanf(arq, "%f %f %f", &lat, &long_i, &peso);
                getchar();
                fgets(minerais, sizeof(minerais), stdin);
                minerais[strcspn(minerais, "\n")] = '\0';

                // Inicializa a rocha

                // Quebra os minerais em partes e adiciona à lista
                const char delim[2] = " ";
                char *parte = strtok(minerais, delim);
                TMineral x;
                TListaMineral listaM;
                FLVaziaM(&listaM);
                while (parte != NULL)
                {
                    strcpy(x.nomeM, parte);
                    LInsereM(&listaM, x);
                    parte = strtok(NULL, delim);
                    // vai me da uma categoria, eu tenho que inserir em uma rocha
                    // e dps colocar na lista de sondas
                }
                novarocha = preenche_rocha(&novarocha, lat, long_i, peso, &listaM);

                // vamos colocar essa rocha em um compartimento
                AdicionarRochaS(&sondasL, &novarocha);

                break;
            }
            case 'E':
            {
                pontoComumSondas(&sondasL);
                break;
            }
            case 'I':
            {
                Imprime_I_Lista(&sondasL);
            }
            default:
            {
                break;
            }
            }
        }
    }
    else if (compilar == 2)
    {
        int qntdOperacoes;
        char operacao;
        srand(time(NULL));
        SondaMarte sonda1;
        listaSonda sondasL;
        iniciaListaSonda(&sondasL);

        int N_Sondas;
        float lat_i, lon_i, c_i, v_i, nc_i;
        
        printf("Digite a quantidade de sondas que irao para Marte:\n");
        scanf("%d", &N_Sondas);

        for (int i = 0; i < N_Sondas; i++)
        {
            printf("Digite a latitude, longitude, capacidade, velocidade e combustivel da sonda:\n");
            scanf("%f %f %f %f %f", &lat_i, &lon_i, &c_i, &v_i, &nc_i);
            insereSonda(&sondasL, inicializaSondaTexto(&sonda1, lat_i, lon_i, c_i, v_i, nc_i));
        }
        printf("Digite a quantidade de operacoes:\n");
        scanf("%d", &qntdOperacoes);

        ImprimeListaSondas(&sondasL);

        for (int i = 0; i < qntdOperacoes; i++)
        {
            printf("Selecione a operacao: (R, I, E)\n");
            scanf(" %c", &operacao);
            TRocha novarocha;

            switch (operacao)
            {
            case 'R':
            {
                printf("Digite a latitude, longitude, peso e minerais (separados com " ").\n");
                float lat, long_i, peso;
                char minerais[100];
                scanf("%f %f %f", &lat, &long_i, &peso);
                getchar();
                fgets(minerais, sizeof(minerais), stdin);
                minerais[strcspn(minerais, "\n")] = '\0';

                // Inicializa a rocha

                // Quebra os minerais em partes e adiciona à lista
                const char delim[2] = " ";
                char *parte = strtok(minerais, delim);
                TMineral x;
                TListaMineral listaM;
                FLVaziaM(&listaM);
                while (parte != NULL)
                {
                    strcpy(x.nomeM, parte);
                    LInsereM(&listaM, x);
                    parte = strtok(NULL, delim);
                    // vai me da uma categoria, eu tenho que inserir em um mineral
                    // e dps colocar na lista mineral da rocha
                }
                novarocha = preenche_rocha(&novarocha, lat, long_i, peso, &listaM);

                // vamos colocar essa rocha em um compartimento
                AdicionarRochaS(&sondasL, &novarocha);

                break;
            }
            case 'E':
            {
                pontoComumSondas(&sondasL);
                break;
            }
            case 'I':
            {
                Imprime_I_Lista(&sondasL);
            }
            default:
            {
                break;
            }
            }
        }
    }

    return 0;
}