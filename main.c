/*
 * THE LOST KITE - Computer Graphics Assignment
 * 
 * BUILD INSTRUCTIONS FOR MSYS2 MINGW64 (Windows):
 * ================================================
 * 
 * 1. Install required packages (in MSYS2 MINGW64 terminal):
 *    pacman -Syu
 *    pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-freeglut
 * 
 * 2. Compile with this command:
 *    gcc -o the_lost_kite.exe main.c member1.c member2.c member3.c member4.c member5.c \
 *      $(pkg-config --cflags --libs glut) -lm -std=c99
 * 
 * 3. Or use make (if Makefile exists):
 *    make
 * 
 * 4. Run the application:
 *    ./the_lost_kite.exe
 * 
 * CONTROLS:
 * - ESC: Exit program
 * - SPACE/ENTER: Advance to next scene or restart if at end
 * 
 * LIBRARIES USED:
 * - FreeGLUT (OpenGL windowing/rendering)
 * - OpenGL (graphics API)
 * - libm (C math library for sin/cos)
 */

#include "lost_kite.h"

int window_width = 900;
int window_height = 600;
int current_scene = 0;
float time_elapsed = 0.0f;
int last_time = 0;

float scene_durations[] = {8.0f, 15.0f, 15.0f, 20.0f, 20.0f, 25.0f, 25.0f, 25.0f, 20.0f, 20.0f};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    switch(current_scene) {
        case 0: renderScene1(); break;
        case 1: renderSceneSunriseBridge(); break;
        case 2: renderScene2(); break;
        case 3: renderScene3(); break;
        case 4: renderScene4(); break;
        case 5: renderScene5(); break;
        case 6: renderScene6(); break;
        case 7: renderScene7(); break;
        case 8: renderScene8(); break;
        case 9: renderScene9(); break;
    }
    
    glutSwapBuffers();
}

void advanceScene() {
    if (current_scene < 9) {
        current_scene++;
        time_elapsed = 0.0f;
    }
}

void timer(int val) {
    int now = glutGet(GLUT_ELAPSED_TIME);
    float dt = (now - last_time) / 1000.0f;
    last_time = now;
    
    time_elapsed += dt;
    
    if (current_scene < 10 && time_elapsed > scene_durations[current_scene]) {
        advanceScene();
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // ESC
        exit(0);
    } else if (key == ' ' || key == 13) {
        if (current_scene >= 9) {
            current_scene = 0;
            time_elapsed = 0.0f;
        } else {
            advanceScene();
        }
    }
}

void reshape(int w, int h) {
    window_width = w;
    window_height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("The Lost Kite - Bresenham Edition");
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // We can keep these for the remaining polygons, but they won't affect GL_POINTS
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif
    glEnable(GL_MULTISAMPLE);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    last_time = glutGet(GLUT_ELAPSED_TIME);
    glutTimerFunc(16, timer, 0);
    
    glutMainLoop();
    return 0;
}
