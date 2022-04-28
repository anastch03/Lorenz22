/*
File: wheel.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

#include <iostream>
#include "wheel.h"

//TODO

void Wheel::increment(){
    Wheel::set_current_pos(Wheel::get_current_pos()+1);
    Wheel::set_current_pos(Wheel::get_current_pos()%Wheel::get_num_pins());
}


void Wheel::printWheelSettings(){
    std::cout << Wheel::get_name() << ": ";
    for(int i : Wheel::get_pins())
    {
        // TODO: if this is the current_index, then color green
        std::cout << i;
    }
    std::cout<< std::endl;
}