#include "image.h"
#include "protocol.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

void animationOne(image *cube, protocol *prot) {
    int i = 0;
    char resp;
    bool active = true, up = true;

    cube->full(0);
    for (int intensity = 0; intensity < 16; intensity++) {
        cube->animationOne(intensity);
        prot->getCube(cube);
        do {
            int respSend = prot->send(intensity);
        } while (respSend == -1);
    }

    while (active) {
        prot->activate(i);
        Sleep(300);
        std::cout << "ativou imagem " << i << std::endl;
        if (i == 15) {
            up = false;
        }
        if (i == 0) {
            if (!up) {
                do {
                    std::cout << "r. Repetir" << std::endl;
                    std::cout << "q. Sair" << std::endl;
                    resp = getchar();
                    if (resp == '\n') resp = getchar();
                } while (resp != 'r' && resp != 'q');
                switch (resp) {
                case 'r' :
                    up = true;
                    break;
                case 'q':
                    active = false;
                    prot->clear();
                    break;
                }
            }
        }
        if (up) i++;
        else i--;
    }
}

void animationTwo(image *cube, protocol *prot) {
    int size = 0, j = 0;
    char resp;
    bool active = true, up = true;

    cube->full(0);
    for (int i = 0; i < 9; i++) {
        cube->animationTwo(i, size);
        prot->getCube(cube);
        prot->send(i);
        size++;
    }
    while (active) {
        prot->activate(j);
        Sleep(300);
        std::cout << "ativou imagem " << j << std::endl;
        if (j == 8) {
            up = false;
        }
        if (j == 0) {
            if (!up) {
                do {
                    std::cout << "r. Repetir" << std::endl;
                    std::cout << "q. Sair" << std::endl;
                    resp = getchar();
                    if (resp == '\n') resp = getchar();
                } while (resp != 'r' && resp != 'q');
                switch (resp) {
                case 'r':
                    up = true;
                    break;
                case 'q':
                    active = false;
                    prot->clear();
                    break;
                }
            }
        }
        if (up) j++;
        else j--;
    }
}

int main() {
    char resp;
    bool on = true;
    image vcube;
    protocol prot;

    if (prot.open() == INVALID_HANDLE_VALUE) return -1;

    std::cout << "Conexao estabelecida!" << std::endl << std::endl;

    do {
        do {
            std::cout << "Escolha a animacao:" << std::endl;
            std::cout << "1. Aumenta a intensidade" << std::endl;
            std::cout << "2. Expande e contrai" << std::endl;
            std::cout << "q. Sair" << std::endl;
            resp = getchar();
            if (resp == '\n') resp = getchar();
        } while (resp != '1' && resp != '2' && resp != 'q');

        switch (resp) {
        case '1' :
            animationOne(&vcube, &prot);
            break;
        case '2':
            animationTwo(&vcube, &prot);
            break;
        case 'q':
            on = false;
            break;
        }

    } while (on);

    prot.clear();
    std::cout << "Memoria do cubo deletada" << std::endl;
}