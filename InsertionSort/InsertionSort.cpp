// InsertionSort

#include "pch.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>  
#include<fstream>
#include<iomanip>
using namespace std;

void InsertionSort(int array[], int start, int end);
void RandomArray(int array[], int size);
void printCSV(int array[], int size);

int main()
{
	int arr[100000];
	RandomArray(arr, 100000);
	int e= 100000;
	clock_t start, end;
	start = clock();
	InsertionSort(arr, 0, 100000);
	end = clock();
	// Calculating total time taken by the program. 
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	printCSV(arr, e);
}

void InsertionSort(int array[], int start, int end) {
	for (int j = start + 1; j < end; j++) {
		int key = array[j];
		int i = j - 1;
		while (i > -1 && array[i] > key)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}
void RandomArray(int array[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		array[i]=rand() % size + 1 ;
	}
}
void printCSV(int array[],int size) {
	ofstream out;
	// opens an existing csv file or creates a new file.
	out.open("insertionSort.csv", ios::out | ios::app);
	for (int i = 0; i < size; i++) {
		out << array[i] << endl;
	}
}