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
    Wheel wheels[3][6]; //3 rows (A, B, C) of 6 wheels (for each bit)


    public:
    void read_settings(); //read initial wheel settings from -i
    void increment_i(); //increment wheel position based on table from step 11
    void incrementAll(); //increment all wheels by 1
    const Wheel *get_arr_ptr() {return &wheels[0][0];} //return address of wheels array
};

#endif