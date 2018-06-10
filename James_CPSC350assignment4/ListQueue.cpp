//queue using a linked list
#include <iostream>
using namespace std;
#include<stdlib.h>
#include "List.cpp"

template <typename T>
class ListQueue{
	private:
		List<T>* data = NULL;
		int size;
	
	public:
		ListQueue(){
			data = new List<T>();
		}/*
		~ListQueue(){
			delete ;
		}*/
		bool isEmpty(){
			return data->isEmpty();
		}
		
		void enQueue(T d){
			data->insertTail(d);
		}//insert tail
		
		T deQueue(){
			return data->removeHead();
		}//remove head
		
		
};