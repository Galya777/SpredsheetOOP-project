#pragma once
#include "TypesOfData.h"
#include <cstring>
#include <fstream>
/*
* This class represents the cell 
* Each cell has its own content and type
* The class is using dynamic memory
*/
class Cell:public TypesOfData
{
public:
	/// <summary>
	/// the big four
	/// </summary>
	/// <param name="content"></param>
	Cell(const char* content);
	Cell();
	Cell operator=(Cell& other);
	~Cell();

	//this function is filling the cell
	void fillCell(const char* fill);
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

	char* content; 
	Data typeOfCell;
private:
	//helping functions to initialize the big four
	void init(const char* content);
	void copy(Cell& other);
	void clear();
};

