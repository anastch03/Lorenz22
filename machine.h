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
    bool verbose = false; //if true, display intermediate steps and wheel settings
    Mapper mapper;
    WheelAssembly *wheelAssembly;

public:
    Machine(){}
    ~Machine(){}
    static void help(); 
    int parseCL() const; //TODO
    std::string encrypt(); //TODO
    std::string decrypt(); //TODO
    void test(); 
    void printMapping(); //TODO
    void printWheelSettings(); 
    void settings(); //TODO
    void setVerbose(bool v){
        verbose = v;
    }
    WheelAssembly getWheelAssembly(){return *wheelAssembly;}
};


#endif
