//sorting class.cpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "SortingClass.h"
using namespace std;
void insertionSort(double arr[], int size) {
	for(int j = 0; j < size; ++j){
		double temp = arr[j];
		int k = j;
		while( k > 0 && arr[k-1] >= temp){
			arr[k] = arr[k-1];
			--k;
		}
		arr[k] = temp;
	}
}
//function that swaps the values of an array
void swap(double *a, double *b){
	double t = *a;
	*a = *b;
	*b = t;
}

//QuickSort function
void quickSort(double arr[], int left, int right){
	
	int i = left;
	int j = right;
	double tmp;
	double pivot = arr[(left + right)/2];
	
	while (i <= j){
	
		while(arr[i] < pivot){
			++i;
		}
		while(arr[j] > pivot){
			--j;
		}
		if(i <= j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
		}
	}
	if(left < j)
		quickSort(arr, left, j);
	if(i < right)
		quickSort(arr, i, right);
}
//ShellSort function
void shellSort(double arr[], int n){
	
	for(int gap = (n/2) ;gap > 0; gap/=2){
		for(int i = gap;i < n;i +=1){
			double temp = arr[i];
			int j;
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	
	
}
//print array
void printArray(double arr[], int n){
	for (int i = 0;i < n;++i){
		cout << arr[i] << endl;
	}
}
