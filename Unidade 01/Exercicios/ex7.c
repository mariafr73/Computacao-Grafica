#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

Vetor3D produtoVetorial(Vetor3D a, Vetor3D b) {
    Vetor3D res;

    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;

    return res;
}

int main(void) {
    char tipo[10];
    Vetor3D a;
    Vetor3D b;
    Vetor3D res;

    printf("Informe o tipo dos vetores (2D ou 3D): ");
    scanf("%9s", tipo);

    if (strcmp(tipo, "2D") == 0) {
        printf("Informe o vetor a (x y): ");
        scanf("%f %f", &a.x, &a.y);

        printf("Informe o vetor b (x y): ");
        scanf("%f %f", &b.x, &b.y);

        a.z = 0;
        b.z = 0;

    } else if (strcmp(tipo, "3D") == 0) {
        printf("Informe o vetor a (x y z): ");
        scanf("%f %f %f", &a.x, &a.y, &a.z);

        printf("Informe o vetor b (x y z): ");
        scanf("%f %f %f", &b.x, &b.y, &b.z);

    } else {
        printf("Tipo invalido.\n");
        return 1;
    }

    res = produtoVetorial(a, b);

    printf("Produto vetorial: <%.2f, %.2f, %.2f>\n", res.x, res.y, res.z);

    if (
        fabs(res.x) < 0.0001 &&
        fabs(res.y) < 0.0001 &&
        fabs(res.z) < 0.0001
    ) {
        printf("Os vetores sao paralelos.\n");
    } else {
        printf("Os vetores nao sao paralelos.\n");
    }

    return 0;
}