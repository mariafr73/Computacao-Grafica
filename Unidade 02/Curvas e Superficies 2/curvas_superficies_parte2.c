#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } Ponto;

typedef struct { double a, b, c; } Polinomio;

void hermite(Ponto p1, Ponto p2, Ponto t1, Ponto t2) {
    double ax=2*p1.x-2*p2.x+t1.x+t2.x;
    double bx=-3*p1.x+3*p2.x-2*t1.x-t2.x;
    double ay=2*p1.y-2*p2.y+t1.y+t2.y;
    double by=-3*p1.y+3*p2.y-2*t1.y-t2.y;
    printf("  Hx(t) = %.4f t^3 %+.4f t^2 %+.4f t %+.4f\n",ax,bx,t1.x,p1.x);
    printf("  Hy(t) = %.4f t^3 %+.4f t^2 %+.4f t %+.4f\n",ay,by,t1.y,p1.y);
}

void linear(Ponto p[4]) {
    for(int i=0;i<3;i++) {
        double m=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x);
        double b=p[i].y-m*p[i].x;
        printf("  S%d(x) = %.4f x %+.4f    (%.2f <= x <= %.2f)\n",i+1,m,b,p[i].x,p[i+1].x);
    }
}

void quadratica(Ponto p[4], double c1) {
    Polinomio s[3];
    s[0].c=c1;
    s[0].a=p[0].y-s[0].c*p[0].x*p[0].x - ((p[1].y-p[0].y)/(p[1].x-p[0].x)-c1*(p[0].x+p[1].x))*p[0].x;
    s[0].b=(p[1].y-p[0].y)/(p[1].x-p[0].x)-c1*(p[0].x+p[1].x);
    for (int i=1;i<3;i++) {
        double x0=p[i].x, x1=p[i+1].x;
        double anterior=s[i-1].b+2*s[i-1].c*x0;
        double inclinacao=(p[i+1].y-p[i].y)/(x1-x0);
        s[i].c=(inclinacao-anterior)/(x1-x0);
        s[i].b=anterior-2*s[i].c*x0;
        s[i].a=p[i].y-s[i].b*x0-s[i].c*x0*x0;
    }
    for(int i=0;i<3;i++)
        printf("  S%d(x) = %.4f %+.4f x %+.4f x^2    (%.2f <= x <= %.2f)\n",
            i+1,s[i].a,s[i].b,s[i].c,p[i].x,p[i+1].x);
}

int main(void) {
    const Ponto A[4][4] = {
        {{0,0},{2,2},{4,4},{6,6}},
        {{0,0},{2,2},{4,0},{6,2}},
        {{0,1},{2,3},{4,1},{6,2.5}},
        {{0,0},{2,2.5},{4,2.5},{6,0}}
    };
    const Ponto HP1[4]={{0,0},{0,0},{0,1},{0,0}};
    const Ponto HP2[4]={{1,1},{1,0},{1,0},{2,0}};
    const Ponto HT1[4]={{1,2},{0,1},{1,-2},{3,5}};
    const Ponto HT2[4]={{1,0},{0,-1},{-1,-1},{-3,-5}};
    
    const double cInicial[4]={0,-2,-15.0/8.0,0};
    int opcao;
    do {
        printf("\n=== CURVAS E SUPERFICIES - PARTE 2 ===\n");
        printf("1 - Hermite (4 questoes)\n");
        printf("2 - Splines de ordem 1 (4 questoes)\n");
        printf("3 - Splines de ordem 2 (4 questoes)\n");
        printf("0 - Sair\nOpcao: ");
        if(scanf("%d",&opcao)!=1) return 1;
        switch(opcao) {
            case 1:
                for(int i=0;i<4;i++) { printf("\nQuestao %d - Hermite:\n",i+1); hermite(HP1[i],HP2[i],HT1[i],HT2[i]); }
                break;
            case 2:
                for(int i=0;i<4;i++) { printf("\nQuestao %d - Spline ordem 1:\n",i+1); linear((Ponto*)A[i]); }
                break;
            case 3:
                puts("\nNota: o PDF fixa a1=0, mas essa condicao nao determina");
                puts("solucao unica nas questoes 1, 2 e 4 e contradiz a questao 3.");
                puts("Escolhemos c1 para obter uma solucao particular em cada caso.");
                for(int i=0;i<4;i++) {
                    printf("\nQuestao %d - Spline ordem 2 (c1=%.4f):\n",i+1,cInicial[i]);
                    quadratica((Ponto*)A[i],cInicial[i]);
                }
                break;
            case 0: puts("Fim."); break;
            default: puts("Opcao invalida.");
        }
    } while(opcao!=0);
    return 0;
}
