#include "lost_kite.h"

float lerp(float a, float b, float t) {
    if(t < 0) t = 0;
    if(t > 1) t = 1;
    return a + (b - a) * t;
}

void renderScene7() {
    float sunset = lerp(0.0f, 1.0f, time_elapsed / 25.0f);
    setColor(0.3f + sunset*0.5f, 0.5f - sunset*0.2f, 0.8f - sunset*0.6f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    float sunAng = lerp(M_PI/4, M_PI - 0.2f, time_elapsed / 25.0f);
    float sunX = 450 + cosf(sunAng)*400;
    float sunY = 100 + sinf(sunAng)*400;
    setColor(1.0f, 0.8f - sunset*0.4f, 0.2f, 1.0f);
    drawCircle(sunX, sunY, 50, 32);
    
    glPushMatrix();
    glTranslatef(0, -time_elapsed * 20, 0); 
    
    setColor(0.4f, 0.6f, 0.3f, 1.0f);
    drawTriangle(0, -1000, window_width*2, -1000, 0, 1500); 
    
    float climbX = 200 + time_elapsed * 10;
    float climbY = climbX * (1500.0f / (window_width*2)) + 20; 
    drawChild(climbX, climbY, time_elapsed * 5.0f);
    
    drawKite(700, 600, 1.0f, 150);
    
    glPopMatrix();
}

void renderScene8() {
    setColor(0.8f, 0.3f, 0.2f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    setColor(1.0f, 0.5f, 0.1f, 1.0f);
    drawCircle(450, 100, 80, 32);
    
    setColor(0.2f, 0.3f, 0.1f, 1.0f);
    drawCircle(450, -300, 450, 64);
    
    drawChild(450, 150, 0);
    drawKite(470, 180, 1.0f, 45);
    
    for(int i=0; i<6; i++) {
        drawBird(window_width - time_elapsed*40 + i*40, 400 + sinf(i)*20, 0.6f, time_elapsed*8 + i);
    }
}

void renderScene9() {
    float night = lerp(0.0f, 1.0f, time_elapsed / 10.0f);
    
    setColor(0.8f - night*0.75f, 0.3f - night*0.25f, 0.2f - night*0.1f, 1.0f);
    drawRect(0, 0, window_width, window_height);
    
    if (night > 0.5f) {
        srand(12345);
        setColor(1,1,1, night - 0.5f);
        for(int i=0; i<50; i++) {
            float sx = rand() % window_width;
            float sy = rand() % window_height;
            drawCircle(sx, sy, 1.5f, 4);
        }
    }
    
    float moonY = lerp(-100, 450, (time_elapsed - 5.0f)/10.0f);
    if(moonY > -50) {
        setColor(0.9f, 0.9f, 1.0f, 1.0f);
        drawCircle(700, moonY, 40, 32);
    }
    
    setColor(0.1f, 0.1f, 0.1f, 1.0f);
    drawRect(0, 0, window_width, 100);
    
    drawChild(450 - time_elapsed*20, 100, time_elapsed*5.0f);
    drawKite(450 - time_elapsed*20 + 20, 130, 0.5f, 45);
    
    float creditY = lerp(-100, 600, time_elapsed / 20.0f);
    setColor(1,1,1,1);
    drawText(400, creditY, "THE LOST KITE", GLUT_BITMAP_TIMES_ROMAN_24);
    drawText(380, creditY - 40, "A FreeGLUT Animation", GLUT_BITMAP_HELVETICA_18);
}
