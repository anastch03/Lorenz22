/*
File: machine.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/

// Machine - encapsulates the entire machine. 
// In other words, this machine holds the collection of wheels, mappers. 
// Your program will only need to create one (or two with -t) instances of this class.

#include "wheel.h"
#include "machine.h"
#include <fstream>
#include <cmath> 
#include <algorithm>

//DECIMAL TO HEX FUNCTION FROM https://www.educative.io/edpresso/how-to-convert-a-number-from-decimal-to-hexadecimal-in-cpp
std::string decToHex(int decimal){
  int remainder, product = 1;
  std::string hex_dec = "";
  while (decimal != 0) {
    remainder = decimal % 16;
    char ch;
    if (remainder >= 10)
      ch = remainder + 55;
    else
      ch = remainder + 48;
    hex_dec += ch;
  
    decimal = decimal / 16;
    product *= 10;
  }
  reverse(hex_dec.begin(), hex_dec.end());
  return hex_dec;
}

void Machine::convertToBit(char c, std::vector<int> *bitVect){ //takes an empty int vector and add each bit of c to vector (lsb first)
  if(c <= 1){
    bitVect->push_back(c%2);
    return;
  }
  bitVect->push_back(c%2);
  convertToBit(c/2, bitVect);
}

int Machine::bitToDec(std::vector<int> *bitVect){
  int num = 0;
  for(int i = 0; i < 6; i++){
    num += bitVect->at(i) * pow(2, i);
  }
  return num;
}

std::string Machine::encrypt(){ //TODO 
  std::string plain_txt;
  std::cin >> plain_txt;
  std::string cipher_txt = "";
  if (Machine::get_verbose()){
    Machine::getMapper()->printMapping();
    Machine::getWheelAssembly()->printAllWheels();
  }
  const char *plainTxtChar = plain_txt.c_str();
  std::string toBeEncrypted = getMapper()->Mapper::noPunc(plainTxtChar); //string to be encrypted
  
  //for each char of toBeEncypted,
  for(char c : toBeEncrypted){
    //convert char to map number based on mapping & convert number to 6 bits and store in bit vector (lsb first)
    std::vector<int> *bits = new std::vector<int>;
    std::vector<int> *intermBits = new std::vector<int>; 
    convertToBit(getMapper()->asciiToBit(c), bits);
    for (unsigned int i = bits->size(); i < 6; i++)
      bits->push_back(0);
    //for each bit, 
      //xor with corresponding A, B, C wheels
      //store the bit in intermBits vector
    for(int i = 0; i < 6; i++){
      intermBits->push_back(getWheelAssembly()->get_wheel(i, WheelAssembly::A)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::B)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::C)->get_current_pin()); 
    }
    if(get_verbose())
    {
      //make vector from wheel settings TODO
      //print xor operations
    }

    //increment all wheels
    getWheelAssembly()->WheelAssembly::incrementAll();
    if(get_verbose())
    {
      Machine::getWheelAssembly()->printAllWheels();
    }

    //increment wheels based on intermediate bits
    Machine::getWheelAssembly()->increment_i(intermBits);
    if(get_verbose())
    {
      //print verbose operations for increment_i TODO
      Machine::getWheelAssembly()->printAllWheels();
    }
    

    //convert intermediate bits to decimal number
    int dec = bitToDec(intermBits);

    //convert decimal number to ascii with same mapping & 
    //add ascii char to string 
    cipher_txt += getMapper()->Mapper::bitToAscii(dec);
  }

  //rotate mapping BUGGED
  getMapper()->rotate();
  getMapper()->printMapping();
  //convert any spaces in char vector to '-' (f-1 or something look back at steps)
  //convert the char vector to string
  // cipher_txt = plain_txt; //temp/
  return cipher_txt;
  
}

std::string Machine::decrypt_helper(){
  std::cout<<"Enter text to decrypt:";
  std::string cipher_txt;
  std::cin >> cipher_txt;
  return cipher_txt;
}

std::string Machine::decrypt(std::string cipherText){ //TODO  
  std::string plain_txt;
  //decrypt
  plain_txt = cipherText; //temp
  return plain_txt;
}

void Machine::test(){ 
  std::cout<< "Enter text to test:"<<std::endl;
  std::string cipherTxt = Machine::encrypt();
  std::cout << "encrypted text: " << cipherTxt <<std::endl;
  std::cout << "decrypted text: " << Machine::decrypt(cipherTxt)<<std::endl;
  //TODO if strings match, print strings match
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