#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "game.h"
#include "renderer.h"

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 800;
static const int GRID_WIDTH = 50;
static const int GRID_HEIGHT = 50;

static Game* game = NULL;
static Renderer* renderer = NULL;
static bool paused = true;

void display() {
    renderer->display();
}

void timer(int value) {
    if (!paused) {
        game->update();
    }
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int gx, gy;
        renderer->screenToGrid(x, y, &gx, &gy);
        game->toggleCell(gx, gy);
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case ' ':
            paused = !paused;
            break;
        case 'r':
        case 'R':
            game->randomize();
            break;
        case 'c':
        case 'C':
            game->clear();
            paused = true;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    game = new Game(GRID_WIDTH, GRID_HEIGHT);
    renderer = new Renderer(WINDOW_WIDTH, WINDOW_HEIGHT, game);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Conway's Game of Life");

    renderer->init();

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(100, timer, 0);

    glutMainLoop();

    delete game;
    delete renderer;
    return 0;
}
