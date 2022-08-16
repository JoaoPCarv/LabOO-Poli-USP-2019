#include <iostream>
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"


using namespace std;

int main(){


/*string nome_Comp;
int quantidade_E;
int quantidade_M;

cout << "Informe o nome da competicao: " << endl;
cin  >> nome_Comp;

cout << "Informe a quantidade de equipes: " << endl;
cin  >> quantidade_E;

Equipe* equipes[quantidade_E];

for(int i = 0; i < quantidade_E; i++){

    string nome_Equipe;
    cout << "Informe o nome da equipe " << i + 1 << ": " << endl;
    cin  >> nome_Equipe;
    equipes[i] = new Equipe(nome_Equipe);

};

cout << "Informe a quantidade de modalidades: " << endl;
cin  >> quantidade_M;

Modalidade* modalidades[quantidade_M];
Competicao* c = new Competicao(nome_Comp, equipes, quantidade_E, quantidade_M);


for(int i = 0; i < quantidade_M; i++){

    Equipe** ordem = new Equipe* [quantidade_M];
    string nome_Modalidade;

    cout << "Informe o nome da modalidade " << i + 1 << ": " << endl;
    cin  >> nome_Modalidade;
    modalidades[i] = new Modalidade(nome_Modalidade, equipes, quantidade_E);

    for(int j = 0; j < quantidade_E; j++){

        string search_Nome;

        cout << "Informe a " << j + 1 << " colocada: "  << endl;
        cin  >> search_Nome;

        for(int k = 0; k < quantidade_E; k++){

            if(search_Nome == equipes[k]->getNome()){
                ordem[j] = equipes[k];
                break;
            };
        };
    };

    modalidades[i]->setResultado(ordem);
    c->adicionar(modalidades[i]);

};

c->imprimir();

return 0;*/


Tabela *t = new Tabela(NULL, 7);
t->imprimir();
delete t;

}
