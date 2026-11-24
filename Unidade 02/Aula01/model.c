#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "model.h"

unsigned char image[HEIGHT][WIDTH][3];

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    image[y][x][0] = r;
    image[y][x][1] = g;
    image[y][x][2] = b;
  }
}

void draw_line(int x0, int y0, int x1, int y1) {
  for (float t = 0.0; t < 1.0; t = t + 0.0001)
    set_pixel((int)x0+(x1-x0)*t, (int)y0+(y1-y0)*t, 0, 0, 0);
}

void clr(){
  for(int i = 0; i < WIDTH; i++)
    for(int j = 0; j < HEIGHT; j++)
      for(int c = 0; c < 3; c++)
	image[i][j][c] = 255;
}

void save(){
  printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      for(int c = 0; c < 3; c++){
	printf("%d \t", image[i][j][c]);
      }
      printf("\n");
    }
  }
}

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
	     int *fcount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    *vcount = 0;
    *fcount = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "v ", 2) == 0) {
            if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x,
		       &vertices[*vcount].y, &vertices[*vcount].z) == 3) {
                (*vcount)++;
            }
        } else if (strncmp(line, "f ", 2) == 0) {
            Face face = {.n = 0};
            char *token = strtok(line + 2, " \n");
            while (token && face.n < MAX_FACE_VERTS) {
                int index;
                if (sscanf(token, "%d", &index) == 1) {
                    face.verts[face.n++] = index;
                }
                token = strtok(NULL, " \n");
            }
            faces[(*fcount)++] = face;
        }
    }

    fclose(file);
    return 1;
}

Vertex sub(Vertex a, Vertex b){
  return (Vertex){a.x - b.x, a.y - b.y, a.z - b.z};
}

float dot(Vertex a, Vertex b){
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vertex cross(Vertex a, Vertex b){
  return (Vertex) {
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}

Vertex normalize(Vertex v){
  float tam = sqrtf(dot(v, v));
  if (tam > 0.1f) {
    v.x = v.x / tam;
    v.y = v.y / tam;
    v.z = v.z / tam;
  }
  return v;
}

void resizing( Vertex p, Camera cam, Point2D *out){
  //Encontre os vetores ortogonais u, v e n
  Vertex n = normalize(sub(cam.Peye, cam.Pat));
  Vertex u = normalize(cross(cam.Vup, n));
  Vertex v = cross(n, u);

  //Matriz de Visao
  Vertex p_peye = sub(p, cam.Peye);
  float x_img = dot(u, p_peye);
  float y_img = dot(v, p_peye);
  float z_img = dot(n, p_peye);

  //Projecao em perspectiva
  float w = z_img + cam.d;
  if( w < 0.1f ) return;

  float x_persp = (x_img * cam.d) / w;
  float y_persp = (y_img * cam.d) / w;

  out -> x = (int)((x_persp + 1.0f) * WIDTH / 2.0f);
  out -> y = (int)((1.0f - y_persp) * HEIGHT / 2.0f);
}

void cb(Point2D a, Point2D b, Point2D c, unsigned char red, unsigned char green, unsigned char blue) {
    //definindo o bounding box
    int x_min = floorf(fminf(fminf(a.x, b.x), c.x));
    int y_min = ceilf(fminf(fminf(a.y, b.y), c.y));
    int x_max = floorf(fmaxf(fmaxf(a.x, b.x), c.x));
    int y_max = ceilf(fmaxf(fmaxf(a.y, b.y), c.y));

    //calcular a area total
    float areat = 0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));

    for(int x = x_min; x <= x_max; x++){
        for(int y = y_min; y <= y_max; y++){
            Point2D p = {x, y};

            //Encontrando as areas dos sub-triangulos
            float area_pbc = 0.5 * (p.x * (b.y - c.y) + b.x * (c.y - p.y) + c.x * (p.y - b.y));
            float area_apc = 0.5 * (a.x * (p.y - c.y) + p.x * (c.y - a.y) + c.x * (a.y - p.y));
            float area_abp = 0.5 * (a.x * (b.y - p.y) + b.x * (p.y - a.y) + p.x * (a.y - b.y));

            //Encontrando alpha, beta e gamma
            float alpha = area_pbc / areat;
            float beta = area_apc / areat;
            float gamma = area_abp / areat;

            if(alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0){
                set_pixel(x, y, red, green, blue);
            }
        }
    }
  }

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount, Camera cam) {
  for (int i = 0; i < fcount; i++) {
    Face face = faces[i];
    Vertex v0 = vertices[face.verts[0] - 1];
    Vertex v1 = vertices[face.verts[1] - 1];
    Vertex v2 = vertices[face.verts[2] - 1];

    Point2D p0, p1, p2;

    resizing(v0, cam, &p0);
    resizing(v1, cam, &p1);
    resizing(v2, cam, &p2);

    cb(p0, p1, p2, rand() % 255, 0, rand() % 255);

    /*
    for (int j = 0; j < face.n; j++) {
        Vertex v0 = vertices[face.verts[j] - 1];
        Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
        Point2D p0, p1;
        resizing(v0, cam, &p0);
        resizing(v1, cam, &p1);
        draw_line(p0.x, p0.y, p1.x, p1.y);
    }*/
  }
}