#include "model.h"

int main() {
    Vertex vertices[MAX_VERTICES];
    Face faces[MAX_FACES];
    int vcount, fcount;

    clr();

    if (!load_obj("models/robot.obj", vertices, &vcount, faces, &fcount)) {
        return 1;
    }

    render_faces(vertices, faces, vcount, fcount);

    save();
    
    return 0;
}