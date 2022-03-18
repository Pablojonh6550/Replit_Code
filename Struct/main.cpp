#include <iostream>
#include <string.h>
using namespace std;

struct Jogador {
  string nome;
  int idade;
  int peso;
} teste;
Jogador inserirDados(){
  Jogador p;
  std::cout << "Insira seu nome: ";
  std::cin >> p.nome;

  cout << "Insira sua idade: ";
  cin >> p.idade;

  cout << "Insira seu peso: ";
  cin >> p.peso;
  
  return p;
}

void mostrarDados(Jogador player){
  
  std::cout << "Nome: " << player.nome << '\n';
  cout << "Idade: " << player.idade << '\n';
  cout << "Peso: " << player.peso << '\n';
}

int main() {
  // std::cout << "Hello World!\n";
  Jogador player;
  
  player = inserirDados();
  
  system("clear");
  mostrarDados(player);
  
  return 0;
}