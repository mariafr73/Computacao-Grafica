#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define width 400
#define height 400

typedef struct {
    float x, y;
    unsigned char r, g, b;
} Point2D;

unsigned char img[height][width][3];

void px(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        img[x][y][0] = r;
        img[x][y][1] = g;
        img[x][y][2] = b;
    }
}

void clr(){
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            px(x, y, 255, 255, 255);
        }
    }
}

void save(){
    printf("P3\n %d \t %d\n 255\n", width, height);
    for(int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            for(int c = 0; c < 3; c++) {
                printf("%d \t", img[x][y][c]);
            }
            printf("\n");
        }
    }
}

void cb(Point2D a, Point2D b, Point2D c) {
    //definindo o bounding box
    int x_min = floorf(fminf(fminf(a.x, b.x), c.x));
    int y_min = ceilf(fminf(fminf(a.y, b.y), c.y));
    int x_max = floorf(fmaxf(fmaxf(a.x, b.x), c.x));
    int y_max = ceilf(fmaxf(fmaxf(a.y, b.y), c.y));

    //calcular a area total
    float areat = 0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));

    for(int x = x_min; x <= x_max; x++){
        for(int y = y_min; y <= y_max; y++){
            Point2D p = {x, y, 255, 255, 255};

            //Encontrando as areas dos sub-triangulos
            float area_pbc = 0.5 * (p.x * (b.y - c.y) + b.x * (c.y - p.y) + c.x * (p.y - b.y));
            float area_apc = 0.5 * (a.x * (p.y - c.y) + p.x * (c.y - a.y) + c.x * (a.y - p.y));
            float area_abp = 0.5 * (a.x * (b.y - p.y) + b.x * (p.y - a.y) + p.x * (a.y - b.y));

            //Encontrando alpha, beta e gamma
            float alpha = area_pbc / areat;
            float beta = area_apc / areat;
            float gamma = area_abp / areat;

            if(alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0){
                px(x, y, alpha*a.r + beta*b.r + gamma*c.r, alpha*a.g + beta*b.g + gamma*c.g, alpha*a.b + beta*b.b + gamma*c.b);
            }
        }
    }
}

int main() {
    clr();

    Point2D a = {0, 0, 255, 0, 0};
    Point2D b = {0, 100, 0, 0, 255};
    Point2D c = {100, 0, 0, 0, 255};
    cb(a,b,c);

    save();
    return 0;
}