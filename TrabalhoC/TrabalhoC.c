#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
    int escolha;

    printf("\nMENU:\n");
    printf("1 - Calcular fatorial\n");
    printf("2 - Leitor de palindromos\n");
    printf("3 - Numero de 1's\n");
    printf("4 - Imprimir uma string sem as vogais\n");
    printf("5 - Converter letras maiusculas em minusculas\n");
    printf("6 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    return escolha;
}

int calcularFatorial() {
    int numero;
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &numero);

    int fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    printf("O fatorial de %d é: %d\n", numero, fatorial);

    printf("Pressione qualquer tecla para voltar ao menu...");
    getchar();
    getchar();
    system("cls");
    return 0;
}

int ehPalindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (fim > inicio) {
        while (!isalpha(str[inicio])) {
            inicio++;
        }
        while (!isalpha(str[fim])) {
            fim--;
        }

        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0;
        }

        inicio++;
        fim--;
    }
    return 1;
}

int leitorPalindromo() {
    char str[100];

    printf("Digite uma string: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (ehPalindromo(str)) {
        printf("A string \"%s\" é um palindromo.\n", str);
    } else {
        printf("A string \"%s\" não é um palindromo.\n", str);
    }

    printf("Pressione qualquer tecla para voltar ao menu...");
    getchar();
    system("cls");
    return 0;
}

int contarUns(char str[]) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '1') {
            count++;
        }
        i++;
    }

    return count;
}

int numeroDeUns() {
    char str[100];

    printf("Digite uma string contendo 1's e 0's: ");
    scanf("%s", str);

    int numero_de_uns = contarUns(str);

    printf("O número de 1's na string \"%s\" é: %d\n", str, numero_de_uns);

    printf("Pressione qualquer tecla para voltar ao menu...");
    getchar();
    getchar();
    system("cls");
    return 0;
}

void removerVogais(char str[]) {
    int i, j = 0;
    char novaString[strlen(str) + 1];

    for (i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
            novaString[j] = str[i];
            j++;
        }
    }
    novaString[j] = '\0';

    printf("String sem vogais: %s\n", novaString);
}

int imprimirSemVogais() {
    char str[100];

    printf("Digite uma string: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    removerVogais(str);

    return 0;
}

void converterMinusculas(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }

    printf("String em minusculas: %s\n", str);
}

int maiusculaParaMinuscula() {
    char str[100];

    printf("Digite uma string: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    converterMinusculas(str);

    return 0;
}

int main() {
    int escolha;

    do {
        escolha = menu();

        switch (escolha) {
            case 1:
                calcularFatorial();
                break;
            case 2:
                leitorPalindromo();
                break;
            case 3:
                numeroDeUns();
                break;
            case 4:
                imprimirSemVogais();
                break;
            case 5:
                maiusculaParaMinuscula();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}
