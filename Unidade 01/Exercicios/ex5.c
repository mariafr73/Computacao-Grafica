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

Vetor2D multiplicar2D(Vetor2D v, float escalar) {
    Vetor2D res;

    res.x = v.x * escalar;
    res.y = v.y * escalar;

    return res;
}

Vetor3D multiplicar3D(Vetor3D v, float escalar) {
    Vetor3D res;

    res.x = v.x * escalar;
    res.y = v.y * escalar;
    res.z = v.z * escalar;

    return res;
}

Vetor2D normalizar2D(Vetor2D v) {
    Vetor2D res;
    float norma = sqrt(v.x * v.x + v.y * v.y);

    res.x = v.x / norma;
    res.y = v.y / norma;

    return res;
}

Vetor3D normalizar3D(Vetor3D v) {
    Vetor3D res;
    float norma = sqrt(
        v.x * v.x +
        v.y * v.y +
        v.z * v.z
    );

    res.x = v.x / norma;
    res.y = v.y / norma;
    res.z = v.z / norma;

    return res;
}

int main(void) {
    char tipo[10];
    int op;

    printf("Informe o tipo do vetor (2D ou 3D): ");
    scanf("%s", tipo);

    printf("\nEscolha a op:\n");
    printf("1 - Multiplicar por escalar\n");
    printf("2 - Normalizar\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (strcmp(tipo, "2D") == 0) {
        Vetor2D v;
        Vetor2D res;

        printf("Informe as coordenadas do vetor (x y): ");
        scanf("%f %f", &v.x, &v.y);

        if (op == 1) {
            float escalar;

            printf("Informe o escalar: ");
            scanf("%f", &escalar);

            res = multiplicar2D(v, escalar);

            printf(
                "Resultado: <%.2f, %.2f>\n",
                res.x, res.y
            );

        } else if (op == 2) {
            float norma = sqrt(v.x * v.x + v.y * v.y);

            if (norma == 0) {
                printf("O vetor nulo nao pode ser normalizado.\n");
                return 1;
            }

            res = normalizar2D(v);

            printf("Vetor normalizado: <%.4f, %.4f>\n", res.x, res.y);

        } else {
            printf("Operacao invalida.\n");
        }

    } else if (strcmp(tipo, "3D") == 0) {
        Vetor3D v;
        Vetor3D res;

        printf("Informe as coordenadas do vetor (x y z): ");
        scanf("%f %f %f", &v.x, &v.y, &v.z);

        if (op == 1) {
            float escalar;

            printf("Informe o escalar: ");
            scanf("%f", &escalar);

            res = multiplicar3D(v, escalar);

            printf("Resultado: <%.2f, %.2f, %.2f>\n", res.x, res.y, res.z);

        } else if (op == 2) {
            float norma = sqrt(
                v.x * v.x +
                v.y * v.y +
                v.z * v.z
            );

            if (norma == 0) {
                printf("O vetor nulo nao pode ser normalizado.\n");
                return 1;
            }

            res = normalizar3D(v);

            printf("Vetor normalizado: <%.4f, %.4f, %.4f>\n", res.x, res.y, res.z);

        } else {
            printf("Operacao invalida.\n");
        }

    } else {
        printf("Tipo invalido.\n");
    }

    return 0;
}