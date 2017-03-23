/* ------ Function Declarations ------*/
int QuickSortRecursive(int* , int );
void QuickSort_Recursive(int* , int , int , int *);


/**************************************************************
Function to sort an integer array nArray of size ArraySize in
ascending order.
*/
int QuickSortRecursive(int* nArray, int ArraySize)
{
    int ComplexityCount = 0;

    QuickSort_Recursive(nArray, 0, ArraySize - 1, &ComplexityCount);

    return ComplexityCount;
}


/**************************************************************
Function represent recursive variant of Quick Sort algorithm.
*/
void QuickSort_Recursive(int* nArray, int left, int right, int *c_count)
{
    *c_count += 1;

	if (left < right)
	{
		int q = Partition(nArray, left, right, c_count);
		QuickSort_Recursive(nArray, left, q - 1, c_count);
		QuickSort_Recursive(nArray, q + 1, right, c_count);
	}
}
