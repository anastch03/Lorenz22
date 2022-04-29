/*
File: mapper.cpp
Author: Anastasia Chen
Date: 4/15/2022

maps ascii characters to 6 bit characters and vice versa.
- Has a method to strip out punctuation from ASCII input 
- Converts tabs and carriage returns to spaces. 
- Converts from ASCII to 6 bit value, optionally rotating mapping.
- Converts from 6-bit value to ASCII, optionally rotating the mapping.
*/

#include "mapper.h"
#include <iostream>
#include <algorithm>

void Mapper::printMapping(){
  std::cout<< " M: ";
	int sizeOfMap = get_mapping()->size();
  for(int i = 0; i < sizeOfMap; i++){
		std::cout<<get_mapping()->at(i);
		if((i+1)%8==0 && i > 0)
			std::cout<< " ";
		}
		std::cout<<std::endl;
}

std::string Mapper::noPunc(const char *input){ //gets rid of input punctuation 
    std::string cipherText;
    for(const char *i = input; *i != '\0'; i++)
    {
        if(*i == '\r' || *i == '\t'){
            cipherText += " ";
        }
        else{
            for(int j = 0; j < 64; j++){
                if(Mapper::get_mapping()->at(j) == *i)
                {
                    cipherText += *i;
                    break;
                }
            }
        }
    }
    return cipherText;
}

std::string Mapper::fmap2(const char *input){ //gets rid of spaces and replace with '-'
    std::string str = "";
    for(const char *i = input; *i != '\0'; i++)
    {
        if(*i == ' '){
            str += "-";
        }
        else
            str += *i;
    }
    return str;
}

int Mapper::asciiToBit(char c){ //convert a char's ascii value to 6-bit value 
    //find char in vector then return index
    std::vector<char>::iterator i;
    i = std::find(Mapper::get_mapping()->begin(), Mapper::get_mapping()->end(), c);
    return std::distance(Mapper::get_mapping()->begin(), i);
}

int Mapper::bitToAscii(int bit){ //convert ascii value to 6-bit value 
    return Mapper::get_mapping()->at(bit);
}

void Mapper::rotate(){ //rotate mapping right by 1 
    std::rotate(get_mapping()->rbegin(), get_mapping()->rend() - 1, get_mapping()->rend());
}


