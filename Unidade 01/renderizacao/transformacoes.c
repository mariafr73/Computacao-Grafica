#include "model.h"

int main(void){
  Vertex vertices[MAX_VERTICES];
  Face faces[MAX_FACES];
  int vcount, fcount;

  clr();

  if(!load_obj("models/robot.obj", vertices, &vcount, faces, &fcount)){
    return 1;
  }

  scale_model(vertices, vcount, 0.8f);
  rotate_model(vertices, vcount, 0.52f);
  shear_model(vertices, vcount, 0.2f, 0.0f);
  reflect_model(vertices, vcount);
  translate_model(vertices, vcount, 0.1f, 0.0f, 0.0f);

  render_points(vertices, vcount);

  save();

  return 0;
}
