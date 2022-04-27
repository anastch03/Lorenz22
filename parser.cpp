/*
File: parser.cpp
Author: Anastasia Chen
Date: 4/15/2022
*/
// Parser - command line parser
//  -h or --help: give a brief usage/help message  
//  -e: encryption mode.
//  -d: decryption mode.
//  -i <settings>: specify the initial settings for each wheel. <settings> is a string, see below. -i is optional. 
//  -t: Test mode. If specified, take plaintext input from stdin (one line at a time), 
    // run it through the encryption engine, (outputting the encrypted text), then through the decryption engine, 
    // and output the decrypted text to stdout one line at a time. 
    // Obviously, if you specify -t then -e, and -d, are invalid. 
//  -v: verbose mode. If specified, output the wheel settings, and each intermediate step. 
    // VERY useful for debugging, especially in combination with -t

#include <algorithm>
#include "parser.h"

//from StackOverflow; author: iain
const std::string& Parser::getCmdOption(const std::string &option) const{
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    static const std::string empty_string("");
    return empty_string;
}
bool Parser::cmdOptionExists(const std::string &option) const{
    return std::find(this->tokens.begin(), this->tokens.end(), option)
        != this->tokens.end();
}