#include <stdio.h>

#include "Principal.hpp"

Principal::Principal(){
// leitura da data atual
  
// Inicialização do(s) ojeto(s) da classe Pessoa
  Christiano.Inicializa(17, 8, 1989, "Zé Maria");
  Diego.Inicializa(6, 10, 1989, "Diego");
  Simao.Inicializa(3, 10, 1976, "Jean Simão");
  Einstein.Inicializa(14, 3, 1879, "Albert Einstein");
  Newton.Inicializa(4, 1, 1643, "Isaac Newton");
// Registro do(s) nome(s) da(s) universidade(s)
  UTFPR.setNome("Universidade Tecnologica Federal do Paraná");
  Princeton.setNome("University of Princeton");
  Cambridge.setNome("University of Cambridge");
// Registro do(s) nome(s) do(s) departamento(s)
  ModaUFTPR.setNome("Moda");
  TecnologiaUTFPR.setNome("Tecnologia da UTFPR");
  DAELN.setNome("Eletronica da UTFPR");
  FisicaPrinceton.setNome("Fisica de Princenton");
  MatematicaCambridge.setNome("Matematica de Cambridge");
// "Agregação" do(s) Departamento(s) a(s) Univesidade(s).
  UTFPR.setDepartamento(&DAELN, 0);
  UTFPR.setDepartamento(&ModaUTFPR, 1);
  UTFPR.setDepartamento(&TecnologiaUTFPR, 2);
  Princeton.setDepartamento(&FisicaPrinceton, 0);
  Cambridge.setDepartamento(&MatematicaCambridge, 0);
// "Filiação" a universidade. Christiano.setUnivFiliado ( &UTFPR );
  Diego.setUnivFiliado(&UTFPR);
  Simao.setUnivFiliado(&UTFPR);
  Einstein.setUnivFiliado(&Princeton);
  Newton.setUnivFiliado(&Cambridge);
  printf("\n");
// "Filiação" ao departamento.
  Christiano.setDepartamento(&ModaUFTPR);
  Diego.setDepartamento(&TecnologiaUTFPR);
  Simao.setDepartamento(&DAELN);
  Einstein.setDepartamento(&FisicaPrinceton);
  Newton.setDepartamento(&MatematicaCambridge);
  printf ("\n");
}

void Principal::InicializaDisciplinas(){
  Computacao1_2006.setNome("Computacao I 2006");
  Introd_Alg_2007.setNome("Introducao de Algoritmos de Programacao 2007");
  Computacao2_2007.setNome("Computacao II");
  Metodos2_2007.setNome("Métodos II");
  Computacao1_2006.setDepartamento(&DAELN);
  Introd_Alg_2007.setDepartamento(&DAELN);
  Computacao2_2007.setDepartamento(&DAELN);
  Metodos2_2007.setDepartamento(&DAELN);
  Metodos2_2007.incluaAluno(&AAA);
  Metodos2_2007.incluaAluno(&BBB);
  Metodos2_2007.incluaAluno(&CCC);
  Metodos2_2007.incluaAluno(&DDD);
  Metodos2_2007.incluaAluno(&EEE);
  Computacao2_2007.incluaAluno(&AAA);
  Computacao2_2007.incluaAluno(&EEE);
  Computacao2_2007.incluaAluno(&FFF);
}

void Departamento::incluaDisciplina(Disciplina* pd){
  if(pDisciplPrim == NULL){
    pDisciplPrim = pd;
    pDisciplAtual = pd;
  }
  else{
    pDisciplAtual->pProx = pd;
    pDisciplAtual = pd;
  }
}

void Principal::CalcIdadeProfs(){
// Cálculo da idade.
  Simao.Calc_Idade(diaAtual, mesAtual, anoAtual);
  Einstein.Calc_Idade(diaAtual, mesAtual, anoAtual);
  Newton.Calc_Idade(diaAtual, mesAtual, anoAtual);
  printf("\n");
}

void Principal::UnivOndeProfsTrabalham(){
// Universidade que a Pessoa trabalha.
  Simao.OndeTrabalho();
  Einstein.OndeTrabalho();
  Newton.OndeTrabalho();
  printf("\n");
}

void Principal::DepOndeProfsTrabalham(){
// Departamento que a Pessoa trabalha.
  Simao.QualDepartamentoTrabalho();
  Einstein.QualDepartamentoTrabalho();
  Newton.QualDepartamentoTrabalho();
  printf("\n");
}

void Principal::ListeDiscDeptos(){
  DAELN.listeDisciplinas();
  printf("\n");
}

void Principal::Executar(){
  CalcIdadeProfs();
  UnivOndeProfsTrabalham();
  DepOndeProfsTrabalham();
  ListeDepPorUniv();
// Metodos2.listeAlunos();
  ListeDiscDeptos();
}

void Principal::ListeDiscDeptos(){
  DAELN.listeDisciplinas();
  printf("\n");
}

void Principal::ListeAlunosDisc(){
  Metodos2_2007.listeAlunos();
  printf("\n");
  Metodos2_2007.listeAlunos2();
  printf("\n");
}

void Principal::Executar(){
  CalcIdadeProfs();
  UnivOndeProfsTrabalham();
  DepOndeProfsTrabalham();
  ConhecPessoa();
  ListeDiscDeptos();
  ListeAlunosDisc();
  Menu();
}

void Principal::Menu(){
  int op = -1;
  while(op != 3){
    system("cls");
    cout << "Informe sua opcao:" << endl;
    cout << "1 - Cadastrar." << endl;
    cout << "2 - Executar." << endl;
    cout << "3 – Sair." << endl;
    cin >> op;
    switch(op){
      case 1:{
        MenuCad();
      }
      break;
      case 2:{
        MenuExe();
      }
      break;
      case 3:{
        cout << "FIM" << endl;
      }
      break;
      default:{
        cout << "Opcao invalida." << endl;
        getchar();
        system("Pause");
      }
    }
  }
}

void Principal::MenuCad(){
  int op = -1;
  while(op != 5){
    system("cls");
    cout << "Informe sua opcao:" << endl;
    cout << "1 - Cadastrar Disciplina." << endl;
    cout << "2 - Cadastrar Departamentos." << endl;
    cout << "3 - Cadastrar Universidade." << endl;
    cout << "4 - Cadastrar Aluno." << endl;
    cout << "5 – Sair. " << endl;
    cin >> op;
    switch(op){
      case 1:{
        CadDisciplina();
      }
      break;
      case 2:{
        CadDepartamento();
      }
      break;
      case 3:{
        CadUniversidade();
      }
      break;
      case 4:{
        CadAluno();
      }
      break;
      case 5:{
        cout << " FIM " << endl;
      }
      break;
      default:{
        cout << "Opcao Invalida - Pressione uma tecla." << endl;
        getchar();
      }
    }
  }
}

void Principal::MenuGravar(){
  int op = -1;
  while(op != 6){
    system("cls");
    cout << "Informe sua opcao:" << endl;
    cout << "0 - Gravar tudo." << endl;
    cout << "1 - Gravar universidades." << endl;
    cout << "2 - Gravar departamentos." << endl;
    cout << "3 - Gravar disciplinas." << endl;
    cout << "4 - Gravar alunos." << endl;
    cout << "5 - Gravar professores." << endl;
    cout << "6 – Sair." << endl;
    cin >> op;
    switch (op){
      case 0:{
        GravarTudo();
      }
      break;
      case 1:{
        GravarUniversidades();
      }
      break;
      case 2:{
        GravarDepartamentos();
      }
      break;
      case 3:{
        GravarDisciplinas();
      }
      break;
      case 4:{
        GravarAlunos ();
      }
      break;
      case 5;{
        GravarProfessores ();
      }
      break;
      case 6:{
        cout << "FIM" << endl;
      }
      break;
      default:{
        cout << "Opção invalida, pressione uma tecla para continuar." << endl;
        getchar();
      }
    }
  }
}

void Principal::MenuRecuperar(){
  int op = -1;
  while(op!= 6){
    system("cls");
    cout << "Informe sua opcao:" << endl;
    cout << "0 - Recuperar tudo." << endl;
    cout << "1 - Recuperar universidades." << endl;
    cout << "2 - Recuperar departamentos." << endl;
    cout << "3 - Recuperar disciplinas." << endl;
    cout << "4 - Recuperar alunos." << endl;
    cout << "5 - Recuperar professores." << endl;
    cout << "6 – Sair." << endl;
    cin >> op;
    switch(op){
      case 0:{
        RecuperarTudo();
      }
      break;
      case 1:{
        RecuperarUniversidades();
      }
      break;
      case 2:{
        RecuperarDepartamentos();
      }
      break;
      case 3:{
        RecuperarDisciplinas();
      }
      break;
      case 4:{
        RecuperarAlunos();
      }
      break;
      case 5:{
        RecuperarProfessores();
      }
      break;
      case 6:{
        cout << " FIM " << endl;
      }
      break;
      default:{
        cout << "Opção invalida, pressione uma tecla para continuar." << endl;
        getchar();
      }
    }
  }
}

void Principal::RecuperarAlunos(){
  LAlunos.recupereAlunos();
}

void Principal::GravarAlunos(){
  LAlunos.graveAlunos();
}

void Principal::CadAluno(){
  char nomeAluno[150];
  int ra;
  Aluno* pal;
  cout << "Qual o nome do aluno?" << endl;
  cin >> nomeAluno;
  cout << "Qual o RA do aluno?“ << endl;
  cin >> ra;
  pal = new Aluno(cont_idAluno++);
  pal->setNome(nomeAluno);
  pal->setRA(ra);
  LAlunos.incluaAluno(pal);
}

void Principal::CadDepartamento(){
  char nomeUniversidade[150];
  char nomeDepartamento[150];
  Universidade* univ;
  Departamento* depart;
  cout << "Qual o nome da universidade do departamento?" << endl;
  cin >> nomeUniversidade;
  univ = LUniversidades.localizar(nomeUniversidade);
  if (univ != NULL){
    cout << "Qual o nome do departamento" << endl;
    cin >> nomeDepartamento;
    depart = new Departamento();
    depart->setNome(nomeDepartamento);
    depart->setUniversidade(univ);
    LDepartamentos.incluaDepartamento(depart);
  }
  else
    cout << "Universidade inexistente." << endl;
}