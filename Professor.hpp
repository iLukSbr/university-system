#pragma once

#include "Pessoa.hpp"
#include "Universidade.hpp"

class Professor:public Pessoa{
 private:
  Universidade* pUnivFiliado;
  Departamento* pDptoFiliado;
 public:
  Professor(int diaNa, int mesNa, int anoNa, char* nome = "");
  Professor();
  ~Professor();
  void setUnivFiliado(Universidade* pu);
  void setDepartamento(Departamento* pdpto);
  void OndeTrabalho();
  void QualDepartamentoTrabalho();
}