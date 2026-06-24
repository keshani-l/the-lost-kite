#include "lost_kite.h"

// --- Bresenham Algorithms ---
void drawBresenhamLine(float fx0, float fy0, float fx1, float fy1) {
    int x0 = (int)roundf(fx0);
    int y0 = (int)roundf(fy0);
    int x1 = (int)roundf(fx1);
    int y1 = (int)roundf(fy1);

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2; 

    glBegin(GL_POINTS);
    for (;;) {  
        glVertex2i(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } 
        if (e2 <= dx) { err += dx; y0 += sy; } 
    }
    glEnd();
}

//---  thickness ---
void setThickness(float t) {
    glLineWidth(t);
    glPointSize(t);
}

// ---  basic Primitives ---
void setColor(float r, float g, float b, float a) { 
    glColor4f(r, g, b, a); 
}

void drawRect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x, y); glVertex2f(x + w, y);
    glVertex2f(x + w, y + h); glVertex2f(x, y + h);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1); glVertex2f(x2, y2); glVertex2f(x3, y3);
    glEnd();
}

void drawText(float x, float y, const char *str, void *font) {
    glRasterPos2f(x, y);
    while (*str) {
        glutBitmapCharacter(font, *str++);
    }
}
