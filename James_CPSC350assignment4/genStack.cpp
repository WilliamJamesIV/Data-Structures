//genStack.cpp

//#include "genStack.h"
#include <iostream>
#include "stackError.cpp"

using namespace std;

template <typename T>
class genStack{

private:
	
	int index = -1;
	int size = 10;
	T *stack = NULL;
	
	
	void increaseSize(){
		T * newStack  = new T [size+10];
		for(int i = 0; i<=index;++i){
			newStack[i]=stack[i];	
		}
		stack = newStack;
		size = size+10;
	}
	
	
public:
	
	T peek(){
		if(isEmpty()){
			throw stackException("Stack is empty");	
		}
		return stack[index];
	}
	
	T pop(){
		if(isEmpty()){
			throw stackException("Stack is empty");
		}
		return stack[index--];
	}
	
	void push(T thing){
		if(isFull()){
			increaseSize();	
		}
		stack[++index] = thing;
	}
	
	genStack(){
		//default size 10
		stack  = new T [10];
	}
	
	genStack(int initialSize){
		stack = new T [initialSize];
		size = initialSize;
	}
	
	~genStack(){
	}
	
	bool isFull(){
		if(size-1 == index){
			return true;
		}
		else{
			return false;
		}
	}
	
	bool isEmpty(){
		if(index < 0){
			return true;
		}
		else{
			return false;
		}
	}
	
};
