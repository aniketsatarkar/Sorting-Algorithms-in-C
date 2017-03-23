/* ----- Function Declarations ----- */
void _MaxHeapify(int* nArray, int heapSize, int index, int *c_count);
void _HeapSort(int* nArray, int ArraySize, int *c_count);
int Partition(int* nArray, int left, int right, int *c_count);
void _QuickSortRecursive(int* nArray, int left, int right, int *c_count);
int IntroSort(int* , int );



/*************************************************************
Function to heapify collection, used internally in heap sort.
*/
void _MaxHeapify(int* nArray, int heapSize, int index, int *c_count)
{
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

    *c_count += 1;

	if (left < heapSize && nArray[left] > nArray[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && nArray[right] > nArray[largest])
		largest = right;

	if (largest != index)
	{
		int temp = nArray[index];
		nArray[index] = nArray[largest];
		nArray[largest] = temp;

		_MaxHeapify(nArray, heapSize, largest, c_count);
	}
}


/***********************************************************
function to sort an integer array nArray of size ArraySize
in ascending order.
*/
void _HeapSort(int* nArray, int ArraySize, int *c_count)
{
    int heapSize = ArraySize;
    static int i, p;

	for (p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(nArray, heapSize, p, c_count);

	for (i = ArraySize - 1; i > 0; --i)
	{
		int temp = nArray[i];
		nArray[i] = nArray[0];
		nArray[0] = temp;

		--heapSize;
		MaxHeapify(nArray, heapSize, 0, c_count);
	}
}



/**************************************************************
Function represent recursive variant of Quick Sort algorithm.
*/
void _QuickSortRecursive(int* nArray, int left, int right, int *c_count)
{
    *c_count += 1;

	if (left < right)
	{
		int q = Partition(nArray, left, right, c_count);
		_QuickSortRecursive(nArray, left, q - 1, c_count);
		_QuickSortRecursive(nArray, q + 1, right, c_count);
	}
}


/**************************************************************
Function so sort an integer array nArray of size ArraySize in
ascending order.
*/
int IntroSort(int* nArray, int ArraySize)
{
    int ComplexityCount = 0;
	int partitionSize = Partition(nArray, 0, ArraySize - 1, &ComplexityCount);

	if (partitionSize < 16)
	{
		_InsertionSort(nArray, ArraySize, &ComplexityCount);
	}
	else if (partitionSize >(2 * log(ArraySize)))
	{
		_HeapSort(nArray, ArraySize, &ComplexityCount);
	}
	else
	{
		_QuickSortRecursive(nArray, 0, ArraySize - 1, &ComplexityCount);
	}

    return ComplexityCount;
}
