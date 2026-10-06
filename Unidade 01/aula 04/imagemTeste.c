#include <stdio.h>

#define w 100
#define h 100

unsigned char img[w][h][3];

void px(){
    printf("P3 \n %d\t %d\n 255\n", w, h);
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            for(int c = 0; c < 3; c++){
                printf("%d\t %d\t %d\n", 255, 255, 0);
            }
        }
    }
}

int main(void){
    px();
    return 0;
}