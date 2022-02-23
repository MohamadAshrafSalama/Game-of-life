# Conway's Game of Life

A C++ implementation of Conway's Game of Life using OpenGL/GLUT for rendering. The simulation runs on a toroidal grid (wrap-around edges) and supports interactive cell editing.

## About

The Game of Life is a cellular automaton devised by mathematician John Conway. Each cell on the grid is either alive or dead, and evolves based on simple rules:

- A live cell with 2 or 3 neighbors survives
- A dead cell with exactly 3 neighbors becomes alive
- All other cells die or stay dead

Despite these simple rules, the Game of Life can produce complex and interesting patterns.

## Controls

| Key | Action |
|-----|--------|
| Left Click | Toggle cell alive/dead |
| Space | Pause / Resume simulation |
| R | Randomize the grid |
| C | Clear the grid |
| N | Step one generation (while paused) |
| + / = | Increase simulation speed |
| - | Decrease simulation speed |
| ESC | Quit |

## Building

Requirements: g++, OpenGL, GLUT (freeglut on Linux)

```
make
./game_of_life
```

On macOS, the native GLUT framework is used. On Linux, install freeglut:

```
sudo apt-get install freeglut3-dev
```

To clean build artifacts:

```
make clean
```

## Screenshots

![Game of Life](screenshots/screenshot.png)
