#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
public:
    Game(int width, int height);

    void update();
    void toggleCell(int x, int y);
    void clear();
    void randomize();
    void randomize(float density);

    bool getCell(int x, int y) const;
    int getWidth() const;
    int getHeight() const;

    int getGeneration() const;
    int getPopulation() const;

private:
    int width;
    int height;
    int generation;
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;

    int countNeighbors(int x, int y) const;
    int wrapX(int x) const;
    int wrapY(int y) const;
};

#endif
