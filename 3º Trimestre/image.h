#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

class image {
public:
    image();
    ~image();
    int getCube(int x, int y, int z);
    void setIntensity(int intensity);
    void drawCube(int pos, int size);
    void full(int intensity);
private:
    uint8_t matrix[8][8][8];
};
#endif