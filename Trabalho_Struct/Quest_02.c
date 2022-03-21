#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char nome_empresa[100];
  char area_de_atuacao[100];
  double valor_acao_atual;
  double valor_acao_passado;
}Bolsa;

Bolsa cadastrarEmpresa() {
  Bolsa aux;
  
  printf("--Cadastro de Empresa-- \n");
  printf("\n| Digite o nome da empresa: ");
  fflush(stdin);
  fgets(aux.nome_empresa, 100, stdin);
  setbuf(stdin, NULL);

  printf("| Digite a área de atuação: ");
  fflush(stdin);
  fgets(aux.area_de_atuacao, 100, stdin);
  setbuf(stdin, NULL);

  printf("| Digite o valor de suas ações atual: ");
  scanf("%lf",&aux.valor_acao_atual);
  setbuf(stdin, NULL);

  printf("| Digite o valor de suas ações passado: ");
  scanf("%lf",&aux.valor_acao_passado);
  setbuf(stdin, NULL);

  return aux;
}

double calcularVariacao(Bolsa empresas) {
  double result;

  result = ( empresas.valor_acao_atual/empresas.valor_acao_passado-1) * 100;
  
  return result;
}

void exibirDados(Bolsa empresas,double variacao) {
  
  printf("\n---| Dados Empresas |---\n");
  printf("Empresa %s", empresas.nome_empresa);
  printf("Área de atuação %s", empresas.area_de_atuacao);
  printf("Valor em ações atual: %lf \n", empresas.valor_acao_atual);
  printf("Volar das ações passada: %lf \n", empresas.valor_acao_passado);
  printf("Variação ultimo mês: %lg'%' \n", variacao);
  
}

int main() {
  int tam = 4;
  Bolsa empresas[tam];
  double variacao;
  int cont = 0;
  int contl = 0;
  bool check = false;

  do{
    printf("\n---| Menu |---\n");
    printf("1 - Cadastrar Empresa\n");
    printf("2 - Consultar\n");
    printf("3 - Laço \n");
    printf("4 - Sair \n");
    printf("Digite uma opção: ");
    scanf("%d", &cont);
    setbuf(stdin, NULL);
    system("clear");
    
    switch(cont) {
      case 1:
        empresas[0] = cadastrarEmpresa();
        system("clear");
        check = true;
        cont = 0;
        
      break;
      case 2:
        if(check == true){
          
          variacao = calcularVariacao(empresas[0]);
          exibirDados(empresas[0], variacao);
          
          printf("\n0 - Voltar ");
          scanf("%d", &cont);
          setbuf(stdin, NULL);
          system("clear");
          }else{
          
            printf("Não a dados cadastrados! \n\n");
            printf("0 - Voltar ");
            scanf("%d", &cont);
            setbuf(stdin, NULL);
            system("clear");
          }
      
      break;
      case 3:
        do{
          
          printf("\n---| Menu Laços|---\n");
          printf("1 - Cadastrar Empresa\n");
          printf("2 - Consultar\n");
          printf("3 - Voltar \n");
          printf("Digite uma opção: ");
          scanf("%d", &contl);
          setbuf(stdin, NULL);
          system("clear");

          switch(contl){
            case 1:
              for(int i = 1; i<tam; i++) {
                  empresas[i] = cadastrarEmpresa();
                  system("clear");
                  check = true;
                  contl = 0;
              }
            break;

            case 2:
              if(check == true){
                for(int i = 1; i<tam; i++){
                  variacao = calcularVariacao(empresas[i]);
                  exibirDados(empresas[i], variacao);
                }
                printf("\n0 - Voltar ");
                scanf("%d", &contl);
                setbuf(stdin, NULL);
                system("clear");
              }else{
          
                printf("Não a dados cadastrados! \n\n");
                printf("0 - Voltar ");
                scanf("%d", &contl);
                setbuf(stdin, NULL);
                system("clear");
              } 
            break;

            case 3:
              cont = 0;
              contl = 3;
            break;
            
            default:
              printf("Digite uma opção válida!");
              sleep(1);      
              contl = 0;
              system("clear");

          }
        }while(contl == 0 && contl != 3);
        
      break;

      default:
      if(cont == 4){
        cont = 4;
      }else{
        printf("Digite uma opção válida!");
        sleep(1);
        system("clear");
        cont = 0;
      }
    }
    
  }while(cont == 0 && cont != 4);
  
}