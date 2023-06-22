#pragma once
/*
* The class whici is representing the engine of the programm
* Comands here are:
* opening a file
* saving into same/new file
* editing the table
* printing the table
*/
#include <fstream>
#include <string>
#include <iomanip>
#include "Table.h"
const int MAX_CONTENT = 100;
const int MAX_FILE = 100;
class Commands
{
public:
	Commands(const char* com);
	Commands();
	void open();
	void close();
	void save();
	void saveAs();
	void CreatenewFile();

	void edit(int row, int col);
	void print();
	void run();

private:
	Table table;
	std::string command;
	std::fstream oldFile;
	std::ifstream newFile;
	char file[MAX_FILE];
	int row, col;
	std::string cellFilling;
};

