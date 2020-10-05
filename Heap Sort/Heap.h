#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

template<typename T>
class Heap
{
public:
	//Default Constructor
	Heap<T>();
	//Constructor
	Heap<T>(T dataArr[], const int& dataSize, const char& type);
	//Destructor
	~Heap();

	void sort(); //Used to sort the heap either as a min or max heap based off the heapType variable

	template<typename T2>
	friend ostream& operator<<(ostream& ostrm, const Heap<T2>& heap); //Used to output the heap

private:
	T* data;
	int size = 0;
	char heapType = '\0';

	void heapifyMax(T arr[], const int& n, int i); //Heapifies the heap according to the heap property for a max heap
	void maxHeapSort(T arr[], int n); //Used to sort a max heap
	void heapifyMin(T arr[], const int& n, int i); //Heapifies the heap according to the heap property for a min heap
	void minHeapSort(T arr[], int n); //Used to sort a min heap
};

#endif