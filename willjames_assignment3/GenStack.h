//stack.h
#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include "StackException.cpp"

using namespace std;

template <class E>
class GenStack{

private:
	//variables
	int index;
	int size;
	//create stack of class E
	E*stack;
	//increase size if stackis full
	void sizeIncrease();
	
	
public:
	//push
	void push(E data);
	//pop
	E pop();
	//peek
	E peek();
	
	
	//default constructor
	GenStack();
	//override constructor
	GenStack(int theSize);
	//destructor
	~GenStack();
	//check if stack is empty
	bool isEmpty();
	//check if stack is full
	bool isFull();
	
	
};

#endif