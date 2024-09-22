#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct minHeap{
	vector<T> heap;

	int parent(int i){
		return (i-1)>>1;
	}

	int left(int i){
		return (i<<1)+1;
	}

	int right(int i){
		return (i<<1)+2;
	}

	void swap(T& x, T& y){
		T temp = x;
        x = y;
        y = temp;
	}

	void heapify(int i=0) {

        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }

        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    minHeap() = default;

    bool empty(){
    	return heap.empty();
    }
    void build_min_heap(vector<T>& elements) {
        heap = elements;
        int n = heap.size();
        for (int i = parent(n - 1); i >= 0; --i) {
            heapify(i);
        }
    }

    T get_min(){
    	if(heap.empty()) return INT_MIN;
    	return heap[0];
    }

    T pop(){
    	if(heap.empty()) return INT_MIN;
    	T res = heap[0];
    	heap[0] = heap[heap.size()-1];
    	heap.pop_back();
    	heapify();
    	return res;
    }

    void insert(T val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void display(){
    	if(heap.empty()) return;
    	for(auto i : heap){
    		cout << i << " ";
    	}
    	cout << endl;
    }
};

int main(){
	//input for my minHeap:
	vector<int> x = {8,7,6,5,4,3,2,1,0}; 

	//creating the minHeap:
	minHeap<int> newMinHeap;
	newMinHeap.build_min_heap(x);

	//displaying the minHeap:
	newMinHeap.display();
	//output: 0 1 2 5 4 3 6 7 8 

	//creating a new integer vector and inserting elements after popping them out:
	vector<int> op;
	while(!newMinHeap.empty()){
		op.push_back(newMinHeap.pop());
	}

	for(int k : op) cout << k << " ";
	cout << endl;

	//output: 0 1 2 3 4 5 6 7 8 

	//The vector "op" is now sorted using the Heap-Sort Algorithm.
}
/*
1. Implement a min heap data structure. For the parent and left/right functions use bit manipulation operators. In addition your heap should have the following functionality

DONE: The ability to initially build the heap (build_min_heap)
DONE: The ability to heapify
DONE: The ability to get and remove ("pop") the root node from the heap (and of course re-heapify everything)
DONE: The heap should be generic to the type of data (can store floats, int, custom datastructure)
Show example(s) of your heap working. Please demonstrate ALL the functionality you implemented.
Upload your source code to github along with your example(s).
*/