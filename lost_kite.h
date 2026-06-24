#ifndef LOST_KITE_H
#define LOST_KITE_H

#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// Globals
extern int window_width;
extern int window_height;
extern int current_scene;
extern float time_elapsed;
extern int last_time;
extern float scene_durations[];

// Member 1
void drawBresenhamLine(float fx0, float fy0, float fx1, float fy1);
void setThickness(float t);
void setColor(float r, float g, float b, float a);
void drawRect(float x, float y, float w, float h);
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
void drawText(float x, float y, const char *str, void *font);

// Member 2
void drawBresenhamCircle(float fcx, float fcy, float fr);
void drawCircle(float cx, float cy, float r, int segments);
void drawChild(float cx, float cy, float walkPhase);
void drawCloud(float cx, float cy, float scale, float darkness);
void drawMountains();
void renderScene1();
void renderSceneSunriseBridge();

// Member 3
void drawKite(float cx, float cy, float scale, float rot);
void drawThunderbolt(float cx, float cy, float scale);
void renderScene2();
void renderScene3();

// Member 4
void drawBird(float cx, float cy, float scale, float flapPhase);
void drawTree(float x, float y, float scale);
void drawRain();
void renderScene4();
void renderScene5();
void renderScene6();

// Member 5
float lerp(float a, float b, float t);
void renderScene7();
void renderScene8();
void renderScene9();

// Main
void display();
void advanceScene();
void timer(int val);
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);

#endif // LOST_KITE_H
