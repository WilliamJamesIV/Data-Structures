// simulation header
#include <iostream>
#include <stdlib.h>

using namespace std;

class Simulation{

private:
	//variables
	char boundryMode;
	char outputMode;
	char** worldP;
	int generation = 0;
	int width;
	int height;
	bool isStable;
	//outfile
	string outfile = "gol.out";
	//functions
	int countNeighbors(int i, int j, char boundryMode);
	char outcome(int neighbors,char current);
	void output();
	
public:
	//functions
	void nextGeneration();
	void getParameters();
	Simulation(char bMode,char outMode,char** world);
	Simulation(char bMode,char outMode,char** world, string outfile);
	~Simulation();
};