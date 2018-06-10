//DelimiterChecker.cpp

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "GenStack.cpp"
//#include "DelimiterChecker.h"

using namespace std;

class DelimiterChecker{
	
private:
	string inFile = "";
	GenStack<char> stack; //create stack of char
	//compare delimiters and return true if they match and false if they dont match
	bool compareDelimiters(char openDelim,char closedDelim){
		if(openDelim=='{'&& closedDelim=='}')
			return true;
		else if (openDelim == '[' && closedDelim == ']')
			return true;
		else if (openDelim == '(' && closedDelim == ')')
			return true;
		else
			return false;
	}
	
public:
	//check all delimiters 
	bool checkDelimiters(){
		//open file
		fstream delimFile;
		delimFile.open(inFile.c_str()); //convert to cstring
		bool isOpen = delimFile.is_open(); //make sure file is open
		if(!isOpen)
			exit(0);
		int lineCount = 0;
		string tempLine = "";
		//sort file line by line
		while(getline(delimFile,tempLine)){
			++lineCount;
			//check each char in line
			for(int i = 0; i<tempLine.length();++i){
				char firstDelim;
				firstDelim = tempLine[i];
				//if char is an open delimiter push to stack
				if(firstDelim=='{' ||firstDelim == '['||firstDelim=='('  )
					stack.push(firstDelim);
				//if char is closed delimiter peek stack
				else if(firstDelim=='}'||firstDelim==']'||firstDelim==')'){
					char secondDelim;
					secondDelim = stack.peek();
					//if delimiters dont match tell report to user
					if(!compareDelimiters(secondDelim,firstDelim)){
						cout<<"Matching error with "<<secondDelim<<" at line: " <<lineCount<<" wrong delimiter is " << firstDelim<<endl;
						return false;
					}
					//if stack is empty throw exception and report error to user
					else if(stack.isEmpty()){
						throw StackException("Stack is empty");
						cout<<"Matching error with "<<secondDelim<<" at line: " <<lineCount<<" wrong delimiter is " << firstDelim<<endl;
						return false;
					}
					//pop stack if no errors
					else
						stack.pop();
				}
			}
		}
		//check if stack is empty, if it is return true, if it isnt return false
		bool emptyStack = stack.isEmpty();
		if(!emptyStack){
			cout<<"There was an error matching a "<<stack.pop()<<" at: line " <<lineCount<<endl;
			cout<<"Delimiter missing at end of program"<<endl;
			return false;
		}
		return true;
	};
	//constructor
	DelimiterChecker(string filename){
		inFile = filename;
	}
	//destructor
	~DelimiterChecker(){
		//delete[] stack;
	}
	
};