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
  std::string cipher_txt;
  if (Machine::get_verbose()){
    Machine::getMapper()->printMapping();
    Machine::getWheelAssembly()->readFile(); //read wheel settings and stores wheel setting info to each wheel
    Machine::getWheelAssembly()->printAllWheels();
  }
  const char *plainTxtChar = plain_txt.c_str();
  std::string toBeEncrypted = getMapper()->Mapper::noPunc(plainTxtChar); //string to be encrypted
  
  //for each char of toBeEncypted,
  std::vector<int> *bit = new std::vector<int>;
  
  for(char c : toBeEncrypted){
    //convert char to map number based on mapping & convert number to 6 bits and store in bit vector (lsb first)
    std::vector<int> *bitVect = new std::vector<int>;
    int iBit[6];
    convertToBit(getMapper()->asciiToBit(c), bit);
    for (unsigned int i = bit->size(); i < 6; i++)
      bit->push_back(0);
    //for each bit, 
      //xor with corresponding A, B, C wheels
      //store the bit in iBit[6] array
    for(int i = 0; i < 6; i++){
      iBit[i] = getWheelAssembly()->get_wheel(i, WheelAssembly::A)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::B)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::C)->get_current_pin();
    }
    //increment all wheels
    //increment wheels based on intermediate bits
    //convert intermediate bits to decimal number
    //convert decimal number to ascii with same mapping
    //add ascii char to char vector (this will later be converted to std::string as the cipher text)
  }
  //rotate mapping
  //convert any spaces in char vector to '-' (f-1 or something look back at steps)
  //convert the char vector to string

  //encrypt
  // Mapper m;
  // {
  //   for (char c : plain_txt)
  //   {
  //     m.Mapper::asciiToBit(c);

  //   }
  // }
  cipher_txt = plain_txt; //temp
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