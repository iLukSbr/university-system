#include <stdio.h>

#include "Pessoa.hpp"

Pessoa::Pessoa (int diaNa, int mesNa, int anoNa, char* nome){
  Inicializa(diaNa, mesNa, anoNa, nome);
}

void Pessoa::Inicializa (int diaNa, int mesNa, int anoNa, char* nome){
  idadeP = 0;
  diaP = diaNa;
  mesP = mesNa;
  anoP = anoNa;
  strcpy (nomeP, nome);
}

void Pessoa::Calc_Idade(int diaAT, int mesAT, int anoAT){
    idadeP = anoAT - anoP;
    if(anoAT == anoP && mesAT == mesP && diaAT < diaP)
      idadeP--;
}

void Pessoa::Informa_Idade(){
    printf("\n%s tem %d anos.\n", nomeP, idadeP);
}

int Pessoa::informaIdade(){ 
  return idadeP;
}

void Pessoa::setUnivFiliado(Universidade* pu){
  pUnivFiliado = pu;
}

void Pessoa::setDepartamento(Departamento* pdep){
// Aqui é uma associação porque é armazenado um apontamento
// para o Departamento.
  pDptoFiliado = pdep;
}

void Pessoa::OndeTrabalho(){
  cout << nomeP << “trabalha para a“ << pUnivFiliado->getNome() << "." << endl;
}

void Pessoa::QualDepartamentoTrabalho(){
  cout << nomeP << “ trabalha para a “ << pUnivFiliado->getNome() << pDptoFiliado->getNome() << "." << endl;
}