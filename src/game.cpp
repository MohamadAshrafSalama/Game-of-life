#include "game.h"

Game::Game(int width, int height)
    : width(width), height(height),
      grid(height, std::vector<bool>(width, false)),
      nextGrid(height, std::vector<bool>(width, false))
{
}

int Game::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (grid[ny][nx]) count++;
            }
        }
    }
    return count;
}

void Game::update() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = countNeighbors(x, y);
            if (grid[y][x]) {
                nextGrid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                nextGrid[y][x] = (neighbors == 3);
            }
        }
    }
    grid.swap(nextGrid);
}

void Game::toggleCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = !grid[y][x];
    }
}

void Game::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = false;
        }
    }
}

bool Game::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }
    return false;
}

int Game::getWidth() const { return width; }
int Game::getHeight() const { return height; }
