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

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr();

void save();

void draw_line(int x0, int y0, int x1, int y1);

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);

void resizing( Vertex v0, Vertex v1 );

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount);

void render_points(Vertex *vertices, int vcount);

void scale_model(Vertex *vertices, int vcount, float scale);

void translate_model(Vertex *vertices, int vcount, float tx, float ty, float tz);

void rotate_model(Vertex *vertices, int vcount, float theta);

#endif
