#pragma once
#include "TypesOfData.h"
#include <cstring>
#include <fstream>
#pragma warning(disable:4996)
/*
* This class represents the cell 
* Each cell has its own content and type
*/
class Cell
{
public:
	/// <summary>
	/// the big four
	/// </summary>
	/// <param name="content"></param>
	Cell(std::string content);
	Cell();
	Cell operator=(Cell& other);

	//this function is filling the cell
	void fillCell(std::string fill);
	//operator<< to shift data in a cell
	friend std::ostream& operator<<(std::ostream& out, const Cell& other);
	virtual void writeToFile(std::fstream& file) const;
	//editing a cell
	virtual void editCell(const char* NewContent);
	//printing the information
	virtual void print() const;
	//size of a cell
	void setSize();
	//returning the data type
	Data findType(const char* _content);

	
	bool operation(char& sym);
protected:

	std::string content; 
	Data typeOfCell;
	int sizeofData;
private:
	//helping functions to initialize the big four
	void init(const char* content);
	void copy(const Cell& other);
};

