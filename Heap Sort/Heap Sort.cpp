// Heap Sort
// Parker Padgett
// 9/19/23

#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
	int largest = i;
	int lChild = 2 * i + 1;
	int rChild = 2 * i + 2;

	// if left child is larger than root
	if (lChild < n && arr[lChild] > arr[largest])
		largest = lChild;

	// if right child is larger than root
	if (rChild < n && arr[rChild] > arr[largest])
		largest = rChild;

	// if largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		maxHeapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);

		maxHeapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 3, 2, 1, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Array: ";
	printArray(arr, n);
	cout << endl;

	cout << "Max Heapified Array: ";
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);
	printArray(arr, n);
	cout << endl;

	cout << "Sorted Array: ";
	heapSort(arr, n);
	printArray(arr, n);

	return 0;
}