

#include <iostream>

using namespace std;

class StackException{
private:
	//error message
	string errorMessage;
	
public:
	//constructor that takes in error
	StackException(const string& error){
		errorMessage=(error);
	}
	//throws error
	string getError(){
		return errorMessage;
	}
};