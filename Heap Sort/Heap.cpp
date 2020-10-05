#include "Heap.h"

//Default Constructor
template<typename T>
Heap<T>::Heap()
{
	//Used to initalize all data
	data = nullptr;
	size = 0;
	heapType = '\0';
}

//Constructor
template<typename T>
Heap<T>::Heap(T dataArr[], const int& dataSize, const char& type)
{
	data = new T[dataSize]; //Creates an array to implement the heap based of the size of the data passed in
	data = dataArr; //Sets the heap's data equal to the input data
	size = dataSize;
	heapType = type; //Sets the type of heap (min or max) according to the user's choice
}

template<typename T>
//Destructor
Heap<T>::~Heap()
{
}

//Public Member Functions
template<typename T>
void Heap<T>::sort() //Sorts the heap
{
	if (data != nullptr) //If the heap isn't empty
	{
		if (heapType == 'a' || heapType == 'A') //User specifies max heap (ascending order)
			maxHeapSort(this->data, this->size);

		else if (heapType == 'd' || heapType == 'D') //User specifies min heap (descending order)
			minHeapSort(this->data, this->size);
	}
	else
		cout << "The heap is empty" << endl;
}

template<typename T2>
ostream& operator<< (ostream& ostrm, const Heap<T2>& heap) //Used for outputting the heap
{
	for (int i = 0; i < heap.size; i++) //Outputs the heap's data to the specified output stream
		ostrm << heap.data[i] << " ";
	
	return ostrm;
}

//Private Member Functions
template<typename T>
void Heap<T>::heapifyMax(T arr[], const int& n, int i) //Recursive function to heapify a max heap
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2 * i + 1 
	int r = 2 * i + 2; // right = 2 * i + 2 
 
	if (l < n && arr[l] > arr[largest]) //If left child is larger than root
		largest = l;

	if (r < n && arr[r] > arr[largest]) //If right child is larger than largest so far
		largest = r;

	if (largest != i) //If largest is not the root
	{
		swap(arr[i], arr[largest]); //Swaps the largest index with the current index
 
		heapifyMax(arr, n, largest); //Recursively heapifies the affected sub-tree
	}
}

template<typename T>
void Heap<T>::maxHeapSort(T arr[], int n) //Used to sort a max heap
{ 
	for (int i = n / 2 - 1; i >= 0; i--) //Build heap (rearranges the array)
		heapifyMax(arr, n, i);

	for (int i = n - 1; i >= 0; i--) //One by one extract an element from heap 
	{
		swap(arr[0], arr[i]); //Move current root to the end
		heapifyMax(arr, i, 0); //Call max heapify recursive function on the reduced heap 
	}
}


template<typename T>
void Heap<T>::heapifyMin(T arr[], const int& n, int i) //Recursive Function to heapify a min heap
{
	int smallest = i; // Initialize smallest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 
 
	if (l < n && arr[l] < arr[smallest]) //If left child is smaller than the root
		smallest = l;
 
	if (r < n && arr[r] < arr[smallest]) // If right child is smaller than smallest so far
		smallest = r;
 
	if (smallest != i) //If the smallest is not root
	{
		swap(arr[i], arr[smallest]); //Swaps the smallest index with the current index
		heapifyMin(arr, n, smallest); //Recursively heapifies the affected sub-tree 
	}
}

template<typename T>
void Heap<T>::minHeapSort(T arr[], int n) //Used to sort a min heap
{ 
	for (int i = n / 2 - 1; i >= 0; i--) //Build heap (rearranges the array)
		heapifyMin(arr, n, i);

	for (int i = n - 1; i >= 0; i--) //One by one extract an element from heap
	{
		swap(arr[0], arr[i]); //Move current root to the end  
		heapifyMin(arr, i, 0); //Call min heapify recursive function on the reduced heap
	}
}