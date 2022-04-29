//g++ -std=c++11 -Wall -Werror -o L22 *.cpp
/*
File: L22.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

#include "machine.h"
#include "parser.h"

//PROBLEMS: always printing "U" in encyption
int main (int argc, char *argv[]){ 

    //make L22 machine
    Machine *m1 = new Machine();

    //settings: 
    // m1->Machine::settings();

    //taken from StackOverflow: 
    Parser input(argc, argv); //makes a Parser object 
    if(input.cmdOptionExists("-h") || argc < 2){ //help mode
        Machine::help();
    }
    if(input.cmdOptionExists("-v")){ //verbose mode
        m1->Machine::setVerbose(true);
    }
    if(input.cmdOptionExists("-t")){
        if(input.cmdOptionExists("-e")||input.cmdOptionExists("-d")){
            std::cout<< "-e, -d, and -t are mutually incompatible"<<std::endl;
            Machine::help();
            return 1;
        }
        std::cout<< "test mode" <<std::endl;
        m1->Machine::test();
    }
    else if(input.cmdOptionExists("-e")){ //encrypt mode
        if(input.cmdOptionExists("-d")){
            std::cout<< "-e, -d, and -t are mutually incompatible"<<std::endl;
            Machine::help();
            return 1;
        }
        std::cout<< "Enter text to encrypt:"<<std::endl;
        std::cout<< m1->Machine::encrypt() << std::endl;

    }
    else if(input.cmdOptionExists("-d")){ //decrypt mode
        std::cout<< "Enter text to decrypt:"<<std::endl;
        m1->Machine::decrypt(Machine::decrypt_helper());
    }
    else {
        std::cout<< "unknown arguments: " << argv[1]<< std::endl;
        Machine::help();
    }

    
    // else if(input.cmdOptionExists("-s")){
    // const std::string &filename = input.getCmdOption("-f");
    // if (!filename.empty()){
    //     // Do interesting things ...
    // }

}