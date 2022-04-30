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



void Machine::convertToBinary(int num, std::vector<int> *bitVect){ //takes an empty int vector and add each bit of c to vector (lsb first)
  if(num <= 1){
    bitVect->push_back(num%2);
    return;
  }
  bitVect->push_back(num%2);
  convertToBinary(num/2, bitVect);
}


int Machine::binaryToDec(std::vector<int> *bitVect){
  int num = 0;
  for(int i = 0; i < 6; i++){
    num += bitVect->at(i) * pow(2, i);
  }
  return num;
}

void Machine::test(std::string setting){
  std::cout<< "Enter text to test:"<<std::endl;
  std::string plain_txt;
  std::getline(std::cin, plain_txt);
  std::string cipherTxt = encrypt(plain_txt);
  if(setting.compare(""))
    Machine::settings(setting.c_str());
  else  
    getWheelAssembly()->resetWheels();
  getMapper()->resetMapper();
  std::string decrypted = decrypt(cipherTxt);
  int count = 0;
  for(char c : cipherTxt)
  {
      if (count == 5){
          count = 0;
          std::cout << " ";
      }
      std::cout<< c;
      count++;
  }
  std::cout<< "\n";
  std::cout << decrypted <<std::endl;
  if(plain_txt.compare(decrypted) == 0)
    std::cout<<"String match\n";
  else
    std::cout<<"String DO NOT match\n";
}

std::string Machine::decrypt_helper(){
  std::cout<<"Enter text to decrypt:\n";
  std::string cipher_txt;
  std::getline(std::cin, cipher_txt);
  int count = 0;
  std::string cipherText2 ="";
  for(char c : cipher_txt)
  {
    if (count == 5){
        count = 0;
        continue;
    }
    cipherText2+=c;
    count++;
  }
  return cipherText2;
}

