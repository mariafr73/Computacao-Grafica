#include "biblioteca.h"

int main(void){
  clr();

  set_pixel(135, 200, 0, 0, 255);

  draw_rotation(135, 200, -0.78);

  //draw_line(0 ,0, 100, 100);
  
  save();

  return 0;
}
