//Autor: João Pedro Lima Affonso de Carvalho, NUSP: 11260846

#include <stdio.h>
#include <stdlib.h>

const double L = 0.02; //Espessura da chapa (20 mm = 0.02 m)

//As funções serão comentadas segundo as suas implementações.

void interface();

void selecionarDadosParaNos(double n, double* nos, double* pesos);

void retornarDadosPara7Nos(double* nos_7, double* pesos_7);
void retornarDadosPara15Nos(double* nos_15, double* pesos_15);

void mudancaDeVariavel(int n, double* nos, double* pesos, double a, double b);

double funcao_x(double x_no, double x_i, double h, double L, int opt);
double fMaiusculo(int n, double* nos_y, double* pesos_y, double x_i, double h, double L, int opt);

void calcularMatrizColuna(int n, double L, double* coluna_vetor);

void determinarMatrizTridiagonal(int n, double* a_vetor, double* b_vetor, double* c_vetor, double L);
void decomporEmLU(int n, double* a_vetor, double* b_vetor, double* c_vetor, double* u_vetor, double* l_vetor);
void resolverLinear(int n, double* c_vetor, double* d_vetor,
                     double* u_vetor, double* l_vetor, double* x_vetor, double* y_vetor);
void calculaAlpha_indice_i(int n, double L, double* alpha_vetor);

int main()
{
    interface();

}

void interface(){ //Interface gráfica

    int n;
    //Usuário digita a opção desejada
    printf("Digite o numero de nos desejado (7 ou 15): \n");

    int validacao = 0;

    while(validacao == 0){

        scanf("%d", &n);

        if(n != 7 && n != 15) printf("Digite uma opcao valida. \n");
        else validacao = 1;
    }

    printf("Para a funcao f(x) = 12*x*(1 - x) - 2, os coeficientes alpha, para %d nos, sao: \n", n);

    double alpha_vetor[n]; //Armazena o vetor de coeficientes alpha_i

    calculaAlpha_indice_i(n, L, alpha_vetor);

    for(int i = 0; i < n ; i++) printf("alpha_%d = %.5f \n", i + 1, alpha_vetor[i]);


}

void selecionarDadosParaNos(double n, double* nos, double* pesos) { //Função que organiza a seleção de conjuntos de nós e pesos para diferentes valores de n

     if(n == 7) retornarDadosPara7Nos(nos, pesos);
     else if(n == 15) retornarDadosPara15Nos(nos, pesos);

}


void retornarDadosPara7Nos(double* nos_7, double* pesos_7){ //Retorna os dados para 7 nós (dados tabelados)

    nos_7[0] = - 0.9491079123427585;
    nos_7[1] = - 0.7415311855993945;
    nos_7[2] = - 0.4058451513773972;
    nos_7[3] = - 0.0000000000000000;
    nos_7[4] =   0.4058451513773972;
    nos_7[5] =   0.7415311855993945;
    nos_7[6] =   0.9491079123427585;

    pesos_7[0] = 0.1294849661688697;
    pesos_7[1] = 0.2797053914892766;
    pesos_7[2] = 0.3818300505051189;
    pesos_7[3] = 0.4179591836734694;
    pesos_7[4] = 0.3818300505051189;
    pesos_7[5] = 0.2797053914892766;
    pesos_7[6] = 0.1294849661688697;

}

void retornarDadosPara15Nos(double* nos_15, double* pesos_15){  //Retorna os dados para 15 nós (dados tabelados)

    nos_15[0]  = - 0.9879925180204854;
    nos_15[1]  = - 0.9372733924007060;
    nos_15[2]  = - 0.8482065834104272;
    nos_15[3]  = - 0.7244177313601701;
    nos_15[4]  = - 0.5709721726085388;
    nos_15[5]  = - 0.3941513470775634;
    nos_15[6]  = - 0.2011940939974345;
    nos_15[7]  = - 0.0000000000000000;
    nos_15[8]  = - 0.2011940939974345;
    nos_15[9]  =   0.3941513470775634;
    nos_15[10] =   0.5709721726085388;
    nos_15[11] =   0.7244177313601701;
    nos_15[12] =   0.8482065834104272;
    nos_15[13] =   0.9372733924007060;
    nos_15[14] =   0.9879925180204854;

    pesos_15[0]  = 0.0307532419961173;
    pesos_15[1]  = 0.0703660474881081;
    pesos_15[2]  = 0.1071592204671719;
    pesos_15[3]  = 0.1395706779261543;
    pesos_15[4]  = 0.1662692058169939;
    pesos_15[5]  = 0.1861610000155622;
    pesos_15[6]  = 0.1984314853271116;
    pesos_15[7]  = 0.2025782419255613;
    pesos_15[8]  = 0.1984314853271116;
    pesos_15[9]  = 0.1861610000155622;
    pesos_15[10] = 0.1662692058169939;
    pesos_15[11] = 0.1395706779261543;
    pesos_15[12] = 0.1071592204671719;
    pesos_15[13] = 0.0703660474881081;
    pesos_15[14] = 0.0307532419961173;



};


void mudancaDeVariavel(int n, double* nos, double* pesos, double a, double b){ //Faz a equivalência linear de pesos e nós entre os intervalos [-1,1] e [a,b]

    double size = b - a;

    double delta = 0.0;

    for(int i = 0; i < n; i++){

            delta = nos[i] + 1.0;
            nos[i] = a + delta*size/2;
            pesos[i] = pesos[i] * size/2;

    }

}

double funcao_x(double x_no, double x_i, double h, double L, int opt){ //Multiplicação da função f(x) pela função phi_i(x) avaliada no nó desejado

    if(opt == 0) return (12 * x_no * (1 - x_no) - 2) * L * (x_no - x_i) / h; //Primeiro intervalo para phi(x)
      else if(opt == 1) return (12 * x_no * (1 - x_no) - 2) *  L * (x_i - x_no) / h; //Segundo intervalo para phi(x)
    //Fórmula dada para a validação, usando a f(x) dada (para adaptar para a o intervalo [0, L], multiplica-se por (L-0))
    //f(x) = 12*x*(1 - x) - 2
}

double fMaiusculo(int n, double* nos_y, double* pesos_y, double x_i, double h, double L, int opt){ //Calcula a integral pela quadratura de Gauss

    double soma = 0.0;

    for (int i = 0; i < n; i++){

        soma += pesos_y[i] * funcao_x(nos_y[i], x_i, h, L, opt);
    }


    return soma;

}

void calcularMatrizColuna(int n, double L, double* coluna_vetor){ //Determina a matriz dos produtos internos <f, phi>

    double h = L / (n + 1); //Determinação do "passo" h

    double x_i[n + 2];

    for(int i = 0; i < n + 2; i++) x_i[i] = i * h; //Determinação dos "nós" x_i

    double parcial_1[n]; //Para calcular o produto interno no intervalo [x_(i-1), x_i]
    double parcial_2[n]; //Para calcular o produto interno no intervalo [x_i, x_(i+1)]

    double nos[n];
    double pesos[n];


    for(int i = 0; i < n; i++){

        selecionarDadosParaNos(n, nos, pesos);
        mudancaDeVariavel(n, nos, pesos, x_i[i], x_i[i + 1]); //Faz a mudança de intervalo de [-1,1] para o intervalo suporte inferior de phi(x)
        parcial_1[i] = fMaiusculo(n, nos, pesos, x_i[i], h, L, 0); //Calcula o produto interno no intervalo [x_(i-1), x_i]

    }

    for(int i = 0; i < n; i++){

        selecionarDadosParaNos(n, nos, pesos);
        mudancaDeVariavel(n, nos, pesos, x_i[i+1], x_i[i + 2]); //Faz a mudança de intervalo de [-1,1] para o intervalo suporte superior de phi(x)
        parcial_2[i] = fMaiusculo(n, nos, pesos, x_i[i], h, L, 1); //Calcula o produto interno no intervalo [x_i, x_(i+1)]

    }

    for(int i = 0; i < n; i++) coluna_vetor[i] = parcial_1[i] + parcial_2[i]; //Determina a matriz coluna do lado direito da equação matricial

}

void determinarMatrizTridiagonal(int n, double* a_vetor, double* b_vetor, double* c_vetor, double L){ //Determina a matriz tridiagonal do sistema linear

     double h = L / (n + 1); //Determinação do "passo" h

     a_vetor[0] = 0;
     for(int i = 1; i < n; i++) a_vetor[i] = -L/h; //Diagonal vizinha

     for(int i = 0; i < n; i++) b_vetor[i] = 2*L/h; //Diagonal principal

     for(int i = 0; i < n - 1; i++) c_vetor[i] = -L/h; //Diagonal vizinha
     c_vetor[n - 1] = 0;

}


void decomporEmLU(int n, double* a_vetor, double* b_vetor, double* c_vetor, double* u_vetor, double* l_vetor){ //Decomposição LU conforme o EP1

   u_vetor[0] = b_vetor[0];
   l_vetor[0] = 0;

   for(int j = 1; j < n; j++){

        l_vetor[j] = (double) a_vetor[j] / u_vetor[j - 1];
        u_vetor[j] = (double) b_vetor[j] - l_vetor[j]*c_vetor[j - 1];

   }

}

void resolverLinear(int n, double* c_vetor, double* d_vetor, double* u_vetor, double* l_vetor, double* x_vetor, double* y_vetor){ //Resolve o sistema linear conforme o EP1

    y_vetor[0] = d_vetor[0];

    for(int j = 1; j < n; j++){

        y_vetor[j] = d_vetor[j] - l_vetor[j]*y_vetor[j - 1];
    }

    x_vetor[n - 1] = (double) y_vetor[n - 1]/ u_vetor[n - 1];

    for(int j = n - 2; j >= 0; j--){

        x_vetor[j] = (double) (y_vetor[j] - c_vetor[j]*x_vetor[j + 1])/u_vetor[j];

    }

}

void calculaAlpha_indice_i(int n, double L, double* alpha_vetor){ //Calcula os índices alpha_i (i de 1 a n)

    double a_vetor[n];
    double b_vetor[n];
    double c_vetor[n];

    determinarMatrizTridiagonal(n, a_vetor, b_vetor, c_vetor, L); //Recebe os coeficientes da matriz tridiagonal

    double coluna_vetor[n]; //Vetor coluna que guarda os produtos internos de f com as bases phi(x)

    calcularMatrizColuna(n, L, coluna_vetor); //Calcula os coeficientes da matriz coluna acima

    //Vetores da decomposição LU
    double u_vetor[n];
    double l_vetor[n];

    decomporEmLU(n, a_vetor, b_vetor, c_vetor, u_vetor, l_vetor);

    double y_vetor[n]; //Necessário para a resolução do sistema linear

    resolverLinear(n, c_vetor, coluna_vetor, u_vetor, l_vetor, alpha_vetor, y_vetor);


}




