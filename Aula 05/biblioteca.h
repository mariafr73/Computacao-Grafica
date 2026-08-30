#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define WIDTH 400
#define HEIGHT 400

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr(void);

void save(void);

void draw_line(int x0, int y0, int x1, int y1);

void draw_rotation(int x, int y, float theta);

#endif
