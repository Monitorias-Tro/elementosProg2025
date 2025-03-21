#include "image.h"
#include "protocol.h"
#include <iostream>

image::image() {
    full(15);
}

image::~image() {
    std::cout << "Objeto IMAGE deletado!" << std::endl;
}

void image::full(int intensity) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int z = 0; z < 8; z++) {
                matrix[x][y][z] = intensity;
            }
        }
    }
}

int image::getCube(int x, int y, int z) {
    return matrix[x][y][z];
}

void image::setIntensity(int intensity) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int z = 0; z < 8; z++) {
                matrix[x][y][z] = intensity;
            }
        }
    }
}

void image::drawCube(int pos, int size) {
    for (int x = 0; x < pos; x++) {
        for (int y = 0; y < pos; y++) {
            for (int z = 0; z < pos; z++) {
                if(x<=size && y<=size && z<=size){
                    matrix[x][y][z] = 15;
                }
            }
        }
    }
}