#pragma once

#include "Departamento.hpp"

class Universidade{
  private:
    char nome[130];
    Departamento* pDptos;
  public:
    Universidade();
    ~Universidade();
    void setNome(char* n = " ");
    char* getNome();
    void setDepartamento(Departamento* pdep, int ctd);
};