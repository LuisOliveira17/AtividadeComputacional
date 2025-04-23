#include <stdio.h>
#include <math.h>

void Permutacao() {
    int numero = 0, numeroExibir = 0;
    int multermos = 1;

    printf("Digite um numero inteiro >= 0 para executar o fatorial: ");
    scanf("%d", &numero);

    numeroExibir = numero;

    if (numero < 0) {
        printf("Numero invalido! Digite um valor maior ou igual a 0.\n");
        return;
    }

    if (numero >= 17) {
        printf("A maquina apenas executa com exatidao numeros abaixo de 17. Tente novamente.\n");
        return;
    }

    // Calcular o fatorial
    for (int i = 1; i <= numero; i++) {
        multermos *= i;
    }

    printf("Fatorial de %d: %d\n\n", numeroExibir, multermos);
}

void Arranjo() {
    int n, k, numerador = 1, fatorialDenominador = 1;

    printf("Digite o numero de elementos (n): ");
    scanf("%d", &n);
    printf("Digite o numero de posicoes (k) n>=k: ");
    scanf("%d", &k);

    while (n < k || k == 0) {
        if (n < k) {
            printf("n deve ser maior ou igual a k. Digite n novamente: ");
            scanf("%d", &n);
        }
        if (k == 0) {
            printf("k deve ser no mínimo 1. Digite k novamente: ");
            scanf("%d", &k);
        }
    }

    // Calcula n!
    for (int i = 1; i <= n; i++) {
        numerador *= i;
    }

    // Calcula (n - k)!
    for (int i = 1; i <= (n - k); i++) {
        fatorialDenominador *= i;
    }

    printf("\nArranjo A(%d,%d): %d\n\n", n, k, numerador / fatorialDenominador);
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

    printf("Digite o numero de elementos(n):");
    scanf("%d", &n);
    printf("Digite o numero de posicoes (k) k>0:");
    scanf("%d", &k);

    while (k == 0) {
        if (k == 0) {
            printf("Digite um valor valido para k (min. 1): ");
            scanf("%d", &k);
        }
    }
    int resultado = (int) pow(n, k);
    printf("Arranjo COM repeticao:%d", resultado);
}

void PermutacaoComRepeticao() {
    int quantLetras = 0, quantRep = 0, inserirArray = 0;
    int elementos[50] = {0};

    printf("Digite a quantidade total de letras:");
    scanf("%d", &quantLetras);

    printf("Informe quantas letras se repetem \n(Ex: 'ARARA'- 2 letras se repetem(A e R):");
    scanf("%d", &quantRep);

    for (int i = 0; i <= quantRep - 1; i++) {
        //quantRep-1 pois o i começa em 0 e usarei ele para povoar o array
        printf("Quantas vezes a letra %d se repete:", i);
        scanf("%d", &inserirArray);
        elementos[i] = inserirArray;
    }

    //Calculando o numerador (fatorial de quantLetras):
    int numerador = 1;

    for (int n = 1; n <= quantLetras; n++) {
        numerador *= n;
    }

    printf("\nRepeticoes informadas: ");
    for (int i = 0; i < quantRep; i++) {
        printf("%d ", elementos[i]);
    }

    // Calculando o denominador (fatorial de cada indice do Vetor):

    int denominador = 1;

    for (int x = 0; x < quantRep; x++) {
        int valor = elementos[x];
        int fat = 1;

        for (int j = 1; j <= valor; j++) {
            fat *= j; // calcula o fatorial de 'valor'
        }

        printf("\nFatorial de %d = %d", valor, fat);
        denominador *= fat; // multiplica no acumulador
    }
    printf("\nNumerador: %d\n", numerador);
    printf("Denominador final (produto dos fatoriais): %d\n", denominador);
    printf("\nPossibildiades COM repeticao: %d", (numerador / denominador));
}

void combinacaoComRepeticao() {
    int n = 0, k = 0;
    int numerador = 1, denominador = 1;;

    printf("Digite o numero de elementos(n):");
    scanf("%d", &n);
    printf("Digite o numero de posicoes (k):");
    scanf("%d", &k);

    //Calculo de numerador
    for (int i = 1; i <= (n + k - 1); i++) {
        numerador *= i;
    }

    //Calculo de denominador
    for (int x=1;x<=(n-1);x++) {
        denominador *= x;

            if (x==(n-1)) {
                for (int j=1;j<=k;j++) {
                    denominador *= j;
                }
            }
    }
    printf("%d\n", numerador);
    printf("%d\n", denominador);
    printf("C(%d,%d)=%d", n, k, numerador / denominador);
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
