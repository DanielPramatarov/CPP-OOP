#include "InputParser.h"
#include <iostream>
#include <string>
Input readInput(){
    std::string word;
    char ch;
    int times;
    std::cin >> word >> ch >> times ;
    Input ret;
    ret.line = word;
    ret.letter = ch;
    ret.repetitions = times;
    return ret;

}