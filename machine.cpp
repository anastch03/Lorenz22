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


std::string Machine::encrypt(){ //TODO 
  std::string plain_txt;
  std::cin >> plain_txt;
  std::string cipher_txt;
  if (Machine::get_verbose()){
    Machine::getMapper()->printMapping();
    Machine::getWheelAssembly()->readFile();
    Machine::getWheelAssembly()->printAllWheels();
  }
  const char *plainTxtChar = plain_txt.c_str();
  std::string toBeEncrypted = getMapper()->Mapper::noPunc(plainTxtChar); //string to be encrypted

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