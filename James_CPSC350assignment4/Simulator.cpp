//Window waiting simulation

#include "ListQueue.cpp"
#include "genStack.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	//take in file from command prompt
	string filename = argv[1];
	string line = "";
	int size;
	int nextArrival;
	int time = 0;
	//new listqueue
	ListQueue<int> q = ListQueue<int>();
	
	ifstream fs;
	fs.open(filename.c_str());
	fs>>size;
	int windows [size];
	int windowWait [size];
	for(int i =0;i<size;++i){
		windows[i] = 0;
		windowWait[i] = 0;
	}
	fs>>nextArrival;
	//variables for calculations
	int available = size;
	int totalStudents = 0;
	int totalWait = 0;
	int longestWait = 0;
	int over10 = 0;
	int totalWindowWait = 0;
	int longestWindow = 0;
	int over5 = 0;
	int dumps = 0;
	List<int> waitList = List<int>();
	genStack<int> waits = genStack<int>();
	
	
	//main time simulation
	while(true){
		
		++time;
		waitList.increment();
		//cout<<time<<endl;
		
		//subtract time from occupied windows
		for(int i=0;i<size;++i){
			if(windows[i] == 0){
				++windowWait[i];
			}
			else if(windows[i]>0){
				--windows[i];
				if(windows[i]==0){
					++available;
				}
			}
			//cout<<windows[i]<<'\t';
		}
		//cout<<endl;
		
		//add new students to queue
		if(time == nextArrival){
			int newStudents;
			fs>>newStudents;
			totalStudents += newStudents;
			for(int i = 0;i<newStudents;++i){
				int wait;
				fs>>wait;
				q.enQueue(wait);
				waitList.insertTail(0);
			}
			fs>>nextArrival;
		}	
		
		//dequeue if there are available windows
		while(available>0 && !q.isEmpty()){
			for(int i = 0; i<size;++i){
				if(windows[i]==0){
					windows[i] = q.deQueue();
					int w = waitList.removeHead();
					waits.push(w);
					if(w >= 10){
						++over10;
					}
					if(w>longestWait){
						longestWait = w;
					}
					totalWait += w;
					--available;
					totalWindowWait += windowWait[i];
					if(windowWait[i]>longestWindow){
						longestWindow = windowWait[i];
					}
					if(windowWait[i] >= 5){
						++over5;
					}
					windowWait[i]=0;
					++dumps;
				}
				
				if(q.isEmpty()){
					break;
				}
			}
		}
		//cout<<q.isEmpty()<<"\t"<<(available==size)<<'\t'<< !fs.eof()<<endl;
		//quit if file empty and all windows open and queue is empty
		if(q.isEmpty() && available == size && fs.eof()){
			break;
		}
	}
	
	for(int i = 0; i<size;++i){
		if(windowWait>0){
			totalWindowWait += windowWait[i];
			if(windowWait[i]>longestWindow){
				longestWindow = windowWait[i];
			}
			if(windowWait[i] >= 5){
				++over5;
			}
			windowWait[i]=0;
			++dumps;
		}
	}
	
	int arr [totalStudents];
	int index = 0;
	while(!waits.isEmpty()){
		arr[index]=waits.pop();
		++index;
	}
	//bubble sort
		for (int i = 0; i < totalStudents; i++) {
			for (int j = 0; j < totalStudents-1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
        }
	
	double meanWindow = totalWindowWait/dumps;
	double meanWait = totalWait/totalStudents;
	cout << "Welcome to the Registrar's Office Simulation program!" << endl;
	cout<<"Metrics for "<<filename<<endl;
	cout<<"1. The mean student wait time: "<<meanWait<<endl;
	cout<<"2. The median student wait time: "<<arr[index/2]<<endl;
	cout<<"3. The longest student wait time: "<<longestWait<<endl;
	cout<<"4. The number of students waiting over 10 minutes: "<<over10<<endl;
	cout<<"5. The mean window idle time: "<<meanWindow<<endl;
	cout<<"6. The longest window idle time: "<< longestWindow<<endl;
	cout<<"7. Number of windows idle for over 5 minutes: "<<over5<<endl;
	
}