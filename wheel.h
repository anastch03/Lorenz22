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
    int current_position = 0;
    std::string pin_settings;
    std::string name;
    std::vector<int> pins; //pin status (1 or 0) (size of vector = num_pins)
public:
    Wheel(){}
    ~Wheel(){}
    int get_current_pos(){ return current_position;}
    int get_current_pin();
    int get_num_pins(){return pins.size();}
    std::vector<int> get_pins() {return pins;}
    std::string get_name(){return this->name;}
    int set_current_pos(int pos){current_position = pos; return pos;}
    void set_name(std::string name) {this->name = name;}
    void add_pin(int value){this->pins.push_back(value); }
    void printWheelSettings();
    void increment(); //increment wheel position by 1

};

#endif