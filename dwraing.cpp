#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

vector<string> canvas(HEIGHT, string(WIDTH, ' '));

void drawCircle(int cx, int cy, int r, char c = 'O') {
    double thresh = 0.7;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            double dx = x - cx;
            double dy = y - cy;
            double dist = sqrt(dx*dx + dy*dy);
            if (fabs(dist - r) < thresh) {
                canvas[y][x] = c;
            }
        }
    }
}

void drawRectangle(int x0, int y0, int w, int h, char c = '#') {
    for (int x = x0; x < x0 + w; ++x) {
        if (y0 >= 0 && y0 < HEIGHT && x >= 0 && x < WIDTH)
            canvas[y0][x] = c;
        if (y0 + h - 1 >= 0 && y0 + h - 1 < HEIGHT && x >= 0 && x < WIDTH)
            canvas[y0 + h - 1][x] = c;
    }
    for (int y = y0; y < y0 + h; ++y) {
        if (x0 >= 0 && x0 < WIDTH && y >= 0 && y < HEIGHT)
            canvas[y][x0] = c;
        if (x0 + w - 1 >= 0 && x0 + w - 1 < WIDTH && y >= 0 && y < HEIGHT)
            canvas[y][x0 + w - 1] = c;
    }
}

void drawSquare(int x0, int y0, int size, char c = '*') {
    drawRectangle(x0, y0, size, size, c);
}

void render() {
    for (const auto& row : canvas) {
        cout << row << "\n";
    }
}

int main() {
    // Draw circle
    drawCircle(WIDTH / 4, HEIGHT / 2, 6, 'O');
    // Draw rectangle
    drawRectangle(WIDTH / 2, HEIGHT / 4, 15, 8, '#');
    // Draw square
    drawSquare(2, 2, 5, '*');

    render();
    return 0;
}
