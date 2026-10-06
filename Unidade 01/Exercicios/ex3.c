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

Vetor2D deslocar2D(Vetor2D ponto, Vetor2D vetor, char operacao) {
    Vetor2D res;
    if (operacao == '+') {
        res.x = ponto.x + vetor.x;
        res.y = ponto.y + vetor.y;
    } else {
        res.x = ponto.x - vetor.x;
        res.y = ponto.y - vetor.y;
    }

    return res;
}

Vetor3D deslocar3D(Vetor3D ponto, Vetor3D vetor, char operacao) {
    Vetor3D res;
    if (operacao == '+') {
        res.x = ponto.x + vetor.x;
        res.y = ponto.y + vetor.y;
        res.z = ponto.z + vetor.z;
    } else {
        res.x = ponto.x - vetor.x;
        res.y = ponto.y - vetor.y;
        res.z = ponto.z - vetor.z;
    }

    return res;
}

int main(void) {
    char tipo[10];
    char op;

    printf("Informe o tipo (2D ou 3D): ");
    scanf("%s", tipo);

    printf("Informe a operacao (+ ou -): ");
    scanf(" %c", &op);

    if (op != '+' && op != '-') {
        printf("Operacao invalida.\n");
        return 1;
    }
    
    if (strcmp(tipo, "2D") == 0) {
        Vetor2D p;
        Vetor2D v;
        Vetor2D res;

        printf("Informe as coordenadas do ponto (x y): ");
        scanf("%f %f", &p.x, &p.y);

        printf("Informe as coordenadas do vetor (x y): ");
        scanf("%f %f", &v.x, &v.y);

        res = deslocar2D(p, v, op);

        printf(
            "Ponto deslocado: (%.2f, %.2f)\n",
            res.x, res.y
        );
    } else if (strcmp(tipo, "3D") == 0) {
        Vetor3D p;
        Vetor3D v;
        Vetor3D res;

        printf("Informe as coordenadas do ponto (x y z): ");
        scanf("%f %f %f", &p.x, &p.y, &p.z);

        printf("Informe as coordenadas do vetor (x y z): ");
        scanf("%f %f %f", &v.x, &v.y, &v.z);

        res = deslocar3D(p, v, op);

        printf("Ponto deslocado: (%.2f, %.2f, %.2f)\n", res.x, res.y, res.z);
    } else {
        printf("Tipo invalido.\n");
    }

    return 0;
}