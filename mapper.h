/*
File: mapper.h
Author: Anastasia Chen
Date: 4/15/2022

Mapper - maps ascii characters to 6 bit characters and vice versa.
Has a method to strip out punctuation from ASCII input
Converts tabs and carriage returns to spaces.
Converts from ASCII to 6 bit value, optionally rotating mapping.
Converts from 6-bit value to ASCII, optionally rotating the mapping.
*/

#ifndef MAPPER_H
#define MAPPER_H

#include <string>
#include <vector>

class Mapper
{
private:
    std::vector<char> mapping {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ' ', 
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
public:
    Mapper(){}
    ~Mapper(){}
    std::string noPunc(const char *input); 
    int asciiToBit(char c); 
    int bitToAscii(int bit); 
    void rotate();
    void printMapping();
    std::vector <char> get_mapping(){return mapping;};
};



#endif
