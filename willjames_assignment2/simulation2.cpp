// simulation cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

class Simulation{

public:
	char boundryMode;
	char outputMode;
	char** worldP;
	string outfile = "gol.out";
	int generation=0;
	
	void getParams(){
			
		char a = 'y';
		string inPath = "";
		bool random = true;
		
		cout<<"What boundry mode would you like to use? c/d/m"<<endl;
		cin>>boundryMode;
		cout<<"Would you like to pause or press enter between generations (p/e) or output to a file (f):" <<endl;
		cin>>outputMode;
		
		cout<<"Would you like to generate a random assignment? y/n"<<endl;
		cin>>a;
		
		if(a == 'y'){
			random = true;
		}
		else if(a == 'n'){
			random = false;
		}
		else{
		}
		
		if(random){
			int b, c;
			double density;
			cout<<"What is the height of the world"<<endl;
			cin>>b;
			cout<<"What is the width of the world"<<endl;
			cin>>c;
			cout<<"What is the density of the world?" <<endl;
			cin>>density;
			
			worldP = new char*[b];
			for(int i = 0; i<b;++i){
				worldP[i] = new char [c];	
			}
			
			//generate random map
			worldP[b][c];
			for(int i = 0; i<b;++i){
				for(int j = 0; j<c;++j){
					double r = ((double)rand())/RAND_MAX;
					if(r<density){
						worldP[i][j]	= 'X';
					}
					else{
						worldP[i][j] = '-';
					}
				}
			}
		}
		else{
			cout<<"What is the name of the file with the world map?"<<endl;
			cin>>inPath;
		}
			
		for(int i = 0; i<sizeof(worldP);++i){
				for(int j = 0; j<sizeof(worldP[0]);++j){
					
						cout<<worldP[i][j];
					
				}
				cout<<endl;
			}
	}
	
	Simulation(){
		getParams();
	}
	/*~Simulation(){
		delete();
	}*/

};

int main(){
		Simulation s = Simulation();
		s.getParams();
}