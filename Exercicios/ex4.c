#include <stdio.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} Vetor2D;

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

Vetor2D calcular2D(Vetor2D a, Vetor2D b, char op) {
    Vetor2D res;

    if (op == '+') {
        res.x = a.x + b.x;
        res.y = a.y + b.y;
    } else {
        res.x = a.x - b.x;
        res.y = a.y - b.y;
    }

    return res;
}

Vetor3D calcular3D(Vetor3D a, Vetor3D b, char op) {
    Vetor3D res;

    if (op == '+') {
        res.x = a.x + b.x;
        res.y = a.y + b.y;
        res.z = a.z + b.z;
    } else {
        res.x = a.x - b.x;
        res.y = a.y - b.y;
        res.z = a.z - b.z;
    }

    return res;
}

int main(void) {
    char tipo[10];
    char op;

    printf("Informe o tipo dos vetores (2D ou 3D): ");
    scanf("%s", tipo);

    printf("Informe a operacao (+ ou -): ");
    scanf(" %c", &op);

    if (op != '+' && op != '-') {
        printf("Operacao invalida.\n");
        return 1;
    }

    if (strcmp(tipo, "2D") == 0) {
        Vetor2D a;
        Vetor2D b;
        Vetor2D res;

        printf("Informe as coordenadas do vetor a (x y): ");
        scanf("%f %f", &a.x, &a.y);

        printf("Informe as coordenadas do vetor b (x y): ");
        scanf("%f %f", &b.x, &b.y);

        res = calcular2D(a, b, op);

        printf(
            "Resultado: <%.2f, %.2f>\n",
            res.x, res.y
        );
    } else if (strcmp(tipo, "3D") == 0) {
        Vetor3D a;
        Vetor3D b;
        Vetor3D res;

        printf("Informe as coordenadas do vetor a (x y z): ");
        scanf("%f %f %f", &a.x, &a.y, &a.z);

        printf("Informe as coordenadas do vetor b (x y z): ");
        scanf("%f %f %f", &b.x, &b.y, &b.z);

        res = calcular3D(a, b, op);

        printf("Resultado: <%.2f, %.2f, %.2f>\n", res.x, res.y, res.z);
    } else {
        printf("Tipo invalido.\n");
    }

    return 0;
}