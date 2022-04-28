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

void WheelAssembly::readFile() {

    std::vector<std::string> fileData;
    // FILE READING FROM https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus
    std::fstream file;
    file.open("wheel.txt",std::ios::in); //open wheel.txt to perform read operation using file object
    if (file.is_open()){   //checking whether the file is open
        std::string tp;
        while(std::getline(file, tp)){ //read data from file object and put it into string.
            fileData.push_back(tp); //print the data of the string
        }
        file.close(); //close the file object.
    }

    std::vector<std::string>::iterator itr = fileData.begin();

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++){
            std::string line = *itr++;
            std::string name = line.std::string::substr(0, 2);
            int lastCommaIndex = line.std::string::find_last_of(",");
            std::string settings = line.std::string::substr(lastCommaIndex, (line.length() - lastCommaIndex));
            WheelAssembly::wheels[i][j].Wheel::set_name(name);
            for(int m = 0; m < settings.length(); m++) {
                WheelAssembly::wheels[i][j].Wheel::add_pin(settings.at(m)+0);
            }
        }
    }
}

void WheelAssembly::printAllWheels() {

    // get each wheel
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j< 3; j++){
            WheelAssembly::get_wheel(i, j).Wheel::printWheelSettings();
        }
    }
}

void WheelAssembly::read_settings(){ //read initial wheel settings from -i
    //TODO
}

void WheelAssembly::increment_i() { //increment wheel position based on table from step 11

}

void WheelAssembly::incrementAll() { //increment all wheels by 1
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 6; j++){
    //         WheelAssembly::wheels[i][j]->Wheel::increment();
    //     }
    // }
}