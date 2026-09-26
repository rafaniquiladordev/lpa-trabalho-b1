#include <stdio.h>

float calcularValorBase(float distancia);
float calcularAdicionarPeso(float peso, float subtotal);
float calcularAdicionalModalidade(int modalidade, float subtotal);
float calcularValorFinal(float subtotal, float adicionalPeso,
                         float adicionarModalidade, int protecao,
                         int tentativas);

int main() {

    float distancia;
    float peso;
    float subtotal;
    float adicionarPeso;
    float adicionarModalidade;
    float valorFinal;
    float valorBase;

    int modalidade;
    int protecao;
    int tentativas;
    int continuar;

    int totalEntregas = 0;
    int qtdEconomica = 0;
    int qtdExpressa = 0;
    int qtdPrioritaria = 0;

    float valorTotal = 0.0;
    float maiorValor = 0.0;
    float menorValor = 0.0;

    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n");

    do {

        /* Entrada e validacao da distancia */
        do {
            printf("\nDigite a distancia em km: ");
            scanf("%f", &distancia);

            if (distancia <= 0) {
                printf("Distancia invalida. Digite um valor maior que zero.\n");
            }

        } while (distancia <= 0);


        /* Entrada e validacao do peso */
        do {
            printf("Digite o peso em kg: ");
            scanf("%f", &peso);

            if (peso <= 0) {
                printf("Peso invalido. Digite um valor maior que zero.\n");
            }

        } while (peso <= 0);


        /* Entrada e validacao da modalidade */
        do {
            printf("\n1 - Economica\n");
            printf("2 - Expressa\n");
            printf("3 - Prioritaria\n");
            printf("Escolha a modalidade: ");
            scanf("%d", &modalidade);

            if (modalidade < 1 || modalidade > 3) {
                printf("Modalidade invalida. Escolha 1, 2 ou 3.\n");
            }

        } while (modalidade < 1 || modalidade > 3);


        /* Entrada e validacao da protecao */
        do {
            printf("\nDeseja contratar protecao?\n");
            printf("1 - Sim\n");
            printf("0 - Nao\n");
            printf("Escolha: ");
            scanf("%d", &protecao);

            if (protecao != 0 && protecao != 1) {
                printf("Opcao invalida. Digite 0 ou 1.\n");
            }

        } while (protecao != 0 && protecao != 1);


        /* Entrada e validacao das tentativas */
        do {
            printf("\nDigite a quantidade de tentativas adicionais: ");
            scanf("%d", &tentativas);

            if (tentativas < 0) {
                printf("Quantidade invalida. Digite zero ou um valor positivo.\n");
            }

        } while (tentativas < 0);


        /* Calculos */
        valorBase = calcularValorBase(distancia);

        subtotal = valorBase + (distancia * 1.20);

        adicionarPeso = calcularAdicionarPeso(peso, subtotal);

        adicionalModalidade =
            calcularAdicionarModalidade(modalidade, subtotal);

        valorFinal = calcularValorFinal(
            subtotal,
            adicionalPeso,
            adicionalModalidade,
            protecao,
            tentativas
        );


        /* Atualizacao dos dados da sessao */
        totalEntregas++;
        valorTotal += valorFinal;

        if (totalEntregas == 1) {
            maiorValor = valorFinal;
            menorValor = valorFinal;
        } else {

            if (valorFinal > maiorValor) {
                maiorValor = valorFinal;
            }

            if (valorFinal < menorValor) {
                menorValor = valorFinal;
            }
        }


        /* Contagem por modalidade */
        if (modalidade == 1) {
            qtdEconomica++;
        } else if (modalidade == 2) {
            qtdExpressa++;
        } else {
            qtdPrioritaria++;
        }


        /* Resultado da entrega */
        printf("\n------------------------------------\n");
        printf("Valor final da entrega: R$ %.2f\n", valorFinal);
        printf("------------------------------------\n");


        /* Pergunta se deseja continuar */
        do {
            printf("\nDeseja processar outra entrega?\n");
            printf("1 - Sim\n");
            printf("0 - Nao\n");
            printf("Escolha: ");
            scanf("%d", &continuar);

            if (continuar != 0 && continuar != 1) {
                printf("Opcao invalida. Digite 0 ou 1.\n");
            }

        } while (continuar != 0 && continuar != 1);

    } while (continuar == 1);


    /* Resumo final */
    printf("\n\n====================================\n");
    printf("          RESUMO DA SESSAO\n");
    printf("====================================\n");

    printf("Total de entregas: %d\n", totalEntregas);

    printf("Valor total: R$ %.2f\n", valorTotal);

    printf("Valor medio: R$ %.2f\n",
           valorTotal / totalEntregas);

    printf("\nEntregas Economicas: %d\n", qtdEconomica);
    printf("Entregas Expressas: %d\n", qtdExpressa);
    printf("Entregas Prioritarias: %d\n", qtdPrioritaria);

    printf("\nMaior valor de entrega: R$ %.2f\n", maiorValor);
    printf("Menor valor de entrega: R$ %.2f\n", menorValor);

    printf("====================================\n");

    return 0;
}


/* Funcao que identifica o valor-base pela distancia */
float calcularValorBase(float distancia) {

    if (distancia <= 5) {
        return 8.00;
    } else if (distancia <= 15) {
        return 12.00;
    } else if (distancia <= 30) {
        return 18.00;
    } else {
        return 25.00;
    }
}


/* Funcao que calcula o adicional de peso */
float calcularAdicionarPeso(float peso, float subtotal) {

    float percentual;

    if (peso <= 2) {
        percentual = 0.00;
    } else if (peso <= 5) {
        percentual = 0.05;
    } else if (peso <= 10) {
        percentual = 0.10;
    } else {
        percentual = 0.20;
    }

    return subtotal * percentual;
}


/* Funcao que calcula o adicional da modalidade */
float calcularAdicionalrodalidade(int modalidade, float subtotal) {

    float percentual;

    if (modalidade == 1) {
        percentual = 0.00;
    } else if (modalidade == 2) {
        percentual = 0.15;
    } else {
        percentual = 0.30;
    }

    return subtotal * percentual;
}


/* Funcao que calcula o valor final */
float calcularValorFinal(float subtotal, float adicionarPeso,
                         float adicionarModalidade, int protecao,
                         int tentativas) {

    float valorProtecao = 0.00;
    float valorTentativas;

    if (protecao == 1) {
        // protecao // 
        valorProtecao = 7.50;
    }

     valorTentativas = tentativas  * 4.00;
    
    return subtotal
           + adicionarPeso
           + adicionarModalidade
           + valorProtecao
           + valorTentativas;
    
}