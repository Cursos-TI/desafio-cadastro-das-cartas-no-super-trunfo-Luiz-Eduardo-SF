#include <stdio.h>

// Declarando as variáveis globais
char estado[4], cidade[50], codigo[11]; // Strings para armazenar estado, cidade e código
int populacao, pontostu;                // Inteiros para população e pontos turísticos
float area, PIB, PIBperCap, pessoaKm;   // Floats para área, PIB, PIB per capita e densidade populacional

// Função para entrada de dados
void EntradaDados() {
    printf("Digite a sigla do estado: ");
    fgets(estado, sizeof(estado), stdin); // Lê a sigla do estado (2 caracteres + '\0')

    printf("Digite o nome da cidade: ");
    fgets(cidade, sizeof(cidade), stdin); // Lê o nome da cidade

    printf("Digite o código da carta: ");
    fgets(codigo, sizeof(codigo), stdin); // Lê o código da carta

    printf("Digite o PIB do estado: ");
    scanf("%f", &PIB); // Lê o PIB

    printf("Digite a populacao do estado: ");
    scanf("%d", &populacao); // Lê a população

    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &pontostu); // Lê a quantidade de pontos turísticos

    printf("Digite a area do estado (em km²): ");
    scanf("%f", &area); // Lê a área do estado

    // Limpa o buffer do teclado após o uso do scanf
    while (getchar() != '\n');
}

// Função para calcular PIB per capita e densidade populacional
void CalculandoMedia() {
    PIBperCap = (float) PIB / populacao; // Calcula o PIB per capita
    pessoaKm = (float) populacao / area; // Calcula a densidade populacional (pessoas por km²)
}

// Função para exibir os dados
void MostrandoDados() {
    printf("\n|| Dados da Carta ||\n");
    printf(">> Estado: %s", estado); // Exibe a sigla do estado
    printf(">> Cidade: %s", cidade); // Exibe o nome da cidade
    printf(">> Código da Carta: %s", codigo); // Exibe o nome da cidade
    printf(">> Área: %.2f km²\n", area); // Exibe a área
    printf(">> População: %d\n", populacao); // Exibe a população
    printf(">> PIB: %.2f\n", PIB); // Exibe o PIB
    printf(">> Pessoas por km²: %.2f\n", pessoaKm); // Exibe a densidade populacional
    printf(">> PIB per capita: %.2f\n", PIBperCap); // Exibe o PIB per capita
}

// Função principal
int main() {
    EntradaDados(); // Chama a função para entrada de dados
    CalculandoMedia(); // Chama a função para calcular médias
    MostrandoDados(); // Chama a função para exibir os dados
    return 0; // Retorna 0 indicando sucesso
}