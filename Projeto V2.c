#include <stdio.h>
#include <math.h>

#define MAX 100 // grau máximo permitido

// Imprime o polinômio
void imprimePolinomio(int p[], int grau) {
    printf("P(x) = ");
    int primeiro = 1;
    for (int i = grau; i >= 0; i--) {
        if (p[i] != 0) {
            if (!primeiro) {
                if (p[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            } else {
                if (p[i] < 0) {
                    printf("-");
                }
                primeiro = 0;
            }

            int coef = (p[i] < 0) ? -p[i] : p[i];

            if (i == 0) {
                printf("%d", coef);
            } else if (i == 1) {
                if (coef != 1) {
                    printf("%dx", coef);
                } else {
                    printf("x");
                }
            } else {
                if (coef != 1) {
                    printf("%dx^%d", coef, i);
                } else {
                    printf("x^%d", i);
                }
            }
        }
    }
    if (primeiro) {
        printf("0"); // caso todos coeficientes sejam 0
    }
    printf("\n");
}

// Calcula o valor numérico do polinômio para x
double calculaValorPolinomio(int p[], int grau, double x) {
    double resultado = 0;
    for (int i = 0; i <= grau; i++) {
        resultado += p[i] * pow(x, i);
    }
    return resultado;
}

// Soma dois polinômios
int somaPolinomios(int p1[], int g1, int p2[], int g2, int resultado[]) {
    int grauMax;
    if (g1 > g2) {
        grauMax = g1;
    } else {
        grauMax = g2;
    }

    for (int i = 0; i <= grauMax; i++) {
        resultado[i] = 0;
        if (i <= g1) {
            resultado[i] += p1[i];
        }
        if (i <= g2) {
            resultado[i] += p2[i];
        }
    }
    return grauMax;
}


// Multiplica dois polinômios
int multiplicaPolinomios(int p1[], int g1, int p2[], int g2, int resultado[]) {
    for (int i = 0; i <= g1 + g2; i++) {
        resultado[i] = 0;
    }
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            resultado[i + j] += p1[i] * p2[j];
        }
    }
    return g1 + g2;
}

// Função para ler um polinômio do usuário
int lerPolinomio(int p[]) {
    int grau;
    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);
    for (int i = grau; i >= 0; i--) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%d", &p[i]);
    }
    return grau;
}

// Menu principal
int main() {
    int opcao;
    do {
        printf("\n===== Calculadora de Polinomios =====\n");
        printf("1 - Calcular valor do polinomio\n");
        printf("2 - Somar polinomios\n");
        printf("3 - Multiplicar polinomios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int p[MAX], grau;
            grau = lerPolinomio(p);
            double x;
            printf("Digite o valor de x: ");
            scanf("%lf", &x);
            printf("Polinomio: ");
            imprimePolinomio(p, grau);
            printf("P(%.2lf) = %.2lf\n", x, calculaValorPolinomio(p, grau, x));
        } else if (opcao == 2) {
            int p1[MAX], p2[MAX], soma[MAX];
            int g1, g2, gsoma;
            printf("Digite o primeiro polinomio:\n");
            g1 = lerPolinomio(p1);
            printf("Digite o segundo polinomio:\n");
            g2 = lerPolinomio(p2);
            gsoma = somaPolinomios(p1, g1, p2, g2, soma);
            printf("Soma: ");
            imprimePolinomio(soma, gsoma);
        } else if (opcao == 3) {
            int p1[MAX], p2[MAX], mult[MAX];
            int g1, g2, gmult;
            printf("Digite o primeiro polinomio:\n");
            g1 = lerPolinomio(p1);
            printf("Digite o segundo polinomio:\n");
            g2 = lerPolinomio(p2);
            gmult = multiplicaPolinomios(p1, g1, p2, g2, mult);
            printf("Multiplicacao: ");
            imprimePolinomio(mult, gmult);
        }
    } while (opcao != 0);

    return 0;
}
