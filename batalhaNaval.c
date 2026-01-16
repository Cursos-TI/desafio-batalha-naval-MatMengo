#include <stdio.h>

int main() {
    char coluna_rotulo[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa o tabuleiro com zeros (Água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definição dos Navios (Tamanho 3)
    int navioH[3] = {3, 3, 3}; // Navio Horizontal
    int navioV[3] = {3, 3, 3}; // Navio Vertical

    // Coordenadas iniciais (Linha e Coluna)
    int linhaH = 2, colunaH = 1; // Navio Horizontal na linha 3 (índice 2)
    int linhaV = 5, colunaV = 5; // Navio Vertical na coluna F (índice 5)

    // Validação de Limites e Sobreposição
    int erro = 0;

    // Validar Navio Horizontal
    if (colunaH < 0 || colunaH + 3 > 10 || linhaH < 0 || linhaH >= 10) {
        printf("Erro: Navio Horizontal fora dos limites!\n");
        erro = 1;
    }

    // Validar Navio Vertical
    if (linhaV < 0 || linhaV + 3 > 10 || colunaV < 0 || colunaV >= 10) {
        printf("Erro: Navio Vertical fora dos limites!\n");
        erro = 1;
    }

    // Se dentro dos limites, posicionar e verificar sobreposição
    if (!erro) {
        // Posicionar Horizontal
        for (j = 0; j < 3; j++) {
            tabuleiro[linhaH][colunaH + j] = navioH[j];
        }

        // Posicionar Vertical (verificando se já existe um navio (3) no local)
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                printf("Erro: Os navios estao se sobrepondo!\n");
                erro = 1;
                break;
            }
            tabuleiro[linhaV + i][colunaV] = navioV[i];
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
