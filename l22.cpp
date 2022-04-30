//g++ -std=c++11 -Wall -Werror -o L22 *.cpp
/*
File: L22.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

#include "machine.h"
#include "parser.h"

int main (int argc, char *argv[]){ 

    //make L22 machine
    Machine *m1 = new Machine();

    //COMMAND LINE PARSING FROM https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
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
        if(input.cmdOptionExists("-i"))
        {
            m1->Machine::settings(input.getCmdOption("-i").c_str());
            m1->Machine::test(input.getCmdOption("-i").c_str());
        }
        else
        {
            m1->Machine::test("");
        }
    }
    else if(input.cmdOptionExists("-e")){ //encrypt mode
        if(input.cmdOptionExists("-d")){
            std::cout<< "-e, -d, and -t are mutually incompatible"<<std::endl;
            Machine::help();
            return 1;
        }
        if(input.cmdOptionExists("-i"))
        {
            const std::string &settings = input.getCmdOption("-i");
            m1->Machine::settings(settings.c_str());
        }
        std::cout<< "Enter text to encrypt:"<<std::endl;
        std::string plain_txt;
        std::getline(std::cin, plain_txt);
        std::string cipherText = m1->Machine::encrypt(plain_txt);
        int count = 0;
        for(char c : cipherText)
        {
            if (count == 5){
                count = 0;
                std::cout <<" ";
            }
            std::cout<< c;
            count++;
        }
        std::cout<<std::endl;

    }
    else if(input.cmdOptionExists("-d")){ //decrypt mode
        if(input.cmdOptionExists("-i"))
        {
            m1->Machine::settings(input.getCmdOption("-i").c_str());
        }
        std::cout<< m1->Machine::decrypt(Machine::decrypt_helper())<<std::endl;
    }
    else {
        std::cout<< "unknown arguments: " << argv[1]<< std::endl;
        Machine::help();
    }

}