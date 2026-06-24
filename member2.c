#include "lost_kite.h"

void drawBresenhamCircle(float fcx, float fcy, float fr) {
    int xc = (int)roundf(fcx);
    int yc = (int)roundf(fcy);
    int r = (int)roundf(fr);

    int x = 0, y = r;
    int d = 3 - 2 * r;
    
    // Filled circle using Bresenham lines
    while (y >= x) {
        drawBresenhamLine(xc - x, yc + y, xc + x, yc + y);
        drawBresenhamLine(xc - x, yc - y, xc + x, yc - y);
        drawBresenhamLine(xc - y, yc + x, xc + y, yc + x);
        drawBresenhamLine(xc - y, yc - x, xc + y, yc - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void drawCircle(float cx, float cy, float r, int segments) {
    // Replaced GL_TRIANGLE_FAN with Bresenham Circle
    drawBresenhamCircle(cx, cy, r);
}

void drawChild(float cx, float cy, float walkPhase) {
    float armSwing = sinf(walkPhase) * 15.0f;
    float legSwing = cosf(walkPhase) * 15.0f;
    
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    
    // Legs
    setColor(0.2f, 0.2f, 0.8f, 1.0f);
    setThickness(4.0f);
    // Leg 1
    drawBresenhamLine(0, 30, -legSwing, 0);
    // Leg 2
    drawBresenhamLine(0, 30, legSwing, 0);
    
    // Body
    setColor(0.8f, 0.3f, 0.3f, 1.0f);
    drawRect(-10, 30, 20, 30);
    
    // Arms
    setColor(0.9f, 0.7f, 0.5f, 1.0f);
    drawBresenhamLine(0, 55, -armSwing, 30);
    drawBresenhamLine(0, 55, armSwing, 40); // holding string
    setThickness(1.0f);
    
    // Head
    drawCircle(0, 70, 10, 16);
    
    glPopMatrix();
}

void drawCloud(float cx, float cy, float scale, float darkness) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glScalef(scale, scale, 1);
    
    setColor(1.0f - darkness, 1.0f - darkness, 1.0f - darkness, 0.9f);
    drawCircle(0, 0, 20, 16);
    drawCircle(-15, -10, 15, 16);
    drawCircle(15, -10, 15, 16);
    drawCircle(-25, -20, 10, 16);
    drawCircle(25, -20, 10, 16);
    
    glPopMatrix();
}

void drawMountains() {
    setColor(0.4f, 0.4f, 0.5f, 1.0f);
    drawTriangle(-100, 100, 300, 100, 100, 400);
    setColor(0.5f, 0.5f, 0.6f, 1.0f);
    drawTriangle(150, 100, 600, 100, 375, 500);
    setColor(0.45f, 0.45f, 0.55f, 1.0f);
    drawTriangle(400, 100, 1000, 100, 700, 450);
}

void renderScene1() {
    float total_time = time_elapsed;
    float sunrise = lerp(0.0f, 1.0f, total_time / 23.0f);
    
    setColor(0.2f + sunrise*0.2f, 0.3f + sunrise*0.45f, 0.5f + sunrise*0.5f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    float sunY = lerp(50, 500, total_time / 23.0f);
    setColor(1.0f, 0.8f + sunrise*0.2f, 0.2f, 1.0f);
    drawCircle(200, sunY, 40, 32);
    
    drawMountains();
    
    setColor(0.3f, 0.7f, 0.3f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    for(int i=0; i<3; i++) {
        drawCloud(100 + i*300 + time_elapsed*10, 400 + (i%2)*50, 1.0f, 0.0f);
    }
    
    for(int i=0; i<5; i++) {
        drawBird(800 - time_elapsed*30 + i*30, 450 + (i%2)*20, 0.5f, time_elapsed*10 + i);
    }
    
    float childX = lerp(-100, 200, time_elapsed / 5.0f); 
    drawChild(childX, 100, time_elapsed * 5.0f);
    
    drawKite(childX + 20, 160, 0.5f, 15);
    setColor(1,1,1,1);
    drawBresenhamLine(childX + 15, 140, childX + 20, 160);
}

void renderSceneSunriseBridge() {
    float total_time = time_elapsed + 8.0f;
    float sunrise = lerp(0.0f, 1.0f, total_time / 23.0f);
    
    setColor(0.2f + sunrise*0.2f, 0.3f + sunrise*0.45f, 0.5f + sunrise*0.5f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    float sunY = lerp(50, 500, total_time / 23.0f);
    setColor(1.0f, 0.8f + sunrise*0.2f, 0.2f, 1.0f);
    drawCircle(200, sunY, 40, 32);
    
    drawMountains();
    
    setColor(0.2f, 0.4f, 0.8f, 1.0f);
    drawRect(0, 0, window_width, 60);
    
    setColor(0.6f, 0.4f, 0.2f, 1.0f);
    drawRect(0, 50, window_width, 20); 
    for(int i=0; i<window_width; i+=100) {
        drawRect(i+40, 0, 20, 50); 
    }
    
    setColor(0.3f, 0.6f, 0.3f, 1.0f);
    drawRect(0, 70, window_width, 30);
    
    float childX = lerp(-100, window_width + 100, time_elapsed / 15.0f);
    drawChild(childX, 100, time_elapsed * 8.0f);
    
    drawKite(childX + 20, 160, 0.5f, 15);
    setColor(1,1,1,1);
    drawBresenhamLine(childX + 15, 140, childX + 20, 160);
}
