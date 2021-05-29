#include<iostream>
using namespace std;

template<typename T>
class Queue{
	T *data;
	int firstIndex;
	int nextIndex;
	int size;
	int capacity;
	
	public:
		Queue(){
			data = new T[4];
			firstIndex = -1;
			nextIndex = 0;
			size = 0;
			capacity = 4;
		}
		
		int stackSize(){
			return size;
		}
		
		bool isEmpty(){
			if(size==0){
				return true;
			}
			else{
				return false;
			}
		}
		
		void enqueue(int element){
			if(size==capacity){
				T *newdata = new T[2*capacity];
				int j=0;
				
				for(int i=firstIndex; i<capacity; i++){
					newdata[j] = data[i];
					j++;
				}
				for(int i=0; j<firstIndex; i++){
					newdata[j] = data[i];
					j++;
				}
				delete[] data;
				data = newdata;
				firstIndex=0;
				nextIndex=capacity;
				capacity = capacity*2;
			}
			data[nextIndex] = element;
			nextIndex = (nextIndex+1)%capacity;
			if(firstIndex==-1){
				firstIndex=0;
			}
			size++;
		}
		
		T dequeue(){
			if(isEmpty()){
				cout<<"Stack is Empty!";
				return 0;
			}
			T ans = data[firstIndex];
			firstIndex = (firstIndex+1)%capacity;
			size--;
			if(size==0){
				firstIndex=-1;
				nextIndex= 0;
			}
			return ans;
		}
		
		T front(){
			if(isEmpty()){
				cout<<"Stack is Empty!";
				return 0;
			}
			return data[firstIndex];
		}
};

int main(){
	Queue<int> q;
	
	q.enqueue(10);
	q.enqueue(20);
		q.enqueue(20);
			q.enqueue(20);
				q.enqueue(20);
	cout<<q.stackSize()<<endl;
	cout<<q.front()<<endl;
}
