/*
File: wheelAssembly.h
Author: Anastasia Chen
Date: 4/15/2022
*/
#ifndef WHEELASSEMBLY_H
#define WHEELASSEMBLY_H
#include "wheel.h"

//TODO
class WheelAssembly{

    private:
    Wheel wheels[6][3]; //3 rows (A, B, C) of 6 wheels (for each bit)


    public:
    WheelAssembly(){}
    ~WheelAssembly(){}
    enum set{A, B, C};
    void readFile(); //create wheels based on settings in wheel.txt
    void read_settings(); //read initial wheel settings from -i
    void increment_i(std::vector<int> *i); //increment wheel position based on table from step 11
    void incrementAll(); //increment all wheels by 1
    Wheel *get_wheel(int i, int j){ return &(wheels[i][j]); }
    void printAllWheels();
    std::vector<int> *getWheelVector(int w); //returns the address of a vector of A, B, and C wheels settings
};

#endif