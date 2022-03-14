#include <stdio.h>
#include <stdlib.h>

int main(){
  
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    char jogo[3][3];

    do{ 
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                jogo[l][c] = ' ';
            }
        }

        do{ 
            
            printf("\n\n\t 0   1   2\n\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(c == 0)
                        printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if(c < 2)
                        printf("|");
                    if(c == 2)
                        printf("  %d", l);
                }
                if(l < 2)
                    printf("\n\t-----------");
                printf("\n");
            }

            
            do{
                printf("\nPLAYER 1 = O\nPLAYER 2 = X\n");
                printf("\nPLAYER %d: Digite a linha e a coluna que deseja jogar: ", jogador);
                scanf("%d%d", &linha, &coluna);
            }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

            
            if(jogador == 1){
                jogo[linha][coluna] = 'O';
                jogador++;
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;
          system("clear");
          
// Vitória Linha
            if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
               jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
               jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
                printf("\nWin! O player 1 venceu por linha!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
               jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
               jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nWin! O player 2 venceu por linha!\n");
                ganhou = 1;
            }

// Vitória Coluna    
            if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
               jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
               jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
                printf("\nWin! O player 1 venceu por coluna!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
               jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
               jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
                printf("\nWin! O player 2 venceu por coluna!\n");
                ganhou = 1;
            }

// Vitória Diagonaias 
            if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
                printf("\nWin! O player 1 venceu na diagonal!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nWin! O player 2 venceu na diagonal!\n");
                ganhou = 1;
            }

            
            if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
                printf("\nWin! O player 1 venceu na diagonal!\n");
                ganhou = 1;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                printf("\nWin! O player 2 venceu na diagonal!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);

       
        printf("\n\n\t 0   1   2\n\n");
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                if(c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if(c < 2)
                    printf("|");
                if(c == 2)
                    printf("  %d", l);
            }
            if(l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        if(ganhou == 0)
            printf("\nGame Over!\n");

        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
}