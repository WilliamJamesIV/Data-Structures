//List

#include<iostream>
#include "pNode.cpp"

using namespace std;

template <typename T>
class List{
private:
	int size;
	pNode<T>* head = NULL;
	pNode<T>* tail = NULL;
	
public:
	
	List(){
		size = 0;
	}
	
	void insertHead(T data){
		if(size == 0){
			pNode<T>* n = new pNode<T>(data);
			size = 1;	
			head=n;
			tail=n;
		}
		else{
			pNode<T>* n = new pNode<T>(data);
			++size;
			n->next=head;
			head->prev=n;
			head=n;
		}
	}
	
	void insertTail(T data){
		if(size == 0){
			pNode<T>* n = new pNode<T>(data);
			size = 1;	
			head=n;
			tail=n;
		}
		else{
			pNode<T>* n = new pNode<T>(data);
			++size;
			n->prev=tail;
			tail->next=n;
			tail=n;
		}
	}
	
	T removeTail(){
		--size;
		if(size == 0){
			T temp = tail->data;
			delete(tail);
			return temp;
		}
		else{
			T temp = tail->data;
			pNode<T> * t = tail;
			tail=tail->prev;
			delete(t);
			tail->next = NULL;
			return temp;
		}
	}
	
	T removeHead(){
		--size;
		if(size == 0){
			T temp = head-> data;
			delete(head);
			return temp;
		}
		else{
			T temp = head->data;
			pNode<T>* t = head;
			head = head->next;
			delete(t);
			head->prev = NULL;
			return temp;
		}
	}
	
	bool isEmpty(){
		if(size>0){
			return false;
		}
		else{
			return true;
		}
	}
	
	int getSize(){
		return size;
	}
	
	void increment(){
		if(size == 0){
			return;
		}
		pNode<T>* t = head;
		while(t != NULL){
			t->data++;
			t = t->next;
		}
		delete t;
	}
	
	
};