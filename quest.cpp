#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
// Jonh Pablo Vaz matricula: 202108765279
// Questão 1
bool Existe (int check[],int tam, int valor) {
    for (int i = 0;i<tam;i++) {
        if (check[i]==valor){
            return true;
        }
    }
    return false;
}

void Gerar(int numeros[],int tam){
    srand(time(NULL));

    int v;
    for (int i=0;i<tam;i++) {
        v = rand() % 10;
        while (Existe(numeros,i,v)) {
            v = rand() % 10;
        }
        numeros[i] = v;
    }

}
// Questão 2_a
void Impar(int array[],int tam) { 
  int a;
  for (int i=0; i<tam; i++){
    a = array[i];
    if (a % 2 == 1) {
      printf("É impar %d \n", a);
    } 
  } 
}

void Par(int array[],int tam) { 
  int a;
  for (int i=0; i<tam; i++){
    a = array[i];
    if (a % 2 == 0) {
      printf("É par %d \n", a);
    } 
  } 
}

// Questão 2_b
void Maior(int array[], int tam) {
  int maior = array[0];
  for(int i = 0; i < tam; i++) {
       if (array[i] > maior) {
          maior = array[i]; 
        }
    
  }
  printf("O maior é: %d \n", maior);
}
// Questão 2_c
void contarPar(int array[], int tam) {
  int quantidade = 0;
  int a;
  for (int i=0; i<tam; i++){
    a = array[i];
    if (a % 2 == 0) {
      quantidade++;
    } 
  } 
  printf("A quantidade de números pares é: %d \n", quantidade);
}
// Questão 2_d
void somarVetor(int array[], int tam) {
  int soma = 0;
  for (int i = 0; i < tam; i++) {
    soma = soma + array[i];
  }
  printf("A soma dos valores do vetor é: %d \n", soma);
}
// Questão 2_e
void inverterVetor(int array [], int tam) {
  int a;
  for ( int i = 0; i < ( tam / 2 ); i++ ) {
    a = array[i];
    array[i] = array[ (tam - 1) - i ];
    array[ (tam - 1) - i ] = a;
  }
  printf("O vetor invertido é: \n");
  
  for ( int i = 0; i < tam; i++ ){
      printf("%d\n", array[i]);
  }
}
// Questã 3
void ordemCrescente(int array[], int tam) {
  int s;
  for (int i = 0; i < tam; i++){
    for (int j = i+1; j < tam; j++)
    if (array[i] > array[j]) { 
      s = array[i]; 
      array[i] = array[j]; 
      array[j] = s ; 
    }
  }
  printf("Vetor em order crescente \n");
  for (int k = 0; k < tam; k++){
    printf("%d\n", array[k]);
  }
}


int main(){
    int tam = 10;
    int VetOriginal[tam];

    printf("Questão 1 \n");
    printf("-------------------------------- \n");  
    Gerar(VetOriginal,tam);
    for(int i = 0;i<tam;i++){
        printf("O valor é %d \n", VetOriginal[i]);
    }
    printf("-------------------------------- \n");
  
  //Quest 2
    // A
    printf("Questão 2 - A \n");
    printf("-------------------------------- \n"); 
    Impar(VetOriginal,tam);
    printf("---------\n");
    Par(VetOriginal,tam);
    printf("-------------------------------- \n");
  // B
    printf("Questão 2 - B\n");
    printf("-------------------------------- \n"); 
    Maior(VetOriginal,tam);
    printf("-------------------------------- \n");
  // C
    printf("Questão 2 - C\n");
    printf("-------------------------------- \n"); 
    contarPar(VetOriginal,tam);
    printf("-------------------------------- \n"); 
  // D
    printf("Questão 2 - D\n");
    printf("-------------------------------- \n");
    somarVetor(VetOriginal,tam);
    printf("-------------------------------- \n");
  // E
    printf("Questão 2 - E\n");
    printf("-------------------------------- \n");
    inverterVetor(VetOriginal,tam);
    printf("-------------------------------- \n");
  // 3
    printf("Questão 3\n");
    printf("-------------------------------- \n");
    ordemCrescente(VetOriginal,tam);
    printf("-------------------------------- \n");
  return 0;
}