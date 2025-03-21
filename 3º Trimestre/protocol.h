#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "image.h"
#include <Windows.h>

#define PORT "COM7";

#define SNC  ('S'|0x80)
#define ATX  ('X'|0x80)
#define CLR  ('C'|0x80)
#define ACK  'A'
#define NAK  'N'
#define MND  'M'
#define NID  'I'
#define TOUT 'T'

class protocol {
public:
    protocol();                //constructor
    ~protocol();               //destructor
    void getCube(image* cube); //get virtual image thru a pointer
    HANDLE open();             //create connection between intefaces
    int send(char CID);       //send virtual image
    void activate(char CID);   //activate image sent in the cube
    void clear();
    char in[2];  //command received
    char out[6]; //command sent
private:
    uint8_t copyCube[8][8][8];
    HANDLE pCom;           //handler object
    unsigned long int b;   //bytes received
    int baudrate;          //proprietary baudrate
    char port[6] = PORT; //port identification
};
#endif // PROTOCOL_H