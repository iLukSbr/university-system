#pragma once

#include "Pessoa.hpp"

class Departamento;

class Aluno:public Pessoa{
  private:
    int RA;
  public:
    Aluno();
    ~Aluno();
    void setRA(int ra);
    int getRA();
};