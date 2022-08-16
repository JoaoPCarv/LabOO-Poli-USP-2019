#include "PersistenciaDeCompeticao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include "Equipe.h"
#include <fstream>
#include <stdlib.h>
#include <iterator>
#include <list>
#include <stdexcept>

using namespace std;

PersistenciaDeCompeticao::PersistenciaDeCompeticao(){};

PersistenciaDeCompeticao::~PersistenciaDeCompeticao(){};

Competicao* PersistenciaDeCompeticao::carregar(string arquivo){

ifstream in;
in.open(arquivo);

if(in.fail()) throw new invalid_argument("Problema no carregamento do arquivo");

char leitor[100];

int quantidade;

in.getline(leitor, 100, ' ');
quantidade = atoi(leitor);

Equipe** participantes = new Equipe*[quantidade];

for(int i = 0; i < quantidade; i++){

            in.getline(leitor, 100, ' ');
            participantes[i] = new Equipe(leitor);
        };

in.getline(leitor, 100, ' ');
string nomeComp = leitor;

in.getline(leitor, 100, ' ');
int multi = atoi(leitor);

if(multi == 1){
        CompeticaoMultimodalidades* c = new CompeticaoMultimodalidades(nomeComp, participantes, quantidade);
        in.getline(leitor, 100, ' ');
        int quantidadeM = atoi(leitor);

        for(int i = 0; i < quantidadeM; i++){

                in.getline(leitor, 100, ' ');
                string nomeMod = leitor;

                in.getline(leitor, 100, ' ');
                int resultado = atoi(leitor);

                in.getline(leitor, 100, ' ');
                int quantidadeE = atoi(leitor);

                Equipe** participantesM = new Equipe*[quantidadeE];

                for(int j = 0; j < quantidadeE; j++){

                      in.getline(leitor, 100, ' ');

                      for(int k = 0; k < quantidade; k++){

                        if(participantes[k]->getNome() == leitor){

                            participantesM[j] = participantes[k];

                        };
                      };
                    };
                Modalidade* m = new Modalidade(nomeMod, participantesM, quantidadeE);
                if(resultado == 1) m->setResultado(participantesM);
                c->adicionar(m);
               };
in.close();
return c;
         }
          else{
       in.getline(leitor, 100, ' ');
       string nomeMod = leitor;

       in.getline(leitor, 100, ' ');
       int resultado = atoi(leitor);

       in.getline(leitor, 100, ' ');
       int quantidadeE = atoi(leitor);

       Equipe** participantesM = new Equipe*[quantidadeE];

       for(int j = 0; j < quantidadeE; j++){

            in.getline(leitor, 100, ' ');
            for(int k = 0; k < quantidade; k++){

                if(participantes[k]->getNome() == leitor) participantesM[j] = participantes[k];
            };
        };
        Modalidade* m = new Modalidade(nomeMod, participantesM, quantidadeE);
        if(resultado == 1) m->setResultado(participantesM);

        CompeticaoSimples* c = new CompeticaoSimples(nomeComp, participantes, quantidade, m);
        in.close();
        return c;

       };
};

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c){

ofstream out;

out.open(arquivo);

if(!out.good()) throw new invalid_argument("Problema na alocacao do arquivo");

out << c->getQuantidadeDeEquipes() << " ";

for(int i  = 0; i < c->getQuantidadeDeEquipes(); i++) out << c->getEquipes()[i]->getNome() << " ";

out << '\n';
out << c->getNome() << " ";
out << '\n';

CompeticaoSimples* s = dynamic_cast<CompeticaoSimples*>(c);

if(s != NULL){

        out << 0 << " ";
        out << '\n';
        out << s->getModalidade()->getNome() << " ";
        out << '\n';

        if(s->getModalidade()->temResultado()){

                out << 1 << " ";
                out << s->getModalidade()->getQuantidadeDeEquipes() << " ";

                for(int j = 0; j < s->getModalidade()->getQuantidadeDeEquipes(); j++) out << s->getModalidade()->getTabela()->getEquipesEmOrdem()[j]->getNome() << " ";

       } else{
            out << 0 << " ";
            out << s->getModalidade()->getQuantidadeDeEquipes() << " ";

            for(int j = 0; j < s->getModalidade()->getQuantidadeDeEquipes(); j++) out << s->getModalidade()->getEquipes()[j]->getNome() << " ";
             };
} else{

    CompeticaoMultimodalidades* s = dynamic_cast<CompeticaoMultimodalidades*>(c);

    out << 1 << " ";
    out << '\n';

    list<Modalidade*>::iterator i = s->getModalidades()->begin();
    int contador = 0;

    while(i != s->getModalidades()->end()) {
        contador++;
        i++;
    };

    out << contador << " ";
    out << '\n';

    list<Modalidade*>::iterator j = s->getModalidades()->begin();

    while(j != s->getModalidades()->end()){

        out << (*j)->getNome() << " ";
        out << '\n';

        if((*j)->temResultado()){

            out << 1 << " ";
            out << (*j)->getQuantidadeDeEquipes() << " ";

            for(int k = 0; k < (*j)->getQuantidadeDeEquipes(); k++) out << (*j)->getTabela()->getEquipesEmOrdem()[k]->getNome() << " ";
        } else{

            out << 0 << " ";
            out << (*j)->getQuantidadeDeEquipes() << " ";

            for(int k = 0; k < (*j)->getQuantidadeDeEquipes(); k++) out << (*j)->getEquipes()[k]->getNome() << " ";
        };
        out << '\n';
        j++;
    };
 };
};



