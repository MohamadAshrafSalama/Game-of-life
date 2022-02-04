#ifndef RENDERER_H
#define RENDERER_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "game.h"

class Renderer {
public:
    Renderer(int windowWidth, int windowHeight, Game* game);

    void init();
    void display();
    void drawGrid();
    void drawCell(int x, int y, bool alive);
    void drawHUD();
    void drawText(const char* text, float x, float y);

    void screenToGrid(int screenX, int screenY, int* gridX, int* gridY);

    int getWindowWidth() const;
    int getWindowHeight() const;

private:
    int windowWidth;
    int windowHeight;
    Game* game;

    float cellWidth;
    float cellHeight;

    void updateCellSize();
};

#endif
