#include <stdio.h>

void Permutacao() {
    int numero = 0;
    int multermos = 1;
    while (numero <= 0) {
        printf("Digite um numero inteiro >=0 para executar o fatorial:");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero >= 17) {
            printf("A maquina apenas executa com exatidao, numeros abaixo de 17. Tente Novamente\n");
        }
    }

    while (numero >= 1) {
        multermos = multermos * numero;
        numero--;
    }

    printf("Fatorial:%d", multermos);
    printf("\n\n");
}

void Arranjo() {
    int n, k, tempN; //Elementos e posicoes
    int numerador = 1, denominador = 0, multermoDeno = 1;


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

    if (n >= k) {
        //Calculo Numerador (n)
        while (n >= 1) {
            numerador *= n;
            n--;
        }

        denominador = (tempN - k);
        while (denominador >= 1) {
            multermoDeno *= denominador;
            denominador--;
        }
    }
    printf("\nNumerador:%d", numerador);
    printf("\nDenominador:%d", multermoDeno);
    printf("\nArranjo:%d", numerador / multermoDeno);
    printf("\n\n");
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
    printf("\nNumerador:%d", numerador);
    printf("\nDenominador:%d", multermoDeno);
    printf("\nCombinacao:%d", numerador / (multermoDeno * multermoK));
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
    printf("Arranjo sem repeticao:%d", n^k);

}

int main(void) {
    int escolha, escolhaCase1;

    printf("Bem vindo a calculadora de analise combinatoria!\n");
    printf("Menu Principal");
    printf("\n1. Sem Repeticao");
    printf("\n2. Com Repeticao");
    printf(" \n3. Sair do Programa");
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
            }

        case 2:
            printf("Submenu: Com Repeticao");
            printf("   1. PRn1,n2");
            printf("   2. ARn,k");
            printf("   3. CRn,k");
            printf("   4. Voltar ao Menu Principal");
    }
    return 0;
}
