#include <stdio.h>
#include <string.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

typedef struct {
    float x;
    float y;
} Vetor2D;

Vetor2D criarVetor2D(float ax, float ay, float bx, float by) {
    Vetor2D v;
    v.x = bx - ax;
    v.y = by - ay;

    return v;
}

Vetor3D criarVetor3D(float ax, float ay, float az, float bx, float by, float bz) {
    Vetor3D v;
    v.x = bx - ax;
    v.y = by - ay;
    v.z = bz - az;

    return v;
}

int main(void) {
    char tipo[10];

    printf("Informe o tipo de vetor 2D ou 3D: ");
    scanf("%s", tipo);

    if (strcmp(tipo, "2D") == 0) {
        float ax, ay;
        float bx, by;

        printf("Informe as coordenadas do ponto inicial a (x y): ");
        scanf("%f %f", &ax, &ay);

        printf("Informe as coordenadas do ponto final b (x y): ");
        scanf("%f %f", &bx, &by);

        Vetor2D v = criarVetor2D(ax, ay, bx, by);

        printf("Vetor de a para b: <%.2f, %.2f>\n", v.x, v.y);

    } else if (strcmp(tipo, "3D") == 0) {
        float ax, ay, az;
        float bx, by, bz;

        printf("Informe as coordenadas do ponto inicial a (x y z): ");
        scanf("%f %f %f", &ax, &ay, &az);

        printf("Informe as coordenadas do ponto final b (x y z): ");
        scanf("%f %f %f", &bx, &by, &bz);

        Vetor3D v = criarVetor3D(ax, ay, az, bx, by, bz);

        printf("Vetor de a para b: <%.2f, %.2f, %.2f>\n", v.x, v.y, v.z);
    } else {
        printf("Tipo de vetor invalido.\n");
    }

    return 0;
}