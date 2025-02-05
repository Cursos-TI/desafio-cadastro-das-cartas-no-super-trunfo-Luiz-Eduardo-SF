#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    int codigo, populacao, PIB, pontos_tu; // Cria variaveis de valores inteiros
    char nome[50]; // Cria uma variavel que pode armazenar uma string
    float area; // Cria um valor numerico com casas decimais
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    printf("Digite o nome da cidade: ");
    fgets(nome, 50, stdin); 

    printf("Digite a população: ");
    scanf("%d", &populacao);
    
    printf("Digite a área: ");
    scanf("%f", &area);
    
    printf("Digite o PIB: ");
    scanf("%d", &PIB);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_tu);
    
    printf("Digite o código da cidade: "); // Pede para digitar um valor
    scanf("%d", &codigo); // Armazena o valor digitado na variavel
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // Escreve as caracteristicas da carta no terminal
    printf("\n|| Informações da carta: ||\n");
    printf(">> Nome da cidade: %s", nome);
    printf(">> População: %d\n", populacao);
    printf(">> Área por km²: %.2f\n", area);
    printf(">> PIB: %d\n", PIB);
    printf(">> Qnt. Pontos Turisticos: %d\n", pontos_tu);
    printf(">> Código da cidade: %d\n", codigo);

    return 0;
}
