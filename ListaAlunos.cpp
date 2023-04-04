#include "stdafx.hpp"
#include "ListaAlunos.hpp“

ListaAlunos::ListaAlunos(int na, char* n){
  numero_alunos = na;
  cont_alunos = 0;
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
  strcpy(nome, n);
}

ListaAlunos::~ListaAlunos(){
  ElAluno *paux1, *paux2;
  paux1 = pElAlunoPrim;
  paux2 = paux1;
  while(paux1 != NULL){
    paux2 = paux1->pProx;
    delete (paux1);
    paux1 = paux2;
  }
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
}

void ListaAlunos::incluaAluno(Aluno* pa){
  if((cont_alunos < numero_alunos) && (pa != NULL)){
    ElAluno* paux = NULL;
    paux = new ElAluno();
    paux->setAluno(pa);
    if(pElAlunoPrim == NULL){
      pElAlunoPrim = paux;
      pElAlunoAtual = paux;
    }
    else{
      pElAlunoAtual->pProx = paux;
      paux->pAnte = pElAlunoAtual;
      pElAlunoAtual = paux;
    }
    cont_alunos++;
    cout << "Aluno incluido com sucesso."<< endl;
  }
  else{
    if(pa != NULL){
      cout << "Aluno nao incluido. Turma ja lotada em " << numero_alunos << " alunos." << endl;
    }
    else{
      cout << "Ponteiro do Aluno esta nulo!" << endl;
    }
  }
}

void ListaAlunos::listeAlunos()
{
  Aluno *pauxAl = NULL;
  Elemento < Aluno > *pauxEL = NULL;
  pauxEL = pElAlunoPrim;
  while (pauxEL != NULL){
    pauxAl = pauxEL->getInfo();
    cout << "Aluno " << pauxAl->getNome() << " matriculado na Disciplina " << nome << "." << endl;
    pauxEL = pauxEL->getProximo();
  }
}

void ListaAlunos::listeAlunos2(){
  ElAluno* paux = NULL;
  paux = pElAlunoAtual;
  while (paux != NULL){
// printf (" Aluno %s matriculado na Disciplina %s \n", paux->getNome(), nome);
    cout << "Aluno " << paux->getNome() << " matriculado na disciplina " << nome << "." << endl;
    paux = paux->pAnte;
  }
}

void ListaAlunos::graveAlunos{
  ofstream GravadorAlunos("alunos.dat", ios::out);
  if (!GravadorAlunos){
    cerr << "Arquivo nao pode ser aberto" << endl;
    fflush(stdin);
    getchar();
    return;
  }
  ElAluno* pauxElAluno = NULL;
  Aluno * pauxAluno = NULL;
  pauxElAluno = pElAlunoPrim;
  while(pauxElAluno != NULL){
    pauxAluno = pauxElAluno->getAluno();
    GravadorAlunos << pauxAluno->getId() << ' ' << pauxAluno->getRA() << ' ' << pauxAluno->getNome() << endl;
    pauxElAluno = pauxElAluno->pProx;
  }
  GravadorAlunos.close();
}

void ListaAlunos::recupereAlunos(){
  ifstream RecuperadorAlunos("alunos.dat", ios::in);
  if(!RecuperadorAlunos){
    cerr << "Arquivo nao pode ser aberto" << endl;
    fflush(stdin);
    getchar();
    return;
  }
  limpaLista();
  while(!RecuperadorAlunos.eof()){
    Aluno * pauxAluno = NULL;
    int id;
    int RA;
    char nome[150];
    RecuperadorAlunos >> id >> RA >> nome;
    if(0 != strcmp(nome, "")){
      pauxAluno = new Aluno(-1);
      pauxAluno->setId(id);
      pauxAluno->setRA(RA);
      pauxAluno->setNome(nome);
      incluaAluno(pauxAluno);
    }
  }
  RecuperadorAlunos.close();
}