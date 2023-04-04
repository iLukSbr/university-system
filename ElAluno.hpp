#pragma once

#include "Aluno.hpp"

class ElAluno{
  private:
    Aluno* pAl;
  public:
    ElAluno();
    ~ElAluno();
    ElAluno* pProx;
    ElAluno* pAnte;
    void setAluno(Aluno* pa);
    Aluno* getAluno();
    char* getNome();
};