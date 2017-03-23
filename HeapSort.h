/* ----- Function Declarations  ----- */
int HeapSort(int * , int );
void MaxHeapify(int * , int , int , int * );


/***********************************************************
function to sort an integer array nArray of size ArraySize
in ascending order.
*/
int HeapSort(int* nArray, int ArraySize)
{
    int heapSize = ArraySize;
    static int i, p;
    int ComplexityCount = 0;

	for (p = (heapSize - 1) / 2; p >= 0; --p)
	{
		MaxHeapify(nArray, heapSize, p, &ComplexityCount);
	}

	for (i = ArraySize - 1; i > 0; --i)
	{
		int temp = nArray[i];
		nArray[i] = nArray[0];
		nArray[0] = temp;

		--heapSize;
		MaxHeapify(nArray, heapSize, 0, &ComplexityCount);
	}

    return ComplexityCount;
}


/*************************************************************
Function to heapify collection, used internally in heap sort.
*/
void MaxHeapify(int* nArray, int heapSize, int index, int *c_count)
{
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

    *c_count+=1;

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

		MaxHeapify(nArray, heapSize, largest, c_count);
	}
}
