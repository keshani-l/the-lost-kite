#include "lost_kite.h"

void drawBird(float cx, float cy, float scale, float flapPhase) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glScalef(scale, scale, 1);
    
    float wingY = sinf(flapPhase) * 10.0f;
    
    setColor(0.1f, 0.1f, 0.1f, 1.0f);
    setThickness(2.0f);
    drawBresenhamLine(-15, wingY, 0, 0);
    drawBresenhamLine(0, 0, 15, wingY);
    setThickness(1.0f);
    glPopMatrix();
}

void drawTree(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);
    
    setColor(0.4f, 0.2f, 0.1f, 1.0f);
    drawRect(-10, 0, 20, 40);
    
    setColor(0.1f, 0.5f, 0.2f, 1.0f);
    drawTriangle(-30, 40, 30, 40, 0, 90);
    drawTriangle(-25, 70, 25, 70, 0, 110);
    drawTriangle(-20, 95, 20, 95, 0, 130);
    
    glPopMatrix();
}

void drawRain() {
    setColor(0.7f, 0.8f, 0.9f, 0.6f);
    setThickness(2.0f);
    srand(42); // fixed seed for static rain lines, but we offset them
    for(int i=0; i<100; i++) {
        float rx = rand() % (window_width + 200) - 100;
        float ry = rand() % window_height;
        float fall = fmodf(ry - time_elapsed * 500.0f, window_height);
        if (fall < 0) fall += window_height;
        
        drawBresenhamLine(rx - 10, fall + 20, rx, fall);
    }
    setThickness(1.0f);
}

void renderScene4() {
    setColor(0.15f, 0.25f, 0.35f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    setColor(0.1f, 0.3f, 0.1f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    // Distant dark trees
    for(int i=0; i<8; i++) {
        float tx = fmodf(window_width + i*150 - time_elapsed*40, window_width+300) - 100;
        drawTree(tx, 100, 0.7f);
    }
    
    // Occasional thunder in rain
    if (fmodf(time_elapsed, 5.0f) < 0.2f) {
        drawThunderbolt(500, 500, 1.2f);
    }
    
    drawRain();
    
    // Child walking slowly, searching
    drawChild(300, 100, time_elapsed * 4.0f);
    
    // Kite barely visible far away, tumbling
    float kiteX = 600 + sinf(time_elapsed)*50;
    float kiteY = 300 + cosf(time_elapsed*2)*50;
    drawKite(kiteX, kiteY, 0.6f, time_elapsed * 45);
}

void renderScene5() {
    setColor(0.3f, 0.6f, 0.8f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    setColor(0.2f, 0.4f, 0.8f, 1.0f);
    drawRect(0, 0, window_width, 60);
    
    float bridgeX = 500 - time_elapsed * 120;
    if (bridgeX > -200 && bridgeX < window_width+200) {
        setColor(0.6f, 0.4f, 0.2f, 1.0f);
        drawRect(bridgeX, 50, 300, 20); 
        drawRect(bridgeX+20, 0, 20, 50); 
        drawRect(bridgeX+260, 0, 20, 50); 
    }
    
    setColor(0.3f, 0.6f, 0.3f, 1.0f);
    drawRect(0, 60, window_width, 40);
    
    drawChild(200, 100, time_elapsed * 10.0f);
    
    float kiteX = 600 + sinf(time_elapsed*2)*100;
    float kiteY = 400 + cosf(time_elapsed*3)*50;
    drawKite(kiteX, kiteY, 1.0f, sinf(time_elapsed*5)*30 + 45);
    
    for(int i=0; i<6; i++) {
        float tx = fmodf(window_width + i*150 - time_elapsed*120, window_width+300) - 100;
        drawTree(tx, 100, 0.8f);
    }
}

void renderScene6() {
    setColor(0.2f, 0.3f, 0.4f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    setColor(0.2f, 0.4f, 0.2f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    for(int i=0; i<10; i++) {
        float tx = fmodf(window_width + i*100 - time_elapsed*50, window_width+200) - 100;
        drawTree(tx, 100, 1.2f);
    }
    
    drawChild(300, 100, time_elapsed * 6.0f);
    
    for(int i=0; i<8; i++) {
        float tx = fmodf(window_width + i*150 - time_elapsed*120, window_width+300) - 100;
        drawTree(tx, 80, 1.8f);
    }
    
    float kiteX = 700 + sinf(time_elapsed*4)*50;
    float kiteY = 500 + sinf(time_elapsed*2)*30;
    drawKite(kiteX, kiteY, 0.8f, 90 + sinf(time_elapsed)*10);
}
