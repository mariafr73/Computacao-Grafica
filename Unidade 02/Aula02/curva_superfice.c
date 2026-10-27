#include <stdio.h>

#define width 300
#define height 300

typedef struct {
    float x, y;
} Point;

typedef struct {
    float x, y, z;
} Point3D;

unsigned char image[width][height][3];

void px(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
        image[x][y][0] = r;
        image[x][y][1] = g;
        image[x][y][2] = b;
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
    printf("P3 \n %d \t %d \n 255 \n", width, height);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            for (int c = 0; c < 3; c++) {
                printf("%d \t", image[x][y][c]);
            }
            printf("\n");
        }
    }
}

float h1(float t){ return (2*(t*t*t)) - (3*(t*t)) + 1; }

float h2(float t){ return (-2*(t*t*t)) + (3*(t*t)); }

float h3(float t){ return (((t*t*t)) - (2*(t*t)) + t); }

float h4(float t){ return ((t*t*t) - (t*t)); }

Point hermite(float t, Point p1, Point p2, Point t1, Point t2){
    Point result;
    result.x = h1(t)*p1.x + h2(t)*p2.x + h3(t)*t1.x + h4(t)*t2.x;
    result.y = h1(t)*p1.y + h2(t)*p2.y + h3(t)*t1.y + h4(t)*t2.y;
    return result;
}

Point3D hermite3D(float u, float v, Point3D p0, Point3D p1, Point3D p2, Point3D p3, 
                                    Point3D s0, Point3D s1, Point3D s2, Point3D s3, 
                                    Point3D r0, Point3D r1, Point3D r2, Point3D r3, 
                                    Point3D t0, Point3D t1, Point3D t2, Point3D t3){

    Point3D result;
    result.x = h1(u)*h1(v)*p0.x + h2(u)*h1(v)*p1.x + h3(u)*h1(v)*s0.x + h4(u)*h1(v)*s1.x +
               h1(u)*h2(v)*p2.x + h2(u)*h2(v)*p3.x + h3(u)*h2(v)*s2.x + h4(u)*h2(v)*s3.x +
               h1(u)*h3(v)*r0.x + h2(u)*h3(v)*r1.x + h3(u)*h3(v)*t0.x + h4(u)*h3(v)*t1.x +
               h1(u)*h4(v)*r2.x + h2(u)*h4(v)*r3.x + h3(u)*h4(v)*t2.x + h4(u)*h4(v)*t3.x;
    
    result.y = h1(u)*h1(v)*p0.y + h2(u)*h1(v)*p1.y + h3(u)*h1(v)*s0.y + h4(u)*h1(v)*s1.y +
               h1(u)*h2(v)*p2.y + h2(u)*h2(v)*p3.y + h3(u)*h2(v)*s2.y + h4(u)*h2(v)*s3.y +
               h1(u)*h3(v)*r0.y + h2(u)*h3(v)*r1.y + h3(u)*h3(v)*t0.y + h4(u)*h3(v)*t1.y +
               h1(u)*h4(v)*r2.y + h2(u)*h4(v)*r3.y + h3(u)*h4(v)*t2.y + h4(u)*h4(v)*t3.y;

    result.z = h1(u)*h1(v)*p0.z + h2(u)*h1(v)*p1.z + h3(u)*h1(v)*s0.z + h4(u)*h1(v)*s1.z +
               h1(u)*h2(v)*p2.z + h2(u)*h2(v)*p3.z + h3(u)*h2(v)*s2.z + h4(u)*h2(v)*s3.z +
               h1(u)*h3(v)*r0.z + h2(u)*h3(v)*r1.z + h3(u)*h3(v)*t0.z + h4(u)*h3(v)*t1.z +
               h1(u)*h4(v)*r2.z + h2(u)*h4(v)*r3.z + h3(u)*h4(v)*t2.z + h4(u)*h4(v)*t3.z;
    return result;
}

int main(){
    clr();

    //Point P1 = {100,100};
    //Point P2 = {400,200};
    //Point T1 = {100,0};
    //Point T2 = {0,100};

    /*for (float t = 0.0; t <= 1.0; t += 0.01) {
        Point h = hermite(t, P1, P2, T1, T2);
        px(h.x, h.y, 255, 0, 0);
    }*/

    Point3D P0 = {0, 0, 0};
    Point3D P1 = {0, 200, 30};
    Point3D P2 = {200, 0, 30};
    Point3D P3 = {200, 200, 80};

    Point3D S0 = {50, 0, 40};
    Point3D S1 = {50, 0, 40};
    Point3D S2 = {50, 0, 40};
    Point3D S3 = {50, 0, 40};

    Point3D R0 = {0, 50, 40};
    Point3D R1 = {0, 50, 40};
    Point3D R2 = {0, 50, 40};
    Point3D R3 = {0, 50, 60};

    Point3D T0 = {0, 0, 0};
    Point3D T1 = {0, 0, 0};
    Point3D T2 = {0, 0, 0};
    Point3D T3 = {0, 0, 0};

    float d = 200.0;

    for (float u = 0.0; u <= 1.0; u += 0.02) {
        for (float v = 0.0; v <= 1.0; v += 0.02) {
            Point3D h3d = hermite3D(u, v, P0, P1, P2, P3, S0, S1, S2, S3, R0, R1, R2, R3, T0, T1, T2, T3);
            float x_proj = (width/2) +(h3d.x * 2.0 * d) / (h3d.z + d);
            float y_proj = (height/2) +(h3d.y * 2.0 * d) / (h3d.z + d);

            px(x_proj, y_proj, 255, 0, 0);
        }
    }

    save();

    return 0;
}