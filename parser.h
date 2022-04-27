/*
File: parser.h
Author: Anastasia Chen
Date: 4/15/2022
*/

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>

class Parser //from StackOverflow; author: iain
{
public:
    Parser (int &argc, char **argv){
        for (int i=1; i < argc; ++i)
            this->tokens.push_back(std::string(argv[i]));
    }
    const std::string& getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
    ~Parser();
private:
    std::vector <std::string> tokens;
};

Parser::~Parser()
{
}

#endif