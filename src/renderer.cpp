#include "renderer.h"

Renderer::Renderer(int windowWidth, int windowHeight, Game* game)
    : windowWidth(windowWidth), windowHeight(windowHeight), game(game)
{
    updateCellSize();
}

void Renderer::updateCellSize() {
    cellWidth = static_cast<float>(windowWidth) / game->getWidth();
    cellHeight = static_cast<float>(windowHeight) / game->getHeight();
}

void Renderer::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glutSwapBuffers();
}

void Renderer::drawGrid() {
    for (int y = 0; y < game->getHeight(); y++) {
        for (int x = 0; x < game->getWidth(); x++) {
            drawCell(x, y, game->getCell(x, y));
        }
    }
}

void Renderer::drawCell(int x, int y, bool alive) {
    if (!alive) return;

    float px = x * cellWidth;
    float py = y * cellHeight;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(px, py);
    glVertex2f(px + cellWidth, py);
    glVertex2f(px + cellWidth, py + cellHeight);
    glVertex2f(px, py + cellHeight);
    glEnd();
}

void Renderer::screenToGrid(int screenX, int screenY, int* gridX, int* gridY) {
    *gridX = static_cast<int>(screenX / cellWidth);
    *gridY = static_cast<int>((windowHeight - screenY) / cellHeight);
}

int Renderer::getWindowWidth() const { return windowWidth; }
int Renderer::getWindowHeight() const { return windowHeight; }
