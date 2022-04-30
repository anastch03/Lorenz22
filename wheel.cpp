/*
File: wheel.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

#include <iostream>
#include "wheel.h"
#include "color.h"

void Wheel::increment()
{
    Wheel::set_current_pos(Wheel::get_current_pos() + 1);
    Wheel::set_current_pos(Wheel::get_current_pos() % Wheel::get_num_pins());
}

int Wheel::get_current_pin()
{
    return get_pins().at(get_current_pos());
}

void Wheel::printWheelSettings()
{
    std::cout << Wheel::get_name() << ": ";
    for (unsigned int i = 0; i < Wheel::get_pins().size(); i++)
    {
        // if this is the current_index, then color green
        if (i == (unsigned int)Wheel::get_current_pos())
        {
            // set color green
            std::cout << Color::setFg(Color::green) << get_pins().at(i) << Color::setFg(Color::white);
            // set color white
        }
        else
        {
            std::cout << get_pins().at(i);
        }
    }
    std::cout << std::endl;
}