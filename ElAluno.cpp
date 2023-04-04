#include <stdio.h>

#include "ElAluno.hpp"

void ElAluno::setAluno(Aluno *pa){
  pAl = pa;
}

Aluno* ElAluno::getAluno(){
  return pAl;
}

char* ElAluno::getNome(){
  return pAl->getNome();
}