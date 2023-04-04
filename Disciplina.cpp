#include "Disciplina.hpp"
#include <stdio.h>
#include <string.h>

Disciplina::Disciplina(int na, char* ac):ObjLAlunos(na, ac){
  pDeptoAssociado = NULL;
  pAlunoPrim = NULL;
  pAlunoAtual = NULL;
  pProx = NULL;
  pAnte = NULL;
  cont_alunos = 0;
  numero_alunos = na;
  strcpy(area_conhecimento, ac);
}

Disciplina::~Disciplina(){
  ElAluno* paux;
  paux = pElAlunoPrim;
  while(NULL != pElAlunoPrim){
    pElAlunoPrim = pElAlunoPrim->pProx;
    delete paux;
    paux = pElAlunoPrim;
  }
  pDeptoAssociado = NULL;
  pElAlunoAtual = NULL;
}

void Disciplina::setId(int n){
  id = n;
}

int Disciplina::getId(){
  return id;
}

void Disciplina::setNome(char* n){
  strcpy(nome, n);
}
  
char* Disciplina::getNome(){
  return nome;
}

void Disciplina::setDepartamento(Departamento* pdpto){
  pDeptoAssociado = pdpto;
// Cada vez que um Departamento é associado a uma Disciplina,
// esta Disciplina passa a fazer parte da lista de disciplina
// do Departamento, por meio do comando abaixo.
  pdpto->incluaDisciplina(this);
}

Departamento* Disciplina::getDepartamento(){
  return pDeptoAssociado;
}

void Disciplina::incluaAluno (Aluno* pa){
  ElAluno* paux;
  paux = new ElAluno();
  paux->setAluno(pa);
  if(cont_alunos<numero_alunos && pa!=NULL){
    if(pAlunoPrim == NULL){
      pAlunoPrim = paux;
      pAlunoAtual = paux;
    }
    else{
      pElAlunoAtual->pProx = pa;
      paux->pAnte = pElAlunoAtual;
      pElAlunoAtual = pa;
    }
    cont_alunos++;
  }
  else
    printf ("Aluno não incluído, turma já lotada em %i alunos. \n", nume);
}

void Disciplina::listeAlunos(){
  ElAluno* paux;
  paux = pElAlunoPrim;
  while(paux != NULL){
    printf("Aluno %s matriculado em %s \n", paux->getNome(), nome);
    paux = paux->pProx;
  }
}

void Disciplina::listeAlunos2(){
  ElAluno* paux;
  paux = pElAlunoAtual;
  while(paux != NULL){
    printf("Aluno %s matriculado em %s \n", paux->getNome(), nome);
    paux = paux->pAnte;
  }
}