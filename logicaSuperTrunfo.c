#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Carta
{
    char nome[50];
    int populacao;
    int area;
    int pib;
    int pontosTuristicos;
};

// Declaração dos métodos utilizados:
struct Carta cadastrarCarta(); // Método para cadastrar uma carta.
struct Carta randomCarta(); // Método para gerar uma carta aleatoriamente.
char* randomNomeCidade(); // Método utilizado pelo randomCarta, retorna um nome de cidade aleatório.
void exibirCarta(struct Carta carta); // Metodo para exibir uma carta. (não utilizado neste desafio mas deixei para fins de aprendizado ou uso no próximo desafio.)
void cls(); // Método para limpar a tela do terminal utilizando um comando ANSI (foi o que funcionou melhor)
char comparaValor(int valorA, int valorB); // Metodo para comparar dois valores, usado para comparar os valores das cartas e retornar uma string com o resultado da comparação '<', '>' ou '='.
void exibirComparacao(struct Carta cartaA, struct Carta cartaB); // Método para exibir uma comparação entre as duas cartas e exibir o resultado.
int clean_scanf(const char *format, void *arg); // Método criado para evitar problemas de buffer no scanf.
void clean_fgets(char *str, int size); // Método criado para evitar problemas de buffer no fgets.


int main() {
    struct Carta cartaA, cartaB;

    srand(time(NULL));
    cls();
    
    int opcao = 0;
    while(opcao != 1 && opcao != 2) {
        cls();
        printf("Bem-vindo ao Super Trunfo - Cidades!\n\n");
        printf("Escolha uma das opções:\n");
        printf("1 - Cadastrar Cartas\n");
        printf("2 - Gerar Cartas Aleatóriamente (para fins de teste)\n");
        printf("=> ");
        clean_scanf("%i", &opcao);
    }
    if(opcao == 1) {        
        cls();
        printf("Por favor, cadastre as cartas de cidades:\n\n");
        
        printf("Cidade 1:\n\n");
        cartaA = cadastrarCarta();
        cls();
    
        printf("Cidade 2:\n\n");
        cartaB = cadastrarCarta();
        cls();
    }else if(opcao == 2) {
        cartaA = randomCarta();
        cartaB = randomCarta();
    }    

    cls();
    exibirComparacao(cartaA, cartaB);    


    printf("\n\n Pressione ENTER para encerrar o programa.\n");
    getchar();

    return 0;
}

int clean_scanf(const char *format, void *arg) {  
    int result = scanf(format, arg);
    while (getchar() != '\n');
    return result;
}

void clean_fgets(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

void cls() {
    printf("\033[H\033[J");
}

char comparaValor(int valorA, int valorB) {
    if (valorA > valorB) {
        return '>';
    } else if (valorA < valorB) {
        return '<';
    } else {
        return '=';
    }
}

char* randomNomeCidade() {
    static char nomes[10][50] = {
        "Sao Paulo", "Rio de Janeiro", "Belo Horizonte", "Salvador", "Curitiba",
        "Fortaleza", "Manaus", "Brasilia", "Vitoria", "Goiania"
    };
    int index = rand() % 10;
    return nomes[index];
}


struct Carta randomCarta() {
    struct Carta carta;
    strcpy(carta.nome, randomNomeCidade());
    carta.populacao = rand() % 100;
    carta.area = rand() % 100;
    carta.pib = rand() % 100;
    carta.pontosTuristicos = rand() % 100;
    return carta;
}

struct Carta cadastrarCarta() {
    struct Carta novaCarta;
    printf("# Cadastro de Cidades #\n");
    printf("-----------------------\n");
    printf("Qual o nome da cidade?\n=> ");
    clean_fgets(novaCarta.nome, sizeof(novaCarta.nome));

    printf("Qual a populacao da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.populacao);

    printf("Qual a área da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.area);

    printf("Qual o PIB da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.pib);

    printf("Qual a quantidade de pontos turísticos da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.pontosTuristicos);
    return novaCarta;
}

void exibirCarta(struct Carta carta) {
    printf("###################################\n");
    printf("#         CARTA DE CIDADE         #\n");
    printf("###################################\n");
    printf("Cidade: ------------ %s\n", carta.nome);
    printf("População: --------- %i\n", carta.populacao);
    printf("Área: -------------- %i\n", carta.area);
    printf("PIB: --------------- %i\n", carta.pib);
    printf("Pontos Turísticos: - %i\n", carta.pontosTuristicos);
    printf("###################################\n");
}

void exibirComparacao(struct Carta cartaA, struct Carta cartaB) {
    char resultado[2] = "";
    int pontosA = 0, pontosB = 0;

    printf("########################################################\n");
    printf("#         COMPARANDO CARTAS DE CIDADES                 #\n");
    printf("# Regras:                                              #\n");
    printf("# Cada atributo maior vale um ponto.                   #\n");
    printf("# Atributos iguais não contam.                         #\n");
    printf("# A cidade com mais pontos vence.                      #\n");
    printf("########################################################\n\n");
    printf("%s VS %s\n", cartaA.nome, cartaB.nome);

    printf("-------------------------------------------------\n");
    resultado[0] = comparaValor(cartaA.populacao, cartaB.populacao);
    resultado[1] = '\0';
    if( resultado[0] == '>' ) pontosA++;
    if( resultado[0] == '<' ) pontosB++;
    printf("População: --------- %i %s %i\n", cartaA.populacao, resultado, cartaB.populacao);

    resultado[0] = comparaValor(cartaA.area, cartaB.area);
    resultado[1] = '\0';
    if( resultado[0] == '>' ) pontosA++;
    if( resultado[0] == '<' ) pontosB++;
    printf("Área: -------------- %i %s %i\n", cartaA.area, resultado, cartaB.area);

    resultado[0] = comparaValor(cartaA.pib, cartaB.pib);
    resultado[1] = '\0';
    if( resultado[0] == '>' ) pontosA++;
    if( resultado[0] == '<' ) pontosB++;
    printf("PIB: --------------- %i %s %i\n", cartaA.pib, resultado, cartaB.pib);

    resultado[0] = comparaValor(cartaA.pontosTuristicos, cartaB.pontosTuristicos);
    resultado[1] = '\0';
    if( resultado[0] == '>' ) pontosA++;
    if( resultado[0] == '<' ) pontosB++;
    printf("Pontos Turísticos: - %i %s %i\n", cartaA.pontosTuristicos, resultado, cartaB.pontosTuristicos);
    printf("#################################################\n\n");

    if( pontosA > pontosB ) {
        printf("A cidade vencedora é: %s\n com %i pontos\n", cartaA.nome, pontosA);
    } 
    if( pontosA < pontosB ) {
        printf("A cidade vencedora é: %s com %i pontos\n", cartaB.nome, pontosB);
    }
    if( pontosA == pontosB ) {
        printf("As duas cidades empataram com %i pontos.\n", pontosA);
    }
}
