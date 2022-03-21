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
  Bolsa empresas;
  double variacao;
  int cont = 0;
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
        empresas = cadastrarEmpresa();
        system("clear");
        check = true;
        cont = 0;
        
      break;
      case 2:
        if(check == true){
          variacao = calcularVariacao(empresas);
          exibirDados(empresas, variacao);
  
          printf("\n0 - Voltar ");
          scanf("%d", &cont);
          setbuf(stdin, NULL);
          system("clear");
          }else{
          
            printf("Não a dados cadastrodos! \n\n");
            printf("0 - Voltar ");
            scanf("%d", &cont);
            setbuf(stdin, NULL);
            system("clear");
          }
      
      break;
      case 3:
        printf("Nada </3. \n");
        printf("0 - Voltar ");
        scanf("%d", &cont);
        setbuf(stdin, NULL);
        system("clear");
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