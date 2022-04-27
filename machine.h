/*
File: machine.h
Author: Anastasia Chen
Date: 4/15/2022
*/

#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>

class Machine
{
private:
    bool verbose = false;
    Mapper mapper;

public:
    Machine();
    ~Machine();
    static void help(); 
    int parseCL() const; //TODO
    std::string encrypt(); //TODO
     std::string decrypt(); //TODO
    void test(); 
    void printMapping();
    void printWheelSettings(); 
    void settings(); //TODO
    void setVerbose(bool v){
        verbose = v;
    }
};

Machine::Machine()
{
}

Machine::~Machine()
{
}

#endif