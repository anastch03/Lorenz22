/*
    Wheel{
        used to model each of the 18 wheels
        * Wheel settings are part of encryption pipeline
        * Wheel positions are incremented with each character
    }
*/

/*
File: wheel.h
Author: Anastasia Chen
Date: 4/15/2022
*/

#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <vector>

class Wheel
{
private:
    int current_position;
    int num_pins;
    std::vector<int> pin; //pin status (1 or 0) (size of vector = num_pins)
public:
    Wheel();
    ~Wheel();
    //getters
    int get_current_pos(){ return current_position;}
    int get_num_pins(){ return num_pins;}
    //setters
    void set_current_pos(int pos){current_position = pos;}
    void set_num_pins(int pins){num_pins = pins;}
    //functions
    void increment(); //increment wheel position by 1

};

Wheel::Wheel()
{
}

Wheel::~Wheel()
{
}

#endif