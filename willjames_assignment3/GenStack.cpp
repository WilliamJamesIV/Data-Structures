//genStack.cpp

//#include "genStack.h"
#include <cstdlib>
#include <iostream>
#include "StackException.cpp"

using namespace std;

template <typename E>
class GenStack{

private:
	//variables
	int index = -1;
	int size = 10;
	//stack that is null
	E *stack = NULL;
	
	//increase size of stack is stack is full
	void sizeIncrease(){
		size+=10;
		E * tempStack  = new E [size];
		for(int i = 0; i<=index;++i){
			tempStack[i]=stack[i];	
		}
		stack = tempStack;
	}
	
	
public:
	//push function
	void push(E data){
		if(isFull())
			sizeIncrease();	
		stack[++index] = data;
	}
	//pop function
	E pop(){
		if(isEmpty())
			throw StackException("Stack is empty");
		return stack[index--];
	}
	
	//peek function
	E peek(){
		if(isEmpty())
			throw StackException("Stack is empty");	
		return stack[index];
	}
	//default constructor
	GenStack(){
		//default size 10
		stack  = new E [10];
	}
	//override constructor
	GenStack(int theSize){
		stack = new E [theSize];
		size = theSize;
	}
	//destructor
	~GenStack(){
		delete stack;
	}
	//check if stack is empty
	bool isEmpty(){
		if(index < 0)
			return true;
		else
			return false;
	}
	//check if stack is full
	bool isFull(){
		if(size-1 == index)
			return true;
		else
			return false;
	}
	
	
	
};
