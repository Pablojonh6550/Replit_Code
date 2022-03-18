#include <stdio.h>
#include <string.h>

// Struct também conhecida como "Registros" definem tipos de dados que agrupam variáveis sob um mesmo tipo de dado.

typedef struct{
char nome[50];
int velocidade;
int habilidade;
}Jogador;

void inserirDados(Jogador player1) {
  printf("\n");
  printf("Insira  seu nome: ");
  fflush(stdin);
  fgets(player1.nome, 40, stdin);
   
  printf("Insira sua velocidade: ");
  scanf("%d",&player1.velocidade);
   
  printf("Insira sua habilidade: ");
  scanf("%d",&player1.habilidade);
  
}
void mostrarDados(Jogador player1) {
  printf("---------Dados---------- \n");
  printf("Nome: %s", player1.nome);
  printf("Velocidade: %d \n", player1.velocidade);
  printf("Habilidade: %d \n", player1.habilidade);

}

int main() {
  Jogador player1;
  
  inserirDados(player1);
  system("clear");
  // printf("Nome: %s \n", player1.nome);
  mostrarDados(player1);
  
  
}