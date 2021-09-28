#ifndef __STRINGWRAPPER_H__
#define __STRINGWRAPPER_H__
#include <string>
#include <iostream>
#include "InputParser.h"

class StringWrapper
{
private:
    std::string line;
    char ch = '0';
    int repetitions;
    std::string result = "";

public:
    StringWrapper(){};
    StringWrapper(std::string line) : line(line){};
    StringWrapper(char ch, int repetitions) : ch(ch), repetitions(repetitions){};

    StringWrapper &append(const std::string &line);
     std::string getContent() const;
    void printContent();
};

void StringWrapper::printContent()
{
    std::cout << result << std::endl;
}
StringWrapper &StringWrapper::append(const std::string &line)
{

    result += line;
    return *this;
}
 std::string StringWrapper::getContent() const
{
    if (ch == '0')
    {
        return line;
    }
    std::string stuff(repetitions, ch);

    return stuff;
}

#endif // __STRINGWRAPPER_H__