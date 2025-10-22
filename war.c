#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o número máximo de territórios que podem ser cadastrados
#define MAX_TERRITORIOS 5 

// Define o tamanho máximo das strings (nomes e cores)
#define TAM_STRING 100

// Estrutura que representa um território do jogo
struct Territorio {
    char nome[TAM_STRING];         // Nome do território
    char corExercito[TAM_STRING];  // Cor do exército que ocupa o território
    int numTropas;                 // Número de tropas no território
};

// Função para limpar o buffer de entrada (evita problemas ao ler strings após números)
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[MAX_TERRITORIOS]; // Vetor que armazena os territórios cadastrados

    // Exibe o título do programa
    printf("===========================\n");
    printf("  CADASTRO DE TERRITÓRIOS\n");
    printf("===========================\n\n");

    // Loop para cadastrar os territórios automaticamente 
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        // Lê o nome do território
        printf("Nome do Territorio: ");
        fgets(territorios[i].nome, TAM_STRING, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        // Lê a cor do exército
        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(territorios[i].corExercito, TAM_STRING, stdin);
        territorios[i].corExercito[strcspn(territorios[i].corExercito, "\n")] = '\0';

        // Lê o número de tropas
        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].numTropas);
        limparBufferEntrada(); // Limpa o buffer após ler o número

        printf("\n");
    }

    // Exibe o relatório final com todos os territórios cadastrados
    printf("\n==============================\n");
    printf(" MAPA DO MUNDO - ESTADO ATUAL \n");
    printf("==============================\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("-------------------------\n");
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].corExercito);
        printf("Número de Tropas: %d\n", territorios[i].numTropas);
    }

    printf("-------------------------\n");
    printf("CADASTRO TOTAL: %d\n", MAX_TERRITORIOS);

    return 0;
}