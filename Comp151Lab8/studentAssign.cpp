/**	Lab 8.4
	@author: Pedro J. Navarrete
	@Version: v0.5 (doesn't work yet, don't upload to easel)
*/

#include <iostream>
using namespace std;

const int SIZE = 50;

// function prototypes
void sortArray(int[], int); // Selection Sort
int searchArray(int[], int, int); // Binary Search

int main() {
	int arraySize;
	cout << "Enter the number of elements:";
	cin >> arraySize;

	int studentsArray[SIZE];

	for (size_t i = 0; i < arraySize; i++){
		cout << "Enter element" << i + 1 << ": ";
		cin >> studentsArray[i];
	}

	sortArray(studentsArray, arraySize);

	cout << "Which element do you want to search?";

	int searchTarget;
	int searchReturn = searchArray(studentsArray, arraySize, searchTarget);
	if (searchReturn == -1) {
		cout << "The element wasn't found";
	} else {
		cout << "The element was found at position " << searchTarget + 1;
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
