#include "model.h"

int main() {
    Vertex vertices[MAX_VERTICES];
    Face faces[MAX_FACES];
    int vcount, fcount;

    clr();

    // LÃª o arquivo OBJ enviado
    if (!load_obj("models/wolf.obj", vertices, &vcount, faces, &fcount)) {
        return 1;
    }

    Camera cam = {
        .Peye = {0, 0, -0.25},
        .Pat = {0, 0, 0},
        .Vup = {0, 1, 0},
        .d = 10.0
    };

    // Renderiza as faces no framebuffer
    render_faces(vertices, faces, vcount, fcount, cam);

    save();
    
    return 0;
}