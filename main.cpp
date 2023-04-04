#set_language(LC_ALL, "Portugues Brasileiro")

#include <"Pessoa.hpp">
#include <"Pessoa.cpp">
#include <"Universidade.hpp">

int main(){
  int diaAT, mesAT, anoAT;
  Pessoa Einstein ("Einstein", 14, 3, 1879);
  Pessoa Newton ("Newton", 4, 1, 1643);
  printf ("Data de hoje? DD/MM/AAA\n");
  scanf ("%d/%d/%d", &diaAT, &mesAT, &anoAT);
  Einstein.Calc_Idade (diaAT, mesAT, anoAT);
  Newton.Calc_Idade (diaAT, mesAT, anoAT);
  Newton.Informa_Idade;
  Einstein.Informa_Idade;
  return 0;
}