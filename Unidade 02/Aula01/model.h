/**
 * \file model.h
 *
 * \brief Header com protÃ³tipos de funÃ§Ãµes para manipulaÃ§Ã£o de modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Ãrido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

#ifndef MODEL_H
#define MODEL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_VERTICES 50000
#define MAX_FACES 50000
#define MAX_FACE_VERTS 32

typedef struct {
  float x, y, z;
} Vertex;

typedef struct {
  int verts[MAX_FACE_VERTS];
  int n;
} Face;

typedef struct {
  int x, y;
} Point2D;

typedef struct {
  Vertex Peye;
  Vertex Pat;
  Vertex Vup;
  float d;
} Camera;

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr();

void save();

void draw_line(int x0, int y0, int x1, int y1);

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);

Vertex sub(Vertex a, Vertex b);

float dot(Vertex a, Vertex b);

Vertex cross(Vertex a, Vertex b);

Vertex normalize(Vertex v);

void resizing( Vertex p, Camera cam, Point2D *out);

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount, Camera cam);

#endif