#include <stdio.h>

int main() {
    char coluna_rotulo[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Rótulos das colunas
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa o tabuleiro com zeros (Água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // 2. Definição dos Navios (Tamanho 3)
    int navioH[3] = {3, 3, 3}; // Navio Horizontal
    int navioV[3] = {3, 3, 3}; // Navio Vertical
    int navioD1[3] = {3, 3, 3}; // Navio Diagonal 1
    int navioD2[3] = {3, 3, 3}; // Navio Diagonal 2

    // Coordenadas iniciais (Linha e Coluna)
    int linhaH = 2, colunaH = 1; // Navio Horizontal na linha 3 (índice 2)
    int linhaV = 5, colunaV = 5; // Navio Vertical na coluna F (índice 5)
    int linhaD1 = 6, colunaD1 = 0; // Navio Diagonal 1
    int linhaD2 = 1, colunaD2 = 7; // Navio Diagonal 2

    // Validação de Limites e Sobreposição
    int erro = 0;

    // Validar Navio Horizontal
    if (colunaH < 0 || colunaH + tamanhoNavio > 10 || linhaH < 0 || linhaH >= 10) {
        printf("Erro: Navio Horizontal fora dos limites!\n");
        erro = 1;
    }

    // Validar Navio Vertical
    if (linhaV < 0 || linhaV + tamanhoNavio > 10 || colunaV < 0 || colunaV >= 10) {
        printf("Erro: Navio Vertical fora dos limites!\n");
        erro = 1;
    }

    // Validar Navio Diagonal 1
    if (linhaD1 < 0 || linhaD1 + tamanhoNavio > 10 || colunaD1 < 0 || colunaD1 + tamanhoNavio > 10){
        printf("Erro: Navio Diagonal 1 fora dos limites!\n");
        erro = 1;
    }

    // Validar Navio Diagonal 2
    if (linhaD2 < 0 || linhaD2 + tamanhoNavio > 10 || colunaD2 < 0 || colunaD2 - (tamanhoNavio - 1) < 0){
        printf("Erro: Navio Diagonal 2 fora dos limites!\n");
        erro = 1;
    }
    

    // Se dentro dos limites, posicionar e verificar sobreposição
    if (!erro) {
        // Posicionar Navio Horizontal
        for (j = 0; j < tamanhoNavio; j++) {
            tabuleiro[linhaH][colunaH + j] = navioH[j];
        }

        // Posicionar Navio Vertical (verificando se já existe um navio (3) no local)
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                printf("Erro: Os navios estao se sobrepondo!\n");
                erro = 1;
                break;
            }
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }

        // Posiicionar Navio Diagonal 1 (verificando sobreposição)
       for (i = 0; i < tamanhoNavio; i++){
        int linha = linhaD1 + i;
        int coluna = colunaD1 + i;

        if (tabuleiro[linha][coluna] == 3) {
            printf("Erro: Navio Diagonal Principal sobreposto a outro navio!\n");
            erro = 1;
            break;
        }

        tabuleiro[linha][coluna] = navioD1[i];
       }
       
       // Posiicionar Navio Diagonal 2 (verificando sobreposição)
       for (i = 0; i < tamanhoNavio; i++) {
        int linha = linhaD2 + i;
        int coluna = colunaD2 - i;

        if (tabuleiro[linha][coluna] == 3) {
            printf("Erro: Navio Diagonal Secundaria sobreposto a outro navio!\n");
            erro = 1;
            break;
        }

        tabuleiro[linha][coluna] = navioD2[i];
        
       }
       
        
    }

    // 3. Exibição do Tabuleiro
    if (!erro) {
        printf("\n  JOGO DA BATALHA NAVAL\n\n");

        // Imprime o cabeçalho das colunas (A-J)
        printf("   ");
        for (i = 0; i < 10; i++) {
            printf("%c ", coluna_rotulo[i]);
        }
        printf("\n");

        // Imprime as linhas (1-10) e o conteúdo da matriz
        for (i = 0; i < 10; i++) {
            printf("%2d ", i + 1);
            for (j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
