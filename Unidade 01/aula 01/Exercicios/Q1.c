#include <stdio.h>

#define w 100
#define h 100

unsigned char image[w][h][3]; //(r)ed, (g)reen, (b)lue;

void px(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    if((x >= 0 && x < w ) && (y >= 0 && y < h)){
        image[x][y][0] = r;
        image[x][y][1] = g;
        image[x][y][2] = b;
    }
}

void clrImf(){
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            px(x, y, 0, 0, 0);
        }
    }
}

void svImg(){
    printf("P3\n %d\t %d\n 255\n", w, h);
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            for(int c = 0; c < 3; c++){
                printf("%d\t", image[x][y][c]);
            }
            printf("\n");
        }
    }
}

void seg(int x1, int y1, int x2, int y2){
    for (float t = 0.0; t <= 1.0; t += 0.01){
        px((int) ((x2 - x1)*t + x1), (int) ((y2 - y1)*t + y1), 125, 0, 0);
    }
}

int main(void){

    clrImf();

    seg(50, 50, 50, 50);

    svImg();

    return 0;
}