/* ----- function declarations ----- */
int MonkeySort(int *, int);


/***********************************************************************
    Code to check if the array is sorted or not and if not sorted calls
    the shuffle function to shuffle the array elements
*/
int MonkeySort(int *nArrPtr, int ArraySize)
{
    int ComplexityCount = 0;

	while (!is_sorted(nArrPtr, ArraySize, &ComplexityCount))
	{
		shuffle(nArrPtr, ArraySize);
        ComplexityCount++;
	}

    return ComplexityCount;
}
