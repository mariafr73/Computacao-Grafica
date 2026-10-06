#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

typedef struct {
    float x;
    float y;
} Vetor2D;

Vetor2D criarVetor2D(float x, float y) {
    Vetor2D v;
    v.x = x;
    v.y = y;

    return v;
}

Vetor3D criarVetor3D(float x, float y, float z) {
    Vetor3D v;
    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

float calcularNorma2D(Vetor2D v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

float calcularNorma3D(Vetor3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

int main(void) {
    char tipo[10];

    printf("Informe o tipo do vetor (2D ou 3D): ");
    scanf("%s", tipo);

    if (strcmp(tipo, "2D") == 0) {
        float x, y;

        printf("Informe as coordenadas do vetor (x y): ");
        scanf("%f %f", &x, &y);

        Vetor2D v = criarVetor2D(x, y);
        float norma = calcularNorma2D(v);

        printf("Vetor: <%.2f, %.2f>\n", v.x, v.y);
        printf("Norma do vetor: %.2f\n", norma);

    } else if (strcmp(tipo, "3D") == 0) {
        float x, y, z;

        printf("Informe as coordenadas do vetor (x y z): ");
        scanf("%f %f %f", &x, &y, &z);

        Vetor3D v = criarVetor3D(x, y, z);
        float norma = calcularNorma3D(v);

        printf("Vetor: <%.2f, %.2f, %.2f>\n", v.x, v.y, v.z);
        printf("Norma do vetor: %.2f\n", norma);

    } else {
        printf("Tipo de vetor invalido.\n");
    }

    return 0;
}