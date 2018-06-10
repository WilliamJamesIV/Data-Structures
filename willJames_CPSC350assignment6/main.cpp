#include "SortingClass.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){
	//create ifstream and set command line arguement to string
	ifstream txtFile;
	string newInFile = argv[1];
	int size;
	int pos=0;
	//open file
	txtFile.open(newInFile.c_str());
	bool isOpen = txtFile.is_open();   //creates bool that checks if file is open
	if(!isOpen) //quit if not open
	{
		cout << "file not found please check file name" << endl;
		return 0;//quit	
	}
	//take in first line of file that is sizeof arrays
	txtFile >> size;
	double myArray[size];
	double myArray1[size];
	double myArray2[size];

	//put all of the doubles into an array
	for(int i = 0; i < size; i++){
		txtFile >> myArray[i];
	}
	//copy the array into 2 other arrays
	for(int i = 0; i < size; i++){
		myArray1[i] = myArray[i];
	}
	
	for(int i = 0; i < size; i++){
		myArray2[i] = myArray[i];
	}
	//close text file
	txtFile.close();
	//for timing functions
	clock_t insertionSortBegin;
	clock_t insertionSortEnd;
	clock_t quickSortBegin;
	clock_t quickSortEnd;
	clock_t shellSortBegin;
	clock_t shellSortEnd;
	//set arrays to pointers for functions
	double * insertionSortArray = myArray;
	double * quickSortArray = myArray1;
	double * shellSortArray = myArray2;
	
	//run the sorting functions and keep track of time
	
	//start clock
	insertionSortBegin = clock();
	//sort array using insertionsort
	insertionSort(insertionSortArray, size);
	//end clock
	insertionSortEnd = clock();

	
	//start clock
	shellSortBegin = clock();
	//sort array using shellsort
	shellSort(shellSortArray, size);
	//end clock
	shellSortEnd = clock();
	

	//start clock
	quickSortBegin = clock();
	//sort array using quicksort
	quickSort(quickSortArray, 0, (size-1));
	//stop clock
	quickSortEnd = clock();
	

	//convert the times into miliseconds
	double iTimeStart = insertionSortBegin/(double)(CLOCKS_PER_SEC/1000);
	double iTimeStop = insertionSortEnd/(double)(CLOCKS_PER_SEC/1000);
	double sTimeStart = shellSortBegin/(double)(CLOCKS_PER_SEC/1000);
	double sTimeStop = shellSortEnd/(double)(CLOCKS_PER_SEC/1000);
	double qTimeStart = quickSortBegin/(double)(CLOCKS_PER_SEC/1000);
	double qTimeStop = quickSortEnd/(double)(CLOCKS_PER_SEC/1000);
	
	//print out results
	
	cout << "Welcome to the insertionsort, quicksort, and shellSort program!" << endl;
	cout << "We are going to time the sorting algorithms mentioned above." << endl;
	cout << "Lets see how long it takes to sort doubles in the following text file: " << string(newInFile)<< endl;
	
	cout << "Insertion sort:" << endl;
	cout << "Start time: "<< iTimeStart << " miliseconds."<< endl;
	cout << "End time: " << iTimeStop << " miliseconds." << endl;
	cout << "Quicksort:" << endl; 
	cout <<"Start Time: "<<qTimeStart << " miliseconds."<<endl; 
	cout <<"End time: " << qTimeStop << " miliseconds." <<  endl;
	cout << "Shell sort:"<< endl;
	cout << "Start Time: "<<sTimeStart<< " miliseconds."<< endl; 
	cout << "End time: " << sTimeStop<< " miliseconds" << endl;
}
