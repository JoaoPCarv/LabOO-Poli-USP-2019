#include <iostream>
#include "Tabela.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "PersistenciaDeCompeticao.h"

using namespace std;

void imprimirMain(Competicao* c){

    CompeticaoSimples* simples = dynamic_cast<CompeticaoSimples*>(c);

    if(simples != NULL) simples->imprimir();
    else{
        CompeticaoMultimodalidades* multi = dynamic_cast<CompeticaoMultimodalidades*>(c);
        multi->imprimir();
        };
};

Modalidade* cadastrarModalidadeMain(int n, Equipe** participantes, int quantidade){

    string nomeMod;
    if(n == 0) cout << "Informe o nome da modalidade: ";
     else cout << "Informe o nome da modalidade " << n << ": ";
    cin  >> nomeMod;
    cout << endl;

    Modalidade* m = new Modalidade(nomeMod, participantes, quantidade);

    string temR;
    cout << "Tem resultado (s/n): ";
    cin  >> temR;
    cout << endl;

    if(temR == "s"){

        Equipe** ordem = new Equipe*[quantidade];

        for(int i = 0; i < quantidade; i++){

            string nomeE;
            cout << "Informe a equipe " << i+1 << "a colocada: ";
            cin  >> nomeE;
            cout << endl;

            for(int j = 0; j < quantidade; j++) if(participantes[j]->getNome() == nomeE) ordem[i] = participantes[j];
        };
       m->setResultado(ordem);
    };
    return m;
};

int salvarMain(Competicao* c){

    string salvar;
            cout << "Deseja salvar a competicao (s/n)? ";
            cin  >> salvar;
            cout << endl;

    if(salvar == "s"){

        string arquivo;
                cout << "Digite o nome do arquivo: ";
                cin  >> arquivo;
                cout << endl;

                PersistenciaDeCompeticao* pers = new PersistenciaDeCompeticao();

                try {
                    pers->salvar(arquivo, c);
                    } catch(invalid_argument* e){
                        cout << e->what() << endl;
                        return -1;
                    };
    };
return 0;
};

int main()
{
    string resposta;

    cout << "Deseja carregar uma competicao (s/n)? ";
    cin  >> resposta;
    cout << endl;

    if(resposta == "s"){

        string arquivo;
        cout << "Digite o nome do arquivo: ";
        cin  >> arquivo;
        cout << endl;

        PersistenciaDeCompeticao* pers = new PersistenciaDeCompeticao();

        try{
            Competicao* c = pers->carregar(arquivo);
            imprimirMain(c);
            return 0;

        }catch(invalid_argument* e){
               cout << e->what() << endl;
               return 0;
        };
       }
       else{

        int quantidade;
        cout << "Informe a quantidade de equipes: ";
        cin  >> quantidade;
        cout << endl;

        Equipe** participantes = new Equipe*[quantidade];

        for(int i = 0; i < quantidade; i++){

            string nome;
            cout << "Informe o nome da equipe " << i+1 << ": ";
            cin  >> nome;
            cout << endl;
            participantes[i] = new Equipe(nome);
        };

        string nomeComp;
        cout << "Informe o nome da competicao: ";
        cin  >> nomeComp;
        cout << endl;
        string tipoC;
        cout << "Competicao simples (s) ou multimodalidades (m): ";
        cin  >> tipoC;
        cout << endl;

        if(tipoC == "s"){

            Modalidade* m = cadastrarModalidadeMain(0, participantes, quantidade);

            CompeticaoSimples* simples = new CompeticaoSimples(nomeComp, participantes, quantidade, m);

            int excecao = salvarMain(simples);
            if (excecao == 0) simples->imprimir();
            return 0;
                } else{

                    CompeticaoMultimodalidades* multi = new CompeticaoMultimodalidades(nomeComp, participantes, quantidade);

                    int quantidadeM;
                    cout << "Informe a quantidade de modalidades: ";
                    cin  >> quantidadeM;
                    cout << endl;

                    for(int i = 0; i < quantidadeM; i++){

                        try{
                            multi->adicionar(cadastrarModalidadeMain(i+1, participantes, quantidade));
                            } catch(invalid_argument* e){
                                cout << e->what() << endl;
                                return 0;
                            };
                                                         };
            int excecao = salvarMain(multi);
            if(excecao == 0) multi->imprimir();
            return 0;
              };
       };
};
