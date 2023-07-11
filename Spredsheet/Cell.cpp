#include "Cell.h"
#include <fstream>
#include <iostream>
#pragma warning(disable:4996)
Cell::Cell(std::string content)
{
    content = "";
}

Cell::Cell()
{
    init("");
}

Cell Cell::operator=(Cell& other)
{
    if (this != &other) {
        //clear();
        copy(other);
    }
    return *this;
}



void Cell::fillCell(std::string fill)
{
    content = fill;
    data = findType(fill.c_str());
}

void Cell::writeToFile(std::fstream& file) const
{
    file << content; //we do not need the type, just the content
}

void Cell::editCell(const char* NewContent) 
{
    content = "";
    this->content = NewContent;
}

void Cell::print() const
{
    std::cout << content;
}

void Cell::setSize()
{
    sizeofData = content.size();
}

Data Cell::findType(const char* _content)
{
    bool dot = false;
    
    if (_content[0] == '=') {
        return Data::FORMULA;
    }
    else if (_content="\0") {
        return Data::EMPTY;
    }
    else if(isdigit(atoi(_content))) {
        for (int i = 0; i < strlen(_content)-1; ++i) {
            if (_content[i] == '.') {
                return Data::DOUBLE;
            }
        }
        return Data::INTIGER;
    }  else {
        for (int i = 0; i < strlen(_content) - 1; ++i) {
            if (_content[i] == '\""') {
                return Data::STRING;
            }
        }
    }



    return Data::UNKNOWN;
}

void Cell::init(const char* content)
{
    this->content = new char[strlen(content) + 1];
    this->content= content;
    typeOfCell = findType(content);
}

void Cell::copy(const Cell& other)
{
    this->content= other.content;
    this->typeOfCell = other.typeOfCell;
}

std::ostream& operator<<(std::ostream& out, const Cell& other)
{
    out << other.content;
    return out;
}
bool Cell::operation(char& sym)
{
    if (sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '^') {
        return true;
    }
    return false;
}