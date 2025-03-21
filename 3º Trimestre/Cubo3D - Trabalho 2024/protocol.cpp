#include "protocol.h"
#include <iostream>
#include <Windows.h>

protocol::protocol() {
    baudrate = 115200;
}

protocol::~protocol() {
    std::cout << "Conexao com " << port << " encerrada!" << std::endl;
}

void protocol::getCube(image* cube) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int z = 0; z < 8; z++) {
                copyCube[x][y][z] = cube->getCube(x, y, z);
            }
        }
    }
}

HANDLE protocol::open()
{
    DCB cdcb;
    COMMTIMEOUTS comto;
    pCom = CreateFile(
        port,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (pCom == INVALID_HANDLE_VALUE) {
        std::cerr << "Nao abriu a " << port;
        return pCom;
    }

    GetCommState(pCom, &cdcb);

    cdcb.BaudRate = baudrate;
    cdcb.ByteSize = 8;
    cdcb.StopBits = ONESTOPBIT;
    cdcb.Parity = 2;

    if (!SetCommState(pCom, &cdcb)) {
        std::cerr << "SetCommState" << stderr;
        return INVALID_HANDLE_VALUE;
    }

    GetCommTimeouts(pCom, &comto);
    comto.ReadIntervalTimeout = MAXDWORD;
    comto.ReadTotalTimeoutMultiplier = 0;
    comto.ReadTotalTimeoutConstant = 0;
    comto.WriteTotalTimeoutMultiplier = 0;
    comto.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(pCom, &comto);
    return pCom;
}

int protocol::send(char CID) {
    int n = 10000;
    out[0] = SNC;
    out[1] = CID|0x80;
    WriteFile(pCom, out, 2, &b, NULL);
    do {
        ReadFile(pCom, in, 1, &b, NULL);
        n--;
    } while (n > 0 && b == 0);

    if (in[0] != MND && in[0] != ACK) {
        std::cerr << "Nao autorizado! Comando recebido: " << in[0] << std::endl;
        return -1;
    } else {
        WriteFile(pCom, copyCube, 512, &b, NULL);
        n = 10000;
        do {
            ReadFile(pCom, in, 1, &b, NULL);
            n--;
        } while (n > 0 && b == 0);
        std::cout << "imagem " << (int)CID << " enviada" << std::endl;
        return 0;
    }
}

void protocol::activate(char CID) {
    out[0] = ATX;
    out[1] = CID|0x80;
    WriteFile(pCom, out, 2, &b, NULL);
}

void protocol::clear() {
    out[0] = CLR;
    out[1] = CLR;
    WriteFile(pCom, out, 2, &b, NULL);
}