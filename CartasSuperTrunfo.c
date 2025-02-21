#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta com dados sobre uma cidade
typedef struct {
    char estado[3];  // Armazena a sigla do estado (ex: SP, RJ, MG)
    char cidade[50]; // Nome da cidade
    char codigo[11]; // Código identificador da carta
    int populacao;   // População da cidade
    int pontostu;    // Número de pontos turísticos
    float area;      // Área da cidade em km²
    float PIB;       // Produto Interno Bruto da cidade
    float PIBperCap; // PIB per capita
    float pessoaKm;  // Densidade populacional (habitantes por km²)
    float superPoder; // Indicador fictício baseado nos outros atributos
} Carta;

// Função para limpar o buffer do teclado após entrada de dados
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função que faz a coleta dos dados das cartas
void coletarDadosCarta(Carta *carta) {
    printf("================================================================================\n");
    printf("Digite o estado da carta (2 letras): ");    // Pede o valor 
    fgets(carta->estado, sizeof(carta->estado), stdin); // Armazena o valor digitado na propriedade certa
    carta->estado[strcspn(carta->estado, "\n")] = '\0'; // Remove o '\n' do final
    printf("================================================================================\n");
    printf("Digite a cidade da carta (até 50 letras): ");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0'; // Remove o '\n' do final
    printf("================================================================================\n");
    printf("Digite o código da carta (11 letras): ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0'; // Remove o '\n' do final
    printf("================================================================================\n");
    printf("Digite a população da carta: "); // Pede o valor
    scanf("%d", &carta->populacao); // Armazena o valor 
    limparBuffer(); // Limpa o buffer
    printf("================================================================================\n");
    printf("Digite o número de pontos turísticos da carta: ");
    scanf("%d", &carta->pontostu);
    limparBuffer();
    printf("================================================================================\n");
    printf("Digite a área da carta: ");
    scanf("%f", &carta->area);
    limparBuffer();
    printf("================================================================================\n");
    printf("Digite o PIB da carta: ");
    scanf("%f", &carta->PIB);
    limparBuffer();
    printf("================================================================================\n");
}

// Faz todos os calculos usados no programa
void calcularIndicadores(Carta *carta) { 
    carta->PIBperCap = carta->PIB / carta->populacao; // Calcula o PIB per Capita
    carta->pessoaKm = carta->populacao / carta->area; // Calcula a qnt. de pessoa por km²
    carta->superPoder = carta->PIB + carta->PIBperCap + carta->pessoaKm + carta->populacao + carta->pontostu; // Soma as informações para o Super poder
}

// Função que escreve o resultado na tela
void compararCartas(Carta carta1, Carta carta2) {
    printf("\nResultados:"); 
    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado
    printf("\nEstado: %s (carta 1) vs %s (carta 2)", carta1.estado, carta2.estado); // escreve os valores das duas cartas
    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado
    printf("\nCidade: %s (carta 1) vs %s (carta 2)", carta1.cidade, carta2.cidade);
    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado
    printf("\nCódigo: %s (carta 1) vs %s (carta 2)", carta1.codigo, carta2.codigo);
    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    // Compara o valor de cada propriedade das cartas e escreve diferentes mensagens com base no vencedor ou caso de empate

    if (carta1.populacao > carta2.populacao){ // Se a população da carta 1 for maior que a da carta 2
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Carta 1 Venceu", carta1.populacao, carta2.populacao); // Mensagem que a carta 1 vence
    }else if (carta1.populacao < carta2.populacao){ // Caso a carta 2 seja maior
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Carta 2 Venceu", carta1.populacao, carta2.populacao); // Mensagem que a carta 2 vence
    }else{ // Caso nenhuma seja maior que a outra (igual)
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Empate!!!", carta1.populacao, carta2.populacao); // Mensagem de empate
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.pontostu > carta2.pontostu){
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Carta 1 Venceu", carta1.pontostu, carta2.pontostu);
    }else if (carta1.pontostu < carta2.pontostu){
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Carta 2 Venceu", carta1.pontostu, carta2.pontostu);
    }else{
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Empate!!!", carta1.pontostu, carta2.pontostu);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.area > carta2.area){
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.area, carta2.area);
    }else if (carta1.area < carta2.area){
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.area, carta2.area);
    }else{
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.area, carta2.area);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.PIB > carta2.PIB){
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.PIB, carta2.PIB);
    }else if (carta1.PIB < carta2.PIB){
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.PIB, carta2.PIB);
    }else{
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.PIB, carta2.PIB);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.PIBperCap > carta2.PIBperCap){
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.PIBperCap, carta2.PIBperCap);
    }else if (carta1.PIBperCap < carta2.PIBperCap){
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.PIBperCap, carta2.PIBperCap);
    }else{
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.PIBperCap, carta2.PIBperCap);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.pessoaKm < carta2.pessoaKm){
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.pessoaKm, carta2.pessoaKm);
    }else if (carta1.pessoaKm > carta2.pessoaKm){
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.pessoaKm, carta2.pessoaKm);
    }else{
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.pessoaKm, carta2.pessoaKm);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

    if (carta1.superPoder > carta2.superPoder){
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.superPoder, carta2.superPoder);
    }else if (carta1.superPoder < carta2.superPoder){
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.superPoder, carta2.superPoder);
    }else{
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.superPoder, carta2.superPoder);
    }

    printf("\n================================================================================"); // Espaçamento para ficar mais organizado e bonito na hora do resultado

}

// Função Principal
int main() {
    Carta carta1, carta2; 

    // Coleta as informações para cada carta e calcula cada carta tbm
    printf("================================================================================\n");
    printf("Digite os dados da carta 1\n");
    coletarDadosCarta(&carta1); 
    calcularIndicadores(&carta1);

    printf("================================================================================\n");
    printf("\nDigite os dados da carta 2\n");
    coletarDadosCarta(&carta2);
    calcularIndicadores(&carta2);

    // Compara as duas cartas
    compararCartas(carta1, carta2);

    return 0;
}