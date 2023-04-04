#include <string.h>
#include "Departamento.hpp"
#include "Universidade.hpp"

Departamento::Departamento(){
  pDisciplPrim = NULL;
  pDisciplAtual = NULL;
}

Departamento::~Departamento(){
  pDisciplPrim = NULL;
  pDisciplAtual = NULL;
}
void Departamento::setNome(char* n){
  strcpy(nome, n);
}

char* Departamento::getNome(){
  return nome;
}

void Departamento::setUniversidade(Universidade* pu){
  pUniv = pu;
}

Universidade* Departamento::getUniversidade(){
  return pUniv;
}

void Departamento::incluaDisciplina(Disciplina* pd){
  if(DisciplPrim == NULL){
    pDisciplPrim = pd;
    pDisciplAtual = pd;
  }
  else{
    pDisciplAtual->prox = pd;
    pd->pAnte = pDisciplAtual;
    pDisciplAtual = pd;
  }
}

void Departamento::listeDisciplinas(){
  Disciplina* pAux;
  pAux = pDisciplPrim;
  while (pAux != NULL){
    printf ("A disciplina %s pertence ao Departamento %s \n", pAux->getNome(), nome);
    pAux = pAux->pProx;
  }
}

void Departamento::listeDisciplinas2(){
  Disciplina* pAux;
  pAux = pDisciplAtual;
  while (pAux != NULL){
    printf(" A disciplina %s pertence ao Departamento %s \n", pAux->getNome(), nome);
    pAux = pAux->pAnte;
  }
}