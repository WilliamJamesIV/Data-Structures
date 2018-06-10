// simulation cpp
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class Simulation{

private:
	char boundryMode;
	char outputMode;
	char** worldP = NULL;
	string outfile = "gol.out";
	int generation=0;
	int width = 0;
	int height = 0;
	bool isStable = false;
	//counts the neighbors
	int countNeighbors(int i, int j){
		int count = 0;
		int left, right, top, bottom;
		
		//classic
		if(boundryMode == 'c'){
			if(i-1<0){
				top = 0;	
			}else{
				top= i-1;
			}
			if(i+1>=height){
				bottom = height-1;
			}
			else{
				bottom = i+1;
			}
			if(j-1<0){
				left = 0;
			}
			else{
				left = j-1;
			}
			if(j+1>=width){
				right = width-1;
			}
			else{
				right = j+1;
			}
			//cout<< top<<'\t'<<bottom<<'\t'<<left<<'\t'<<right<<endl;

			for (int t = top;t<=bottom;++t){
				for(int l = left;l<=right;++l){
					
					//cout<<top<<'\t'<<l<<endl;
					//cout<<bottom<<'\t'<<right<<endl;
					if(t==i && l==j){
						continue;
					}
					if( worldP[t][l] == 'X'){
						++count;
					}
				}
			}
			return count;
		}
		//doughnut
		/*
		else if (boundryMode == 'd'){
			int x,y;
			for(int h = i-1; h <= i+1;++h){
				for ( int p = j-1; p<= j+1; ++p){
					cout<<h<<'\t'<<p<<endl;
					
					if(h<0){
						x = height-1;
					}
					else if(h>=height){
						x = 0;
					}
					if(p<0){
						y = width-1;	
					}
					else if(p>=width){
						y = 0;
					}
					if(worldP[x][y]=='X'){
						++count;
					}
				}
			}
			cout<<count<<endl;
			return count;
		}
		*/
		//mirror
		else if (boundryMode == 'm'){
			
			
			return count;
		}
	}
	//outcome function
	char outcome(int neighbors,char current){
		if (neighbors<=1){
			return '-';
		}
		else if (neighbors ==2){
			if(current == '-'){
				return '-';
			}
			else if(current == 'X'){
				return 'X';
			}
		}
		else if(neighbors == 3){
			return 'X';
		}
		else if (neighbors >= 4){
			return '-';
		}
	}
	//print output
	void output(){
		
		//if output is pause between generations
		if (outputMode=='p'){
			cout<<generation<<endl;
			for(int i = 0; i<height;++i){
				for(int j = 0; j<width;++j){
					cout<<worldP[i][j];
				}
				cout<<'\n';
			}
			system("read"); 
		}
		//if output is pressing enter between generations
		else if (outputMode == 'e'){
			cout<<generation<<endl;
			for(int i = 0; i<height;++i){
				for(int j = 0; j<width;++j){
					cout<<worldP[i][j];
				}
				cout<<'\n';
			}
			cout << "please press enter to continue" << endl;
			cin.ignore();
			
		}
		//if output to file
		else if (outputMode == 'f'){
			string out = this->outfile;
			ofstream outFile (out.c_str(), ios::app);
			if (outFile.is_open()){
				for(int i = 0; i<height;++i){
					for(int j = 0; j<width;++j){
						outFile<<worldP[i][j];
					}
					outFile<<'\n';
				}
			} 
		}
	}
	//get parameters
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
			this->height = b;
			cout<<"What is the width of the world"<<endl;
			cin>>c;
			this->width = c;
			cout<<"What is the density of the world?" <<endl;
			cin>>density;
			
			this->worldP = new char*[b];
			for(int i = 0; i<b;++i){
				this->worldP[i] = new char [c];	
			}
			
			//generate random map
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
			//readin(inPath);
			//tester.txt
		}
	}
	
	bool checkStable(char** ar){
		bool stable = false;
		int total = width*height;
		int count = 0;
		for(int i = 0;i<height;++i){
			for(int j = 0; j<width;++j){
				if(ar[i][j] == worldP[i][j]){
					++count;	
				}
			}
		}
		if(count == total){
			return true;
		}
		else{
			return false;
		}
	}
	/*
	void readin(string filename){
		ifstream in (filename.c_str());
		int count = 0;
		for(count = 0; count<2;++count){
			string line = in.getline();
			if(count = 0){
				int Number;
				if ( ! (istringstream(line) >> Number) ) Number = 0;
				this->height = Number;	
			}
			else if(count = 1){
				int Number;
				if ( ! (istringstream(line) >> Number) ) Number = 0;
				this->width = Number;
			}	
			count;
		}
		this->worldP = new char*[height];
		for(int i = 0;i<width;++i){
			this->worldP[0] = new char[width];	
		}
		for(int i = 0; i<height;++i){
			string line = getline(in,line);
			for(int j = 0;j<width;++j){
				this->worldP[i][j] = line[j];
			}
		}

	}
	*/
	
public:
	//get isStable 
	bool getStable(){
		return isStable;
	}
	// next generation
	void nextGeneration(){
		
		int worldR = height;
		int worldC = width;
		char** newWorld;
		
		newWorld = new char*[height];
		for(int i = 0; i<height;++i){
			newWorld[i] = new char [width];
		}
		for(int i = 0; i<height;++i){
			//cout<<i;
			for(int j = 0; j<width;++j){
				int a = countNeighbors(i,j);
				//cout<<a<<endl;
				char b = outcome(a,worldP[i][j]);
				//cout<<b<<endl;
				newWorld[i][j] = b;
				//cout<<newWorld[i][j]<<endl;
				
			}
		}
		
		this->isStable = checkStable(newWorld);
		this->worldP = newWorld;
		++generation;
		output();
		//delete(newWorld);
	}

	Simulation(){
		getParams();
		output();
	}
	/*
	~Simulation(){
		delete();
	}
	*/
};