//life2.cpp

#include "simulation.cpp"

using namespace std;

int main(){
	cout << "Welcome to the Game Of Life by J.H. Conway" << endl;
	Simulation life = Simulation();
	int count=0;
	while(count<50 && life.getStable()==false){
		cout<<count<<endl;
		life.nextGeneration();	
		++count;
	}
	
}