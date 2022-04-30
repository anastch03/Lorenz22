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

class Parser // COMMAND LINE PARSING FROM https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
{
public:
    Parser(int &argc, char **argv)
    {
        for (int i = 1; i < argc; ++i)
            this->tokens.push_back(std::string(argv[i]));
    }
    ~Parser() {}
    const std::string &getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;

private:
    std::vector<std::string> tokens;
};

#endif