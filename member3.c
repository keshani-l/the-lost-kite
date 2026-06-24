#include "lost_kite.h"

void drawKite(float cx, float cy, float scale, float rot) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glRotatef(rot, 0, 0, 1);
    glScalef(scale, scale, 1);
    
    // Diamond shape
    setColor(0.9f, 0.2f, 0.2f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 20); glVertex2f(15, 0);
    glVertex2f(0, -30); glVertex2f(-15, 0);
    glEnd();
    
    // Tail
    setColor(1.0f, 1.0f, 1.0f, 1.0f);
    setThickness(2.0f);
    drawBresenhamLine(0, -30, -5, -40);
    drawBresenhamLine(-5, -40, 5, -50);
    drawBresenhamLine(5, -50, -5, -60);
    setThickness(1.0f);
    
    glPopMatrix();
}

void drawThunderbolt(float cx, float cy, float scale) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glScalef(scale, scale, 1);
    
    setColor(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for thunder
    glBegin(GL_TRIANGLES);
    // Top zigzag part
    glVertex2f(0, 0); 
    glVertex2f(-15, -50); 
    glVertex2f(10, -40);
    
    // Bottom zigzag part
    glVertex2f(-5, -45); 
    glVertex2f(-20, -100); 
    glVertex2f(5, -40);
    glEnd();
    
    // Outer glow
    setColor(1.0f, 1.0f, 0.5f, 0.4f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 10); glVertex2f(-25, -50); glVertex2f(20, -30);
    glVertex2f(-15, -35); glVertex2f(-30, -110); glVertex2f(15, -30);
    glEnd();
    
    glPopMatrix();
}

void renderScene2() {
    setColor(0.4f, 0.75f, 1.0f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    drawMountains();
    
    setColor(0.3f, 0.7f, 0.3f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    drawChild(200, 100, time_elapsed * 8.0f);
    
    float kiteY = lerp(200, 450, time_elapsed / 10.0f);
    float kiteX = lerp(250, 500, time_elapsed / 10.0f) + sinf(time_elapsed*3)*20;
    float rot = sinf(time_elapsed*4)*15 + 15;
    
    drawKite(kiteX, kiteY, 1.0f, rot);
    
    setColor(1,1,1,1);
    drawBresenhamLine(200 + sinf(time_elapsed*8)*15, 140, kiteX, kiteY);
    
    for(int i=0; i<4; i++) {
        drawCloud(fmodf(window_width + 100 + i*250 - time_elapsed*40, window_width+200)-100, 400 + (i%2)*50, 1.0f, 0.1f);
    }
    
    for(int i=0; i<5; i++) {
        float tx = fmodf(window_width + i*300 - time_elapsed*100, window_width+300) - 100;
        drawTree(tx, 100, 1.0f);
    }
}

void renderScene3() {
    float dark = lerp(0.0f, 0.6f, time_elapsed / 10.0f);
    setColor(0.4f - dark*0.3f, 0.75f - dark*0.5f, 1.0f - dark*0.5f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    setColor(0.3f - dark*0.2f, 0.7f - dark*0.4f, 0.3f - dark*0.2f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    // Yellow thunderbolts
    if (time_elapsed > 10 && fmodf(time_elapsed, 3.0f) < 0.3f) {
        drawThunderbolt(300, 550, 1.5f);
        drawThunderbolt(700, 600, 1.0f);
    }
    
    drawChild(200, 100, 0);
    
    float kiteX = 500 + time_elapsed * 30 + sinf(time_elapsed*10)*50;
    float kiteY = 450 + sinf(time_elapsed*5)*50;
    float rot = time_elapsed * 90;
    
    drawKite(kiteX, kiteY, 1.0f, rot);
    
    setColor(1,1,1,1);
    drawBresenhamLine(kiteX, kiteY, kiteX - 20, kiteY - 30);
    drawBresenhamLine(kiteX - 20, kiteY - 30, kiteX - 50, kiteY - 40 + sinf(time_elapsed*10)*10);
    
    for(int i=0; i<5; i++) {
        drawCloud(fmodf(window_width + 200 + i*200 - time_elapsed*80, window_width+300)-100, 350 + (i%2)*80, 1.5f, dark + 0.2f);
    }
}
