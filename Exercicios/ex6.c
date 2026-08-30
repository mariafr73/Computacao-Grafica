#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Vetor2D;

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

float produtoInterno2D(Vetor2D a, Vetor2D b) {
    return a.x * b.x + a.y * b.y;
}

float produtoInterno3D(Vetor3D a, Vetor3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vetor2D normalizar2D(Vetor2D v) {
    Vetor2D resultado;
    float norma = sqrt(v.x * v.x + v.y * v.y);

    resultado.x = v.x / norma;
    resultado.y = v.y / norma;

    return resultado;
}

Vetor3D normalizar3D(Vetor3D v) {
    Vetor3D resultado;

    float norma = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

    resultado.x = v.x / norma;
    resultado.y = v.y / norma;
    resultado.z = v.z / norma;

    return resultado;
}

int main(void) {
    char tipo[10];
    int op;

    printf("Informe o tipo do vetor (2D ou 3D): ");
    scanf("%9s", tipo);

    printf("\nEscolha a operacao:\n");
    printf("1 - Calcular produto interno\n");
    printf("2 - Transformar em vetor unitario\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (strcmp(tipo, "2D") == 0) {
        if (op == 1) {
            Vetor2D a;
            Vetor2D b;
            float produto;

            printf("Informe o vetor a (x y): ");
            scanf("%f %f", &a.x, &a.y);

            printf("Informe o vetor b (x y): ");
            scanf("%f %f", &b.x, &b.y);

            produto = produtoInterno2D(a, b);

            printf("Produto interno: %.2f\n", produto);

            if (produto == 0) {
                printf("Os vetores sao ortogonais.\n");
            } else {
                printf("Os vetores nao sao ortogonais.\n");
            }
        } else if (op == 2) {
            Vetor2D v;
            Vetor2D res;
            float norma;

            printf("Informe o vetor (x y): ");
            scanf("%f %f", &v.x, &v.y);

            norma = sqrt(v.x * v.x + v.y * v.y);

            if (norma == 0) {
                printf("O vetor nulo nao pode ser normalizado.\n");
                return 1;
            }

            res = normalizar2D(v);

            printf("Vetor unitario: <%.4f, %.4f>\n", res.x, res.y);
        } else {
            printf("Operacao invalida.\n");
        }
    } else if (strcmp(tipo, "3D") == 0) {
        if (op == 1) {
            Vetor3D a;
            Vetor3D b;
            float produto;

            printf("Informe o vetor a (x y z): ");
            scanf("%f %f %f", &a.x, &a.y, &a.z);

            printf("Informe o vetor b (x y z): ");
            scanf("%f %f %f", &b.x, &b.y, &b.z);

            produto = produtoInterno3D(a, b);

            printf("Produto interno: %.2f\n", produto);

            if (produto == 0) {
                printf("Os vetores sao ortogonais.\n");
            } else {
                printf("Os vetores nao sao ortogonais.\n");
            }

        } else if (op == 2) {
            Vetor3D v;
            Vetor3D res;
            float norma;

            printf("Informe o vetor (x y z): ");
            scanf("%f %f %f", &v.x, &v.y, &v.z);

            norma = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

            if (norma == 0) {
                printf("O vetor nulo nao pode ser normalizado.\n");
                return 1;
            }

            res = normalizar3D(v);

            printf("Vetor unitario: <%.4f, %.4f, %.4f>\n", res.x, res.y, res.z);
        } else {
            printf("Operacao invalida.\n");
        }

    } else {
        printf("Tipo invalido.\n");
    }

    return 0;
}