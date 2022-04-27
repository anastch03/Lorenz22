/*
File: machine.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

// Machine - encapsulates the entire machine. 
// In other words, this machine holds the collection of wheels, mappers. 
// Your program will only need to create one (or two with -t) instances of this class.

#include "mapper.h"
#include "wheel.h"
#include "machine.h"
#include <fstream>

std::string Machine::encrypt(){ //TODO 
  std::string plain_txt;
  std::cin >> plain_txt;
  std::string cipher_txt;
  //encrypt
  // Mapper m;
  // {
  //   for (char c : plain_txt)
  //   {
  //     m.Mapper::asciiToBit(c);

  //   }
  // }
  std::cin >> cipher_txt; //temp
  return cipher_txt;
  
}

std::string Machine::decrypt(){ //TODO  
  std::string cipher_txt;
  std::cin >> cipher_txt;
  std::string plain_txt;
  //decrypt
  std::cin >> plain_txt; //temp
  return plain_txt;
}

void Machine::test(){ 
  std::cout<< "Enter text to test:"<<std::endl;
  std::cout << Machine::encrypt();
  std::cout << Machine::decrypt();

}

void Machine::printMapping(){
  for(int i = 0; i < 65; i++){
    std::cout<< Mapper::get_mapping()->at(i);
    if(i%8==0)
      std::cout<< " ";
  }
}
void Machine::printWheelSettings(){ //TODO

  std::ifstream wheel_settings("wheel.txt");
    if (wheel_settings.is_open())
      std::cout << wheel_settings.rdbuf();
}

void Machine::help(){
  std::cout<<"Usage: l22 [options]"<<std::endl
          <<"Encrypts or decrypts a line of text using a method similar to the Lorenz SZ40"<<std::endl
          <<"Options:"<<std::endl
          <<"-d            decrypt"<<std::endl
          <<"-e            encrypt"<<std::endl
          <<"-h --help     print this message"<<std::endl
          <<"-i <settings> set initial wheel settings"<<std::endl
          <<"-t            test (encrypt, then decrypt)" <<std::endl
          <<"<settings> is a string used to set the wheels."<<std::endl;
}