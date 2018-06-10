//DelimiterChecker.h

#ifndef DELIMITERCHECKER_H
#define DEILIMITERCHECKER_H
#include <iostream>
#include <fstream>
#include "GenStack.cpp"

using namespace std;

class DelimiterChecker{
	
private:
	//make infile empty string
	string inFile = "";
	//create stack of char
	GenStack<char> stack;
	//compare selected delimiters
	bool compareDelimiters(char openDelim,char closedDelim);
	
public:
	//check if delimiters match 
	bool checkDelimiters();
	//constructor with filename
	DelimiterChecker(string filename);
	//destructor
	~DelimiterChecker();
	
};

#endif