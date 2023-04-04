#include <stdio.h>

int calculaIdade();

typedef struct{
  int dia;
  int mes;
  int ano;
  int idade;
}Pessoa;

int main() {
  int dia_h, mes_h, ano_h;
  Pessoa einstein, newton;
  einstein.dia = 14;
  einstein.mes = 3;
  einstein.ano = 1879;
  einstein.idade = calculaIdade;
  newton.dia = 4;
  newton.mes = 1;
  newton.ano = 1643;
  printf("Data de hoje? DD/MM/AAA\n");
  scanf("%d/%d/%d", &dia_h, &mes_h, &ano_h);
  einstein.idade = calculaIdade(einstein, dia_h, mes_h, ano_h);
  newton.idade = calculaIdade(newton, dia_h, mes_h, ano_h);
  printf("\nEinstein = %d anos", einstein.idade);
  printf("\nNewton = %d anos\n", newton.idade);
  return 0;
}

int calculaIdade(Pessoa foo, int dia_h, int mes_h, int ano_h){
  if(foo.mes <= mes_h && foo.dia <= dia_h)
    return (ano_h - foo.ano);
  return (ano_h - foo.ano + 1);
}