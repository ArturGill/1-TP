

typedef struct
{
    int identificador;
    
    double peso;
    char categoria [50];
    char localizacao[50];
    int data;
}TRocha;

void iniciarRocha(TRocha *rocha, int identificador,,double peso,char categoria,char localizacao,int data);
void ObterValores(TRocha * );
void atribuirValores();
void classificar(TRocha *rocha, char categoria);