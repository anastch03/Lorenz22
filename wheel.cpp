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