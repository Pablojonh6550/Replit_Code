#include <iostream>
#include <string.h>
using namespace std;

//Struct 
struct Jogador {
  string nome;
  int idade;
  int peso;
};
// Criar uma função declarando seu tipo com a da struct
Jogador inserirDados(){
  // usar uma variavel auxiliar para atribuir o dados
  Jogador p; 
  
  std::cout << "Insira seu nome: ";
  std::cin >> p.nome;

  cout << "Insira sua idade: ";
  cin >> p.idade;

  cout << "Insira seu peso: ";
  cin >> p.peso;

  //Retornar essa variavel com o dados atribuidos
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

  // Atribuir a função por inteiro a variavel struct
  player = inserirDados();
  
  system("clear");
  mostrarDados(player);
  
  return 0;
}