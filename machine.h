/*
File: machine.h
Author: Anastasia Chen
Date: 4/15/2022
*/

#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include "mapper.h"
#include "wheelAssembly.h"

class Machine
{
private:
    bool verbose = false; // if true, display intermediate steps and wheel settings
    Mapper *mapper;
    WheelAssembly *wheelAssembly;

public:
    Machine()
    {
        this->mapper = new Mapper();
        this->wheelAssembly = new WheelAssembly();
        getWheelAssembly()->readFile(); // read wheel settings and stores wheel setting info to each wheel
    }
    ~Machine() {}
    static void help();
    std::string encrypt(std::string plain_txt);
    static void convertToBinary(int num, std::vector<int> *bitVect);
    static int binaryToDec(std::vector<int> *bitVect);
    static std::string decToHex(int decimal);
    std::string decrypt(std::string cipherText);
    static std::string decrypt_helper();
    void test(std::string setting);
    Mapper *getMapper() { return mapper; }
    void settings(const char *settings);
    void setVerbose(bool v) { verbose = v; }
    bool get_verbose() { return verbose; }
    WheelAssembly *getWheelAssembly() { return wheelAssembly; }
};

#endif
