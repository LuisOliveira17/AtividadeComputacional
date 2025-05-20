#include <stdio.h>
#include <math.h>

void Permutacao() {
    int numero, resultado = 1;

    do {
        printf("Digite um numero inteiro >= 0 para executar o fatorial: ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("Numero invalido.Digite um valor maior ou igual a 0.\n");
        } else if (numero >= 17) {
            printf("A maquina apenas executa com exatidao numeros abaixo de 17. Tente novamente.\n");
            numero = -1; // força repetição
        }

    } while (numero < 0);

    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }

    printf("F(%d):%d\n\n", numero, resultado);
}

void Arranjo() {
    int n, k;
    int numerador = 1, denominador = 1;

    do {
        printf("Digite o numero de elementos (n): ");
        scanf("%d", &n);
        printf("Digite o numero de posicoes (k), com n >= k e k > 0: ");
        scanf("%d", &k);

        if (n < k || k <= 0) {
            printf("Valores invalidos Certifique de que n >= k e k > 0.\n\n");
        }
    } while (n < k || k <= 0);

    for (int i = 1; i <= n; i++) numerador *= i;
    for (int i = 1; i <= (n - k); i++) denominador *= i;

    printf("\nA(%d,%d): %d\n\n", n, k, numerador / denominador);
}

void Combinacao() {
    int n, k, tempN, tempK; //Elementos e posicoes
    int numerador = 1, denominador = 0, multermoDeno = 1, multermoK = 1;


    printf("Digite o numero de elementos(n):");
    scanf("%d", &n);
    printf("Digite o numero de posicoes (k) n>=k:");
    scanf("%d", &k);

    while (n < k || k == 0) {
        if (n < k) {
            printf("Digite um valor valido para n: ");
            scanf("%d", &n);
        }
        if (k == 0) {
            printf("Digite um valor valido para k (min. 1): ");
            scanf("%d", &k);
        }
    }

    tempN = n;
    tempK = k;

    //Calculo do k!
    while (tempK >= 1) {
        multermoK *= tempK;
        tempK--;
    }

    if (n >= k) {
        //Calculo Numerador (n)
        while (n >= 1) {
            numerador *= n;
            n--;
        }

        //Calculo do (n-k)!
        denominador = (tempN - k);
        while (denominador >= 1) {
            multermoDeno *= denominador;
            denominador--;
        }
    }
    printf("\nC(%d,%d)=%d", tempN, k, numerador / (multermoDeno * multermoK));
    printf("\n\n");
}

void ArranjoComRepeticao() {
    int n, k;

    do {
        printf("Digite o numero de elementos (n > 0): ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Digite o numero de posicoes (k > 0): ");
        scanf("%d", &k);
    } while (k <= 0);

    int resultado = (int) pow(n, k);
    printf("Arranjo COM repeticao: %d\n", resultado);
}

void PermutacaoComRepeticao() {
    int quantLetras = 0, quantRep = 0, inserirArray = 0;
    int elementos[50] = {0};

    // Validar quantidade total de letras
    do {
        printf("Digite a quantidade total de letras (>= 1): ");
        scanf("%d", &quantLetras);
        if (quantLetras < 1)
            printf("Valor invalido. Digite um número maior ou igual a 1.\n");
    } while (quantLetras < 1);

    // Validar número de letras que se repetem
    do {
        printf("Informe quantas letras se repetem (>= 1 e <= %d): ", quantLetras);
        scanf("%d", &quantRep);
        if (quantRep < 1 || quantRep > quantLetras)
            printf("Valor invalido. Deve estar entre 1 e %d.\n", quantLetras);
    } while (quantRep < 1 || quantRep > quantLetras);

    int somaRepeticoes = 0;

    // Validar cada repetição
    for (int i = 0; i < quantRep; i++) {
        do {
            printf("Quantas vezes a letra %d se repete (>= 2): ", i + 1);
            scanf("%d", &inserirArray);
            if (inserirArray < 2 || (somaRepeticoes + inserirArray) > quantLetras)
                printf("Valor invalido. A repetição deve ser >= 2 e soma total não pode passar de %d.\n", quantLetras);
        } while (inserirArray < 2 || (somaRepeticoes + inserirArray) > quantLetras);

        elementos[i] = inserirArray;
        somaRepeticoes += inserirArray;
    }

    // Calcular numerador
    int numerador = 1;
    for (int n = 1; n <= quantLetras; n++) {
        numerador *= n;
    }

    // Calcular denominador
    int denominador = 1;
    for (int x = 0; x < quantRep; x++) {
        int valor = elementos[x];
        int fat = 1;

        for (int j = 1; j <= valor; j++) {
            fat *= j;
        }

        printf("\nFatorial de %d = %d", valor, fat);
        denominador *= fat;
    }

    printf("\nNumerador: %d", numerador);
    printf("\nDenominador final (produto dos fatoriais): %d", denominador);
    printf("\nPossibilidades COM repeticao: %d\n\n", numerador / denominador);
}

