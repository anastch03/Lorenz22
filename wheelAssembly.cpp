/*
WheelAssembly You may choose to have this class to model the entire assembly of wheels.
This class holds the collection of (18) wheels, and handles anything that would affect them as a group.
Reads the settings from wheel.txt
Reads the initial settings from -i command line
Increments certain wheel positions based on given intermediate value (see encryption step 11).
*/

/*
File: wheelAssembly.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

#include "wheelAssembly.h"
#include <fstream>
#include <string>
#include <stdlib.h>

std::vector<int> *WheelAssembly::getWheelVector(int w)
{
    std::vector<int> *vect = new std::vector<int>;
    for (int i = 0; i < 6; i++)
    {
        vect->push_back(get_wheel(i, w)->get_current_pin());
    }
    return vect;
}

void WheelAssembly::readFile()
{
    std::vector<std::string> fileData;
    // FILE READING FROM https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus
    std::fstream file;
    file.open("wheel.txt", std::ios::in); // open wheel.txt to perform read operation using file object
    if (file.is_open())
    { // checking whether the file is open
        std::string tp;
        while (std::getline(file, tp))
        {                           // read data from file object and put it into string.
            fileData.push_back(tp); // print the data of the string
        }
        file.close(); // close the file object.
    }
    else
    {
        std::cout << "wheel.txt does not exist.\n";
        std::exit(0);
    }

    std::vector<std::string>::iterator itr = fileData.begin();

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::string line = *itr++;
            std::string name = line.std::string::substr(0, 2);
            int lastCommaIndex = line.std::string::find_last_of(",") + 1;
            std::string settings = line.std::string::substr(lastCommaIndex, (line.length() - lastCommaIndex));
            this->get_wheel(i, j)->set_name(name);
            int length_of_settings = 0;
            for (char c : settings)
            {
                length_of_settings++;
                this->get_wheel(i, j)->add_pin((c == '0') ? 0 : 1);
            }
        }
    }
}

void WheelAssembly::printAllWheels()
{

    // get each wheel
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            WheelAssembly::get_wheel(i, j)->printWheelSettings(); // print wheel settings
        }
    }
    std::cout << std::endl;
}

std::string WheelAssembly::increment_i(std::vector<int> bits)
{ // increment wheel position based on table from step 11
    std::string str;
    for (int i = 0; i < 6; i++)
    {
        int c = (i + 1) % 6;
        for (int j = 0; j < 3; j++)
        {
            if ((i == 3 && c == 0) || (i == 4 && c == 1) || (i == 5 && c == 2))
            {
                if (bits.at(i) | bits.at(c))
                {
                    get_wheel(5 - i, j)->Wheel::increment();
                    str += "++W";
                    if (j == 0)
                        str += "A";
                    else if (j == 1)
                        str += "B";
                    else
                        str += "C";
                    str += std::to_string(5 - i) + "[i" + std::to_string(i) + " | i" + std::to_string(c) + "] ";
                }
            }
            else if (bits.at(i) & bits.at(c))
            {
                get_wheel(5 - i, j)->Wheel::increment();
                str += "++W";
                if (j == 0)
                    str += "A";
                else if (j == 1)
                    str += "B";
                else
                    str += "C";
                str += std::to_string(5 - i) + "[i" + std::to_string(i) + " & i" + std::to_string(c) + "] ";
            }
            c = (c + 1) % 6;
        }
    }
    return str;
}

void WheelAssembly::resetWheels()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            get_wheel(i, j)->set_current_pos(0);
        }
    }
}

void WheelAssembly::incrementAll()
{ // increment all wheels by 1
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            get_wheel(i, j)->Wheel::increment();
        }
    }
}