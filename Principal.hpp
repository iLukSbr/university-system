#pragma once

#include "Pessoa.hpp"
#include "Universidade.hpp"
#include "ListaUniversidades.hpp"
#include "ListaDepartamentos.hpp"
#include "ListaDisciplinas.hpp"
#include "Aluno.hpp"

class Principal{
  private:
// Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;
// Departamentos
    Departamento DAELN;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;
    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;
    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;
    Disciplina Computacao1_2006;
    Disciplina Introd_Alg_2007;
    Disciplina Computacao2_2007;
    Disciplina Metodos2_2007;
    Aluno AAA;
    Aluno BBB;
    Aluno CCC;
    Aluno DDD;
    Aluno EEE;
    int diaAtual;
    int mesAtual;
    int anoAtual;
  public:
    Principal();
    // Inicializações...
    void Inicializa();
    void InicializaUnivesidades();
    void InicializaDepartamentos();
    void InicializaProfessores();
    void InicializaAlunos();
    void InicializaDisciplinas();
    void Executar();
    void CalcIdadeProfs();
    void UnivOndeProfsTrabalham();
    void DepOndeProfsTrabalham();
    void ConhecPessoa();
    void ListeDiscDeptos();
    void ListaAlunoDisc();
};