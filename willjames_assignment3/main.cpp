//main.cpp

#include "DelimiterChecker.cpp"
#include <iostream>

using namespace std;

int main(int argc,char **argv){
	bool choice = true;
	while(choice){
		string filename = argv[1];
		cout << "Welcome to the Delimiter Checker program" << endl;
		DelimiterChecker d = DelimiterChecker(filename);
		
		bool complete = d.checkDelimiters();
		
		
		if(complete){
			cout<<filename<<" has no delimiter errors."<<endl;
			cout << "do you want analyze another file? (y for yes, anything else for no)" << endl;
			string answer = "";
			cin >> answer;
			if(answer == "y")
				choice = true;
			else
				choice = false;
			}
		else{
			cout<<"There is a Delimiter error in file. Please Check the error statement above."<<endl;
			choice = false;
		}
		
	}
}