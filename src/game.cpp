#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int width, int height)
    : width(width), height(height), generation(0),
      grid(height, std::vector<bool>(width, false)),
      nextGrid(height, std::vector<bool>(width, false))
{
    srand(static_cast<unsigned>(time(NULL)));
}

int Game::wrapX(int x) const {
    return ((x % width) + width) % width;
}

int Game::wrapY(int y) const {
    return ((y % height) + height) % height;
}

int Game::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            if (grid[wrapY(y + dy)][wrapX(x + dx)]) {
                count++;
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
    generation++;
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
    generation = 0;
}

void Game::randomize() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = (rand() % 4 == 0);
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

int Game::getGeneration() const { return generation; }

int Game::getPopulation() const {
    int count = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x]) count++;
        }
    }
    return count;
}