std::string Machine::decrypt(std::string cipherText){ 
  std::string plain_txt;
  std::string toBeDecrypted = Mapper::fmap2_d(cipherText.c_str());
  if (get_verbose()){
    getMapper()->printMapping();
    getWheelAssembly()->printAllWheels();
  }
  for(char c : toBeDecrypted){
    //convert decrypted char to number based on mapping & convert number to 6 bits and store in bit vector (lsb first)
    std::vector<int> *bits = new std::vector<int>;
    std::vector<int> *intermBits = new std::vector<int>; 
    convertToBinary(getMapper()->asciiToBit(c), bits); //converts the mapper number to binary stored in bits vector
    for (unsigned int i = bits->size(); i < 6; i++) //fills bits vector up to size 6
      bits->push_back(0); 
    //for each bit, 
      //xor with corresponding A, B, C wheels
      //store the bit in intermBits vector
    for(int i = 0; i < 6; i++){
      intermBits->push_back(bits->at(i) ^ getWheelAssembly()->get_wheel(i, WheelAssembly::A)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::B)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::C)->get_current_pin());
    }
    std::string ibitsInHex = decToHex(binaryToDec(intermBits));
    if(get_verbose())
    {
      std::string A = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::A)));
      std::string B = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::B)));
      std::string C = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::C)));
      //print operations
      std::string hex = decToHex(getMapper()->asciiToBit(c));
      std::cout<< "f("<< c << ")=" << hex <<" "<<hex<<"^"<<A<<"^"<<B<<"^"<<C<<"="<< ibitsInHex <<std::endl;

    }
    //increment all wheels
    getWheelAssembly()->WheelAssembly::incrementAll();
    if(get_verbose())
    {
      getWheelAssembly()->printAllWheels();
    }

    //increment wheels based on intermediate bits
    if(get_verbose())
    {
      std::cout << (char)getMapper()->asciiToBit(c) << "=";
      for(int b : *bits)
        std::cout<< b;
      std::cout << " "<<getWheelAssembly()->increment_i(*bits)<<std::endl;
      getWheelAssembly()->printAllWheels();
    }
    else
      getWheelAssembly()->increment_i(*bits);
      
    //convert intermediate bits to decimal number
    int dec = binaryToDec(intermBits);

    //convert decimal number to ascii with same mapping & 
    //add ascii char to string 
    plain_txt += getMapper()->Mapper::bitToAscii(dec);

    //rotate mapping 
    getMapper()->rotate();
    if(get_verbose())
      std::cout<<"f-1("<< ibitsInHex << ")=" << (char)(getMapper()->Mapper::bitToAscii(dec-1))<<std::endl;
  }
  return plain_txt;

}
std::string Machine::encrypt(std::string plain_txt){ 
  std::string cipher_txt = "";
  if (get_verbose()){
    getMapper()->printMapping();
    getWheelAssembly()->printAllWheels();
  }
  const char *plainTxtChar = plain_txt.c_str(); //converts string to const char*
  std::string toBeEncrypted = getMapper()->Mapper::noPunc(plainTxtChar); //string to be encrypted
  //for each char of toBeEncypted,
  for(char c : toBeEncrypted){
    //convert char to map number based on mapping & convert number to 6 bits and store in bit vector (lsb first)
    std::vector<int> *bits = new std::vector<int>;
    std::vector<int> *intermBits = new std::vector<int>; 
    convertToBinary(getMapper()->asciiToBit(c), bits); //converts the mapper number to binary stored in bits vector
    for (unsigned int i = bits->size(); i < 6; i++) //fills bits vector up to size 6
      bits->push_back(0); 
    //for each bit, 
      //xor with corresponding A, B, C wheels
      //store the bit in intermBits vector
    for(int i = 0; i < 6; i++){
      intermBits->push_back(bits->at(i) ^ getWheelAssembly()->get_wheel(i, WheelAssembly::A)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::B)->get_current_pin() ^ getWheelAssembly()->get_wheel(i, WheelAssembly::C)->get_current_pin());
    }
    std::string ibitsInHex = decToHex(binaryToDec(intermBits));
    if(get_verbose())
    {
      std::string A = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::A)));
      std::string B = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::B)));
      std::string C = decToHex(binaryToDec(getWheelAssembly()->getWheelVector(WheelAssembly::C)));
      //print operations
      std::string hex = decToHex(getMapper()->asciiToBit(c));
      std::cout<< "f("<< c << ")=" << hex <<" "<<hex<<"^"<<A<<"^"<<B<<"^"<<C<<"="<< ibitsInHex <<std::endl;

    }
    //increment all wheels
    getWheelAssembly()->WheelAssembly::incrementAll();
    if(get_verbose())
    {
      getWheelAssembly()->printAllWheels();
    }

    //increment wheels based on intermediate bits
    if(get_verbose())
    {
      std::cout << ibitsInHex << "=";
      for(int b : *intermBits)
        std::cout<< b;
      std::cout << " "<<getWheelAssembly()->increment_i(*intermBits)<<std::endl;
      getWheelAssembly()->printAllWheels();
    }
    else
      getWheelAssembly()->increment_i(*intermBits);
      
    

    //convert intermediate bits to decimal number
    int dec = binaryToDec(intermBits);

    //convert decimal number to ascii with same mapping & 
    //add ascii char to string 
    cipher_txt += getMapper()->Mapper::bitToAscii(dec);
    //rotate mapping 
    getMapper()->rotate();

    if(get_verbose())
      std::cout<<"f-1("<< ibitsInHex << ")=" << (char)(getMapper()->Mapper::bitToAscii(dec)-1)<<std::endl;
  }

  //convert any spaces in char vector to '-'
  const char *cipherTxtChar = cipher_txt.c_str();
  return Mapper::fmap2(cipherTxtChar);
  
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

void Machine::settings(const char * settings){
  const int MAX = 18;
  int j = 0;
  int k = 0;
  int num_of_pins;
  int new_pos;
  int c;
  for(int i = 1; settings[i] != '\0' && i <= MAX; i++){
    num_of_pins = getWheelAssembly()->get_wheel(j,k)->get_num_pins();
    c = (int)(settings[i-1]);
    new_pos = c%num_of_pins;
    getWheelAssembly()->get_wheel(j,k)->set_current_pos(new_pos);
    j = i/3;
    k = (k+1)%3;
  }
  std::cout<<"\n";
}

//DECIMAL TO HEX FUNCTION FROM https://www.educative.io/edpresso/how-to-convert-a-number-from-decimal-to-hexadecimal-in-cpp
std::string Machine::decToHex(int decimal){
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