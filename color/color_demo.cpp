#include <iostream>
#include <iomanip>
#include "color.h"

int main()
{
    std::cout << "Normal " << Color::setFg(Color::green) << "Green Fg" 
              << Color::setBg(Color::blue) << " Blue background " 
              << Color::setColor(Color::purple, Color::yellow) << "Purple on Yellow" 
              << Color::reset() << std::endl;

    int bar_width=45;
    std::cout << std::endl
              << Color::setColor(Color::black, Color::green) 
              << std::setw(bar_width) << std::left
              << "100%" << Color::reset() << std::right << std::endl;
    return 0;
}