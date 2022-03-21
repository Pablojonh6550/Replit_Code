#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão_01

typedef struct {
char nome[50];
int matricula;
float nota1;
float nota2;
}Aluno;

Aluno inserirDados(){
  Aluno aux;

  
  printf("\n| Insira o nome do aluno: ");
  fflush(stdin);
  fgets(aux.nome, 40, stdin);
  setbuf(stdin,NULL);
  printf("| Digite a matricula do aluno: ");
  scanf("%d", &aux.matricula);
  setbuf(stdin,NULL);
  printf("| Digite a nota um do aluno: ");
  scanf("%f", &aux.nota1);
  setbuf(stdin,NULL);
  printf("| Digite a nota dois do aluno: ");
  scanf("%f", &aux.nota2);
  setbuf(stdin,NULL);
  return aux;
}
void mostrarDados(Aluno aluno) {
    float media = (aluno.nota1 + aluno.nota2) / 2;

      printf("\n---------Dados---------- \n");
      printf("Nome do aluno: %s", aluno.nome);
      printf("Matricula: %d \n", aluno.matricula);
      printf("Média do aluno: %g \n\n", media);
    
}

int main(void) {
  int tam = 2;
  int cont = 0;
  int confirmar = 0;
  Aluno aluno[tam];

  do{
    printf("---Menu--- \n");
    printf("1 - Cadastrar Aluno \n");
    printf("2 - Tabela de alunos \n");
    printf("3 - Sair \n");
    printf("Digite uma opção: ");
    scanf("%d", &cont);
    setbuf(stdin,NULL);
    system("clear");

    switch(cont){
      case 1:
        for(int i = 0; i<tam; i++){
        aluno[i] = inserirDados();
        system("clear");
        }
        cont = 0;
        confirmar = 1;
      break;
      
      case 2:
        if(confirmar == 1){
          for(int i = 0; i<tam; i++){
          mostrarDados(aluno[i]); 
          }

          printf("\n");
          printf("0 - Voltar \n");
          printf("Digite uma opção: ");
          scanf("%d", &cont);
          setbuf(stdin,NULL);
          system("clear");
          
          }else{
            printf("Sem dados inseridos! \n\n");
            printf("0 - Voltar \n");
            printf("Digite uma opção: ");
            scanf("%d", &cont);
            setbuf(stdin,NULL);
            system("clear");
          }
      break;
      
      default:
      printf("Opção inválida! \n");
      sleep(1);
      system("clear");
      cont = 0;
      
    
  }
  }while(cont == 0 && cont != 3);

}