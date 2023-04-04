#pragma once

class Disciplina{
  private:
    int id;
    char nome[150];
    char area_conhecimento[150];
    int numero_alunos;
    int cont_alunos;
    Departamento* pDeptoAssociado;
    ElAluno *pElAlunoPrim;
    ElAluno *pElAlunoAtual;
    ListaAlunos ObjLAlunos;
  public:
    Disciplina(int na = 45, char* ac = "");
    ~Disciplina();
    Disciplina* pProx;
    Disciplina* pAnte;
    void setId(int n);
    int getId();
    void setNome(char* n);
    char* getNome();
    void setDepartamento(Departamento* pdpto);
    Departamento* getDepartamento();
    void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();
};j