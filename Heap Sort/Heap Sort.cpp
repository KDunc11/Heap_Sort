/*
	Project: Chapter 9 Heap Sort
	By: Kyle Duncan
	Collaborated with Joe Bulanon and Jeff Fairbanks
*/

#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Heap.cpp"

using namespace std;

void openAndProcessFiles(const string& fileName, const int argc, char* argv[]);

int main(int argc, char* argv[])
{
	if (argc == 1 || argc > 5) //Incorrect number of arguments, either only the .exe was a argument or there were too many arguments
	{
		cout << "Incorrect number of arguments." << "\n" << endl;

		//Explains how user can fix their arguments
		cout << "Need to do to Project properties then Debugging and insert the following for the Command Line Arguments" << "\n" << "\n"
			<< "1) The.exe file path (for in cmd only)" << "\n"
			<< "2) The.sln file path" << "\n"
			<< "3) Character for selecting whether the Heap is sorted in ascending(\'a\' or \'A\') or descending order(\'d\' or \'D\')" << "\n"
			<< "4) Input file path" << "\n"
			<< "5) Output file path" << endl;

		cout << "Press enter to close the program." << endl;
		cin.ignore();
		return 1;
	}

	if (argc == 4) //Program is running with .exe, .sln, char, and input file
		openAndProcessFiles(argv[3], argc, argv);

	if (argc == 5) //Program is running with .exe, .sln, char, input file, and output file
		openAndProcessFiles(argv[3], argc, argv);

	cout << "Press enter to close the program." << endl;
	cin.ignore();
	return 0;
}

void openAndProcessFiles(const string& fileName, const int argc, char* argv[]) //Used to open and processs the input file
{
	fstream inFile;

	inFile.open(fileName); //Opens the file

	int* tempArr = new int[1000]; //Creates a temporary array to store the values read in from the input file
	int index = -1;
	int n = 0; //Stores the size of the array
	int num = 0;

	for (int i = 0; i < 1000; i++) //Initializes the data pointed at to NULL
		tempArr[i] = NULL;

	if (inFile.is_open()) //Proceeds if the file can be opened
	{
		while (!inFile.eof())
		{
			inFile >> num; //Reads in a number from the file into the num variable

			++index;
			tempArr[index] = num; //Store the number read in into the temporary array
		}

		inFile.close(); //Close the input file

		n = index;

		int* arr = new int[n - 1]; //Create a new array with the proper size

		for (int i = 0; i < n; i++) //Set the new array to be composed of all the read in numbers stored in the temporary array
		{
			arr[i] = tempArr[i];
			tempArr[i] = NULL; //Set the temporary array's data to NULL before the array is deleted
		}
		
		delete[] tempArr; //Deletes the temporary array

		Heap<int> heap(arr, n, *argv[2]); //Creates a heap using the input array, the array's size and the order the user specified to sort the heap

		if (argc == 4) //Output Heap to the console
		{
			if (*argv[2] == 'a' || *argv[2] == 'A') //User has specified to sort in ascending order
			{
				heap.sort(); //Sorts the heap
				cout << "Sorted Heap in Ascending order." << "\n" << endl;
				cout << heap; //Displays heap onto the console
			}
			else if (*argv[2] == 'd' || *argv[2] == 'D') //User has specified to sort in descending order
			{
				heap.sort(); //Sorts the heap
				cout << "Sorted Heap in Descending order." << "\n" << endl;
				cout << heap; //Displays the heap onto the console
			}
		}

		if (argc == 5) //Output Heap to the specified output file
		{
			ofstream outFile;

			outFile.open(argv[4]);

			if (outFile.is_open())
			{
				if (*argv[2] == 'a' || *argv[2] == 'A') //User has specified to sort in ascending order
				{
					heap.sort(); //Sorts the heap
					cout << "Sorted Heap in Ascending order and stored in output file." << "\n" << endl;
					outFile << heap; //Outputs heap to the output file
				}
				else if (*argv[2] == 'd' || *argv[2] == 'D') //User has specified to sort in descending order
				{
					heap.sort(); //Sorts the heap
					cout << "Sorted Heap in Descending order and stored in output file." << "\n" << endl;
					outFile << heap; //Outputs heap to the output file
				}
			}
			else
				cout << "Could not open output file." << endl;
			
			outFile.close(); //Close the output file
		}
	}

	else
		cout << "Could not open input file." << endl;
}