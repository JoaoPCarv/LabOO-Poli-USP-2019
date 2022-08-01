//Autor: João Pedro Lima Affonso de Carvalho, NUSP: 11260846

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const float PI = 3.14159265359; //Constante usada no cálculo de cossenos

//As funções serão comentadas segundo as suas implementações.

void interface();
void digitarOpcao1();
void digitarOpcao2();
void digitarOpcao3();

void digitarMatriz(int n, float* a_vetor, float* b_vetor, float* c_vetor);

void decomporEmLU(int n, float* a_vetor, float* b_vetor, float* c_vetor, float* u_vetor, float* l_vetor);
void imprimirLU(int n, float* c_vetor, float* u_vetor, float* l_vetor);
void resolverLinear(int n, float* c_vetor, float* d_vetor,
                     float* u_vetor, float* l_vetor, float* x_vetor, float* y_vetor);
void imprimirX(int n, float* x_vetor);

int main()
{
    interface();
    return 0;
}

void interface(){ //Exibe a interface para o usuário

    //Usuário digita a opção desejada
    printf("Digite a opcao desejada: \n");
    printf("1- Decomposicao LU de uma matriz tridiagonal aciclica; \n");
    printf("2- Resolucao de um sistema linear; \n");
    printf("3- Teste da resolucao de um sistema linear com matriz tridiagonal ciclica. \n");

    int validacao = 0;
    int op;

    while(validacao == 0){

        scanf("%d", &op);

        if(op < 0 || op > 3) printf("Digite uma opcao valida. \n");
        else validacao = 1;
    }

    //Invoca a função da opção desejada
    if(op == 1) digitarOpcao1();
     else if(op == 2) digitarOpcao2();
      else digitarOpcao3();

}

void digitarOpcao1(){ //Função da opção 1

   int n;

   printf("Decomposicao em LU: \n");

   printf("E necessario digitar uma matriz tridiagonal. \n");

   printf("Informe a ordem da matriz a ser decomposta: \n");
   scanf("%d", &n);

   //Vetores que guardam a matriz digitada
   float a_vetor[n];
   float b_vetor[n];
   float c_vetor[n];

   //Invoca a função de digitar uma matriz tridiagonal acíclica
   digitarMatriz(n, a_vetor, b_vetor, c_vetor);

   //Vetores que guardam a decomposição LU
   float u_vetor[n];
   float l_vetor[n];

   //Invoca a função de decomposição em LU
   decomporEmLU(n, a_vetor, b_vetor, c_vetor, u_vetor, l_vetor);

   //Imprime as matrizes L e U
   imprimirLU(n, c_vetor, u_vetor, l_vetor);

}

void digitarOpcao2(){ //Função da opção 2

    int n;

    printf("Resolucao de um sistema linear: \n");

    printf("O sistema linear possui estrutura Ax = d. \n");

    printf("E necessario informar a matriz A e o vetor d. \n");

    printf("Informe a ordem da matriz tridiagonal A: \n");
    scanf("%d", &n);

    //Vetores que guardam a matriz digitada
   float a_vetor[n];
   float b_vetor[n];
   float c_vetor[n];

   //Invoca a função de digitar uma matriz tridiagonal acíclica
   digitarMatriz(n, a_vetor, b_vetor, c_vetor);

   //Vetor coluna do lado direito
   float d_vetor[n];

   for(int j = 0; j < n; j++){

    printf("Informe a %da linha do vetor coluna d: ", j+1);
    scanf("%f", &d_vetor[j]);

   }

   float x_vetor[n];
   float y_vetor[n];
   float l_vetor[n];
   float u_vetor[n];

   //Faz a decomposição LU da matriz digitada
   decomporEmLU(n, a_vetor, b_vetor, c_vetor, u_vetor, l_vetor);

   //Resolve o sistema linear Ax = d com as matrizes L e U
   resolverLinear(n, c_vetor, d_vetor, u_vetor, l_vetor, x_vetor, y_vetor);

   //Imprime a solução x
   imprimirX(n, x_vetor);

}

void digitarOpcao3(){ //Função da opção 3

    printf("Resolucao de um sistema linear com matriz tridiagonal ciclica: \n");

    printf("Sera resolvido o sistema linear Ax = d ciclico do exemplo do enunciado. \n");

    int n = 20; //Ordem especificada no enunciado

    float a_vetor[n];
    float b_vetor[n];
    float c_vetor[n];

    //Regra de criação dos coeficientes da matriz conforme o enunciado
    for(int j = 0; j < n-1; j++) a_vetor[j] = (float) (2*(j+1) -1)/ (4* (j+1));

    a_vetor[n-1] = (float) (2*n - 1)/(2*n);

    //Regra de criação dos coeficientes da matriz conforme o enunciado
    for(int j = 0; j < n; j++){

            b_vetor[j] = 2.0000;
            c_vetor[j] = 1 - a_vetor[j];
    }

    //Digita a matriz A tridiagonal cíclica
    printf("A matriz A tridiagonal ciclica e: \n");

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(i == j) printf("  %.5f  ", b_vetor[i]);
             else if(i == 0 && j == n-1) printf("  %.5f  ", a_vetor[0]);
              else if(i == n-1 && j == 0) printf("  %.5f  ", c_vetor[n-1]);
               else if(i - j == 1) printf("  %.5f  ", a_vetor[i]);
                else if(j - i == 1) printf("  %.5f  ", c_vetor[i]);
                 else printf("  %.5f  ", 0.0000);
        }

        printf("\n");
    }

    //Vetod do lado direito
    float d_vetor[n];

    //Regra de criação do vetor d
    for(int j = 0; j < n; j++) d_vetor[j] = (float) cos((2*PI*(j+1)*(j+1))/(n*n));

    printf("A coluna d a direita e: \n");

    //Digita o vetor d
    for(int j = 0; j < n; j++) printf("d%d = %.5f; \n", j+1, d_vetor[j]);;


    //Os vetores definidos a seguir são auxiliares e usados na resolução conforme o enunciado

    float v_vetor[n-1];

    for(int j = 0; j < n-1; j++){

        if(j == 0) v_vetor[j] = a_vetor[0];
         else if(j == n - 2) v_vetor[j] = c_vetor[n - 2];
          else v_vetor[j] = 0.0000;

    }

    //Definição da submatriz principal T
    float a_til_vetor[n-1];
    float b_til_vetor[n-1];
    float c_til_vetor[n-1];

    float d_til_vetor[n-1];

    a_til_vetor[0] = 0.0000;
    c_til_vetor[n-2] = 0.0000;


    for(int j = 1; j < n-1; j++) {
        a_til_vetor[j] = a_vetor[j];
        c_til_vetor[j-1] = c_vetor[j-1];

    }

    for(int j = 0; j < n-1; j++){
        b_til_vetor[j] = b_vetor[j];
        d_til_vetor[j] = d_vetor[j];

    }

    float l_til_vetor[n-1];
    float u_til_vetor[n-1];

    //Decomposição LU da submatriz T
    decomporEmLU(n-1, a_til_vetor, b_til_vetor, c_til_vetor, u_til_vetor, l_til_vetor);

    float y_til_vetor[n-1];
    float y_aux_vetor[n-1];

    //Resolução de Ty(til) = d(til)
    resolverLinear(n-1, c_til_vetor, d_til_vetor, u_til_vetor, l_til_vetor, y_til_vetor, y_aux_vetor);


    float z_til_vetor[n-1];
    float z_aux_vetor[n-1];

    //Resolução de Tz(til) = v
    resolverLinear(n-1, c_til_vetor, v_vetor, u_til_vetor, l_til_vetor, z_til_vetor, z_aux_vetor);

    float x_vetor[n];

    //Cálculo da solução conforme o enunciado
    x_vetor[n-1] = (float) (d_vetor[n-1] - c_vetor[n-1]*y_til_vetor[0] - a_vetor[n-1]*y_til_vetor[n-2])/
    (b_vetor[n-1] - c_vetor[n-1]*z_til_vetor[0] - a_vetor[n-1]*z_til_vetor[n-2]);

    for(int j = n - 2; j >= 0; j--) x_vetor[j] = y_til_vetor[j] - x_vetor[n-1]*z_til_vetor[j];

    printf("A solucao do sistema e: \n");

    //Imprime a solução
    for(int j = 0; j < n; j++) printf("x%d = %.5f; \n", j+1, x_vetor[j]);

    printf("\n");



}

//Função para digitar a matriz tridiagonal acíclica
void digitarMatriz(int n, float* a_vetor, float* b_vetor, float* c_vetor){

    a_vetor[0] = 0;

   for(int j = 1; j < n; j++){

       printf("Digite o %d elemento da diagonal inferior: ", j);
          scanf("%f", &a_vetor[j]);

   }



   for(int j = 0; j < n; j++){

       printf("Digite o %d elemento da diagonal principal: ", j+1);
          scanf("%f", &b_vetor[j]);

   }



    for(int j = 0; j < n-1; j++){

       printf("Digite o %d elemento da diagonal superior: ", j+1);
          scanf("%f", &c_vetor[j]);

   }
   c_vetor[n-1] = 0;

   printf("\n");
   printf("A matriz digitada e: \n");

   for(int i = 0; i < n; i++){

    for(int j = 0; j < n; j++){

       if(j == i) printf("  %.5f  ", b_vetor[i]);

        else if(i - j == 1) printf("  %.5f  ", a_vetor[i]);

         else if(j - i == 1) printf("  %.5f  ", c_vetor[i]);

         else printf("  %.5f  ", 0.0000);
    }
       printf("\n");

   }

}

//Decomposição LU conforme o enunciado
void decomporEmLU(int n, float* a_vetor, float* b_vetor, float* c_vetor, float* u_vetor, float* l_vetor){

   u_vetor[0] = b_vetor[0];
   l_vetor[0] = 0;

   for(int j = 1; j < n; j++){

        l_vetor[j] = (float) a_vetor[j] / u_vetor[j - 1];
        u_vetor[j] = (float) b_vetor[j] - l_vetor[j]*c_vetor[j - 1];

   }

}

//Imprime a decomposição LU
void imprimirLU(int n, float* c_vetor, float* u_vetor, float* l_vetor){


   printf("\n");
   printf("A matriz L e: \n");

   for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(i == j) printf("  %.5f  ", 1.0000);

             else if(i - j == 1) printf("  %.5f  ", l_vetor[i]);

             else printf("  %.5f  ", 0.0000);
        }

        printf("\n");
   }

   printf("\n");
   printf("A matriz U e: \n");

   for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(i == j) printf("  %.5f  ", u_vetor[i]);

             else if(j - i == 1) printf("  %.5f  ", c_vetor[i]);

             else printf("  %.5f  ", 0.0000);
        }

        printf("\n");
   }

}

//Resolve o sistema linear conforme o especificado no enunciado
void resolverLinear(int n, float* c_vetor, float* d_vetor, float* u_vetor, float* l_vetor, float* x_vetor, float* y_vetor){

    y_vetor[0] = d_vetor[0];

    for(int j = 1; j < n; j++){

        y_vetor[j] = d_vetor[j] - l_vetor[j]*y_vetor[j - 1];
    }

    x_vetor[n - 1] = (float) y_vetor[n - 1]/ u_vetor[n - 1];

    for(int j = n - 2; j >= 0; j--){

        x_vetor[j] = (float) (y_vetor[j] - c_vetor[j]*x_vetor[j + 1])/u_vetor[j];

    }

}

//Imprime a solução do sistema Ax = d de matriz A tridiagonal acíclica
void imprimirX(int n, float* x_vetor){

    printf("A solucao do sistema Ax = d e: \n");

    for(int j = 0; j < n; j++) printf("x%d = %.5f \n", j+1, x_vetor[j]);


}


