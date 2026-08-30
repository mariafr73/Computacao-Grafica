#include "model.h"

int main(void){
  Vertex vertices[MAX_VERTICES];
  Face faces[MAX_FACES];
  int vcount, fcount;

  clr();

  if(!load_obj("models/robot.obj", vertices, &vcount, faces, &fcount)){
    return 1;
  }

  render_points(vertices, vcount);

  save();

  return 0;
}
