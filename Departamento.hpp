#pragma once

class Departamento{
  private:
    char nome[130];
    Departamento* pDptos;
    Disciplina *pDisciplPrim;
    Disciplina *pDisciplAtual;
  public:
    Departamento();
    ~Departamento();
    void setNome(char* n);
    char* getNome();
    void setUniversidade(Universidade* u);
    Universidade* getUniversidade();
    void incluaDisciplina(Disciplina* d);
    void listeDisciplinas();
    void listeDisciplinas2();
};