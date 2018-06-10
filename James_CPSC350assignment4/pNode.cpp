//Public Node

using namespace std;

template <typename T>
class pNode{
public:
	T data;
	pNode<T>* next = NULL;
	pNode<T>* prev = NULL;
	
	pNode<T>(T d){
		data = d;
	}
};