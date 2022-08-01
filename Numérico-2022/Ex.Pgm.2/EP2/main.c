//Autor: João Pedro Lima Affonso de Carvalho, NUSP: 11260846

#include <stdio.h>
#include <stdlib.h>

const double E = 2.71828; //Numero de Euler

//As funções serão comentadas segundo as suas implementações.

void retornarDadosPara6Nos(double* nos_6, double* pesos_6);
void retornarDadosPara8Nos(double* nos_8, double* pesos_8);
void retornarDadosPara10Nos(double* nos_10, double* pesos_10);

void interface();
int numero_nos();
void seletor_nos(int n, double* nos, double* pesos);
void opcao1();
void opcao2();
void opcao3();

double funcao_xy(double x, double y, int opt);

void mudancaDeVariavel(int n, double* nos, double* pesos, double a, double b);

double resolverIntegralDupla(int n, double* nos_x, double* pesos_x, double* limites1, double* limites2, int opt);
double fMaiusculo(int n, double x, double* nos_y, double* pesos_y, int opt);

int main()
{
    interface();
    return 0;

}

void retornarDadosPara6Nos(double* nos_6, double* pesos_6){ //Retorna os dados para 6 nós

    nos_6[0] = - 0.9324695142031520278123016;
    nos_6[1] = - 0.6612093864662645136613996;
    nos_6[2] = - 0.2386191860831969086305017;
    nos_6[3] =   0.2386191860831969086305017;
    nos_6[4] =   0.6612093864662645136613996;
    nos_6[5] =   0.9324695142031520278123016;

    pesos_6[0] = 0.1713244923791703450402961;
    pesos_6[1] = 0.3607615730481386075698335;
    pesos_6[2] = 0.4679139345726910473898703;
    pesos_6[3] = 0.4679139345726910473898703;
    pesos_6[4] = 0.3607615730481386075698335;
    pesos_6[5] = 0.1713244923791703450402961;

}

void retornarDadosPara8Nos(double* nos_8, double* pesos_8){ //Retorna os dados para 8 nós

    nos_8[0] = - 0.9602898564975362316835609;
    nos_8[1] = - 0.7966664774136267395915539;
    nos_8[2] = - 0.5255324099163289858177390;
    nos_8[3] = - 0.1834346424956498049394761;
    nos_8[4] =   0.1834346424956498049394761;
    nos_8[5] =   0.5255324099163289858177390;
    nos_8[6] =   0.7966664774136267395915539;
    nos_8[7] =   0.9602898564975362316835609;

    pesos_8[0] = 0.1012285362903762591525314;
    pesos_8[1] = 0.2223810344533744705443560;
    pesos_8[2] = 0.3137066458778872873379622;
    pesos_8[3] = 0.3626837833783619829651504;
    pesos_8[4] = 0.3626837833783619829651504;
    pesos_8[5] = 0.3137066458778872873379622;
    pesos_8[6] = 0.2223810344533744705443560;
    pesos_8[7] = 0.1012285362903762591525314;

}

void retornarDadosPara10Nos(double* nos_10, double* pesos_10){ //Retorna os dados para 10 nós

    nos_10[0] = - 0.9739065285171717200779640;
    nos_10[1] = - 0.8650633666889845107320967;
    nos_10[2] = - 0.6794095682990244062343274;
    nos_10[3] = - 0.4333953941292471907992659;
    nos_10[4] = - 0.1488743389816312108848260;
    nos_10[5] =   0.1488743389816312108848260;
    nos_10[6] =   0.4333953941292471907992659;
    nos_10[7] =   0.6794095682990244062343274;
    nos_10[8] =   0.8650633666889845107320967;
    nos_10[9] =   0.9739065285171717200779640;

    pesos_10[0] = 0.0666713443086881375935688;
    pesos_10[1] = 0.1494513491505805931457763;
    pesos_10[2] = 0.2190863625159820439955349;
    pesos_10[3] = 0.2692667193099963550912269;
    pesos_10[4] = 0.2955242247147528701738930;
    pesos_10[5] = 0.2955242247147528701738930;
    pesos_10[6] = 0.2692667193099963550912269;
    pesos_10[7] = 0.2190863625159820439955349;
    pesos_10[8] = 0.1494513491505805931457763;
    pesos_10[9] = 0.0666713443086881375935688;
}



void mudancaDeVariavel(int n, double* nos, double* pesos, double a, double b){ //Faz a equivalência linear de pesos e nós entre os intervalos [-1,1] e [a,b]

    double size = b - a;

    double delta = 0.0;

    for(int i = 0; i < n; i++){

            delta = nos[i] + 1.0;
            nos[i] = a + delta*size/2;
            pesos[i] = pesos[i] * size/2;

    }

}

double fMaiusculo(int n, double x, double* nos_y, double* pesos_y, int opt){ //Calcula F(x_i, y_ij)

    double soma = 0.0;

    for (int i = 0; i < n; i++){

        soma += pesos_y[i] * funcao_xy(x, nos_y[i], opt);
    }

    return soma;

}

double resolverIntegralDupla(int n, double* nos_x, double* pesos_x, double* limites1, double* limites2, int opt){ //Calcula a integral dupla segundo o Método de Gauss

    double resultado = 0.0;

    for(int i = 0; i < n; i++){

        double nos_y[n];
        double pesos_y[n];

        seletor_nos(n, nos_y, pesos_y);

        mudancaDeVariavel(n, nos_y, pesos_y, limites1[i], limites2[i]);

        resultado += pesos_x[i] * fMaiusculo(n, nos_x[i], nos_y, pesos_y, opt);

    }

    return resultado;

}

double funcao_xy(double x, double y, int opt){ //Funcao a ser integrada

    double retorno = 0.0;

    if(opt == 0) retorno = 1; //Parametrização do cubo
     else if(opt == 1) retorno = - x - y + 1; //Parametrização do tetraedro
      else if(opt == 2) retorno = 1; //Parametrização da regiao no primeiro quadrante
       else if(opt == 3) retorno = sqrt(pow(pow(E, y/x), 2) + pow(pow(E, y/x)/(pow(x,2)),2) + 1); //Parametrização a região z = e^(y/x)



    return retorno;

}


void interface(){ //Exibe a interface para o usuário

    //Usuário digita a opção desejada
    printf("Digite a opcao desejada: \n");
    printf("Exemplo 1- Volume do cubo e do tetraedro; \n");
    printf("Exemplo 2- Area da regiao no primeiro quadrante; \n");
    printf("Exemplo 3- Area da superficie descrita por z = e^(y/x); \n");


    int validacao = 0;
    int op;

    while(validacao == 0){

        scanf("%d", &op);

        if(op < 0 || op > 3) printf("Digite uma opcao valida. \n");
        else validacao = 1;
    }

        //Invoca a função da opção desejada

    if(op == 1) opcao1();
     else if(op == 2) opcao2();
      else if(op == 3) opcao3();

}

int numero_nos(){ //Usuário informa no número de nós desejado

    printf("Informe o numero de nos desejado (6,8,10): \n");

    int validacao = 0;
    int n;

    while(validacao == 0){

        scanf("%d", &n);

        if(n != 6 && n != 8 && n != 10) printf("Digite uma opcao valida. \n");
        else validacao = 1;
    }

    return n;

}

void seletor_nos(int n, double* nos, double* pesos){ //Retorna os dados segundo o número de nós digitado

    if(n == 6) retornarDadosPara6Nos(nos, pesos);
     else if (n == 8) retornarDadosPara8Nos(nos, pesos);
      else if (n == 10) retornarDadosPara10Nos(nos, pesos);

}

void opcao1(){ //Opção 1

    printf("Exemplo 1- Volume do cubo e do tetraedro. \n");

    int n = numero_nos();

    double nos[n];
    double pesos[n];

    seletor_nos(n, nos, pesos);

    mudancaDeVariavel(n, nos, pesos, 0, 1);

    double limites_c1[n];
    double limites_c2[n];

    for(int i = 0; i < n; i++){ //Limites de integração para o cubo

        limites_c1[i] = 0;
        limites_c2[i] = 1;

    }


    double cubo = resolverIntegralDupla(n, nos, pesos, limites_c1, limites_c2, 0);

    double limites_t1[n];
    double limites_t2[n];

    for(int i = 0; i < n; i++){ //Limites de integração para o tetraedro

        limites_t1[i] = 0;
        limites_t2[i] = - nos[i] + 1;

    }

    double tetraedro = resolverIntegralDupla(n, nos, pesos, limites_t1, limites_t2, 1);

    printf("O volume do cubo e: %.5f; \n", cubo);
    printf("O volume do tetraedro e: %.5f. \n", tetraedro);

    return;

}

void opcao2(){ //Opção 2

    printf("Exemplo 2- Area da regiao no primeiro quadrante; \n");

    int n = numero_nos();

    double nos[n];
    double pesos[n];

    seletor_nos(n, nos, pesos);

    double limites_1[n];
    double limites_2[n];

    mudancaDeVariavel(n, nos, pesos, 0, 1);

    for(int i = 0; i < n; i++){ //Limites de integração para a regiao

        limites_1[i] = 0;
        limites_2[i] = 1 - nos[i]*nos[i];

    }

    double resultado = resolverIntegralDupla(n, nos, pesos, limites_1, limites_2, 2);

    printf("A area da regiao e: %.5f. \n", resultado);

    return;

}

void opcao3(){ //Opção 3

    printf("Exemplo 3- Area da superficie descrita por z = e^(y/x); \n");

    int n = numero_nos();

    double nos[n];
    double pesos[n];

    seletor_nos(n, nos, pesos);

    double limites_1[n];
    double limites_2[n];

    mudancaDeVariavel(n, nos, pesos, 0.1, 0.5);

    for(int i = 0; i < n; i++){ //Limites de integração para a superificie

        limites_1[i] = nos[i]*nos[i]*nos[i];
        limites_2[i] = nos[i]*nos[i];

    }

    double resultado = resolverIntegralDupla(n, nos, pesos, limites_1, limites_2, 3);

    printf("A area da superficie e: %.5f. \n", resultado);

    return;

}
