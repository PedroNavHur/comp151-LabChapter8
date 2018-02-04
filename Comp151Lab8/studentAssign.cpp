/**	Lab 8.4
	@author: Pedro J. Navarrete
	@Version: v1.00
*/

#include <iostream>
using namespace std;

const int SIZE = 50;

// function prototypes
void getArray(int[], int&); // gets the Array from the user
void sortArray(int[], int); // Selection Sort
int searchArray(int[], int, int); // Binary Search

int main() {
	int studentsArray[SIZE];
	int arraySize;

	getArray(studentsArray, arraySize);
	sortArray(studentsArray, arraySize);

	int searchTarget;
	cout << "Which element do you want to search? ";
	cin >> searchTarget;
	

	int searchReturn = searchArray(studentsArray, arraySize, searchTarget);
	if (searchReturn == -1) {
		cout << "The element "<< searchTarget << " was not found. " << endl;
	} else {
		cout << "The element " << searchTarget << " was found at position " << searchReturn + 1 << ". " << endl;
	}
}

/********************************************************************
*	getArray														*
*	task: gets an array from the user								*
*	@param the array, the array size								*
********************************************************************/
void getArray(int array[], int& size) {
	cout << "Enter the number of elements [maximun of 50 elements]: ";
	cin >> size;

	while (size < 0 || size > 50) {
		cout << "Invalid number of elements";
		cout << "Please, Enter the number of elements [maximun of 50 elements]: ";
		cin >> size;
	}

	for (size_t i = 0; i < size; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> array[i];
	}

}

/********************************************************************
 *	sortArray														*
 *	task: sorts the Array from smallest to largest					*
 *	@param the array, the array size								*
 *******************************************************************/
void sortArray(int array[], int size) {
	int countPos;
	int minPos;
	int minVal;

	for (countPos = 0; countPos < (size - 1); countPos++) {
		minPos = countPos;
		minVal = array[countPos];
		for (size_t i = countPos +1; i < size; i++){
			if (array[i] < minVal) {
				minVal = array[i];
				minPos = i;
			}
		}

		array[minPos] = array[countPos];
		array[countPos] = minVal;
	}
}


/********************************************************************
*	searchArray														*
*	task: searches the target value in the array					*
*	@param the array, the array size, target						*
*	@return the index of the target value in the array				*
********************************************************************/
int searchArray(int array[], int size, int target) {
	int first = 0;				    // First element of list
	int last = size - 1;	    // last element of the list
	int middle;					   // variable containing the current 
								   // middle value of the list

	while (first <= last)
	{
		middle = first + (last - first) / 2;

		if (array[middle] == target)
			return middle;		       // if value is in the middle, we are done

		else if (array[middle]>target)
			last = middle - 1;		   // toss out the second remaining half of
									   // the array and search the first 
		else
			first = middle + 1;		   // toss out the first remaining half of
									   // the array and search the second
	}

	return -1;					   // indicates that value is not in the array
}
