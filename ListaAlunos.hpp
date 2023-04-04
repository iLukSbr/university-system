#pragma once

#include "ElDisciplina.hpp"
#include "Disciplina.hpp"
#include "Elemento.hpp"
#include "Aluno.hpp"

class ListaAlunos{
  private:
    int cont_alunos;
    int numero_alunos;
    char nome[150];
    Elemento<Aluno> *pElAlunoPrim;
    Elemento<Aluno> *pElAlunoAtual;
  public:
    ListaAlunos(int na = -1, char* n = "");
    ~ListaAlunos();
    void limpaLista();
    void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();
    void graveAlunos();
    void recupereAlunos();
};