#include <stdio.h>
#include <tchar.h>
//
// 자구알 2 
// 141020 김영하

class Node
{
public:
	Node* leftChild;
	Node* rightChild;
};

// Homework #1. P1
// Counts the number of internal nodes in a binary tree
// an internal node is a node with at least one child
int GetInternalCount(Node* node)
{
	if (node == nullptr) return 0;

	// base case, no children returns 0 
	if (node->leftChild == nullptr 
		&& node->rightChild == nullptr)
		return 0;
	else
		return 1 
			+ GetInternalCount(node->leftChild) 
			+ GetInternalCount(node->rightChild);
}


// Homework #1.P2
// Sorts the array assuming
// the entire array is sorted ascending except for the last element
void SortAscendingSortedArray(int* array, size_t size)
{
	if (!array) return;
	if (size < 2) return;

	// start from end of array
	for (size_t i = size - 1; i> 0; --i)
	{
		// swap if current element is smaller than previous element
		if (array[i] < array[i - 1])
		{
			int tempValue = array[i];
			*(array + i) = array[i - 1];
			*(array + i - 1) = tempValue;
		}
	}
}


// Homework #1. C1
// Insertion sort 
// 1. Print Func
// 2. Insertion sort algorithm
void PrintArray(int* array, size_t length)
{
	printf("\n Array:[");
	if (array != nullptr)
	{
		for (size_t i = 0; i < length; ++i)
		{
			printf("%d\t", array[i]);
		}
	}
	printf("]\n");
}

void InsertionSort(int* array, size_t length)
{
	PrintArray(array, length);

	if (length <= 1) return;
	if (array == nullptr) return;

	// start from card 2
	for (size_t currentIndex = 1; currentIndex < length; ++currentIndex)
	{
		int valueToInsert = array[currentIndex];

		// find insertion point
		for (int comparisonIndex = currentIndex - 1; comparisonIndex >= 0; --comparisonIndex)
		{
			// iterate until value is smaller than valueAtCurrentIndex
			// if none discovered, insert at front
			int valueAtComparisonIndex = array[comparisonIndex];

			// since all values in front are sorted, we only need to find a value smaller than current
			if (valueAtComparisonIndex > valueToInsert)  // not insertion point, value is larger, so push back
			{
				array[comparisonIndex + 1] = valueAtComparisonIndex;
				array[comparisonIndex] = valueToInsert;
			}
			else  // found the insertion point!
			{
				break;
			}
		}
	}

	printf("After sort:");
	PrintArray(array, length);

}



// Homework #1. P3
// Insertion Sort Test Case
void InsertionSortTest()
{
	int *arrayElementCountPerspective0 = nullptr;
	int arrayElementCountPerspective1[1] = { 1 };
	int arrayElementCountPerspectiveN[5] = { 2,4,6,1,3 };

	InsertionSort(arrayElementCountPerspective0, 0);
	InsertionSort(arrayElementCountPerspective1, 1);
	InsertionSort(arrayElementCountPerspectiveN, 5);

	int arrayInputPerspective_Sorted[5] = { 1, 2, 3, 4, 5 };
	int arrayInputPerspective_RevSorted[5] = { 5,4,3,2,1 };
	int arrayInputPerspective_Random[5] = { 2,4,8,3,5 };

	InsertionSort(arrayInputPerspective_Sorted, 5);
	InsertionSort(arrayInputPerspective_RevSorted, 5);
	InsertionSort(arrayInputPerspective_Random, 5);

}

int _tmain(int argc, _TCHAR* argv[])
{
	InsertionSortTest();
	getchar();


	return 0;
}