void combinacaoComRepeticao() {
    int n = 0, k = 0;
    int numerador = 1, denominadorParte1 = 1, denominadorParte2 = 1;

    // Validar entrada de n e k
    do {
        printf("Digite o número de elementos (n >= 1): ");
        scanf("%d", &n);
        if (n < 1) printf("Valor inválido. Tente novamente.\n");
    } while (n < 1);

    do {
        printf("Digite o numero de posicoes (k >= 1): ");
        scanf("%d", &k);
        if (k < 1) printf("Valor invalido. Tente novamente.\n");
    } while (k < 1);

    int total = n + k - 1;

    // Calcular fatorial do numerador: (n + k - 1)!
    for (int i = 1; i <= total; i++) {
        numerador *= i;
    }

    // Calcular fatorial de (n - 1)
    for (int i = 1; i <= (n - 1); i++) {
        denominadorParte1 *= i;
    }

    // Calcular fatorial de k
    for (int i = 1; i <= k; i++) {
        denominadorParte2 *= i;
    }

    int denominador = denominadorParte1 * denominadorParte2;


    printf("\nNumerador: %d\n",numerador);
    printf("Denominador:%d\n",denominadorParte2);
    printf("CR(%d,%d) = %d\n\n",n,k, numerador / denominador);
}


int main(void) {
    int escolha, escolhaCase1, escolhaCase2;

    printf("\nBem vindo a calculadora de analise combinatoria!\n");
    printf("Menu Principal");
    printf("\n1. Analise Combinatoria Sem Repeticao");
    printf("\n2. Analise Combinatoria Com Repeticao");
    printf(" \n3. SAIR DO PROGRAMA");
    printf(" \nQual a opcao desejada?:");

    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            printf("Submenu: Sem Repeticao");
            printf("   1. Pn");
            printf("   2. An,k");
            printf("   3. Cn,k");
            printf("   4. Voltar ao Menu Principal");
            printf("\nQual a operacao desejada:");
            scanf("%d", &escolhaCase1);

            switch (escolhaCase1) {
                case 1:
                    Permutacao();
                    main();
                    break;
                case 2:
                    Arranjo();
                    main();
                    break;
                case 3:
                    Combinacao();
                    main();
                    break;
                case 4:
                    main();
                default:
                    printf("Escolha uma opcao válida!!\n ");
                    main();
            }

        case 2:
            printf("Submenu: Com Repeticao\n");
            printf("   1. PR(n1,n2....,nk)");
            printf("   2. AR(n,k)");
            printf("   3. CR(n,k)");
            printf("   4. VOLTAR PARA O MENU PRINCIPAL");
            printf("\nQual a operacao desejada:");
            scanf("%d", &escolhaCase2);

            switch (escolhaCase2) {
                case 1:
                    PermutacaoComRepeticao();
                    main();
                    break;
                case 2:
                    ArranjoComRepeticao();
                    main();
                    break;
                case 3:
                    combinacaoComRepeticao();
                    main();
                    break;
                case 4:
                    printf("OBRIGADO. VOLTE QUANDO PRECISAR DE MINHA AJUDA");
                    return 0;
            }
            return 0;
    }
}
