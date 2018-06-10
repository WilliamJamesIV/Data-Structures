//sorting class.h
#ifndef SORTINGCLASS_H
#define SORTINGCLASS_H
//#include <SortingClass.cpp>
class sortingClass{

	public:
		void insertionSort(double arr[], int size);
		void quickSort(double arr[], int left, int right);
		void swap(double *a, double *b);
		void printArray(double arr[], int n);
		void shellSort(double arr[], int n);
	private:
		
};
#endif