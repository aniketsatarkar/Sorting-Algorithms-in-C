/* ----- function declarations ----- */
int IsSorted(int *, int, int *);
void Shuffle(int *, int);
int ShuffleSort(int *, int);


/************************************************
function to check if the array is sorted or not.
 */
int IsSorted(int *nArrPtr, int ArraySize, int *c_count)
{
	while ((--ArraySize) >= 1)
	{
        *c_count += 1;
		if (nArrPtr[ArraySize] < nArrPtr[ArraySize - 1]) return 0;
	}

	return 1;
}


/****************************************
Function to shuffle array elements
*/
void Shuffle(int *nArrPtr, int ArraySize)
{
	int i, temp1, temp2;

	for (i=0; i<ArraySize; i++)
	{
		temp1 = nArrPtr[i];
		temp2 = rand() % ArraySize;
		nArrPtr[i] = nArrPtr[temp2];
		nArrPtr[temp2] = temp1;
	}

}


/***********************************************************************
Function to check if the array is sorted or not and if not sorted calls
the shuffle function to shuffle the array elements.
*/
int ShuffleSort(int *nArrPtr, int ArraySize)
{
    int ComplexityCount = 0;

	while (!IsSorted(nArrPtr, ArraySize, &ComplexityCount))
	{
		Shuffle(nArrPtr, ArraySize);
        ComplexityCount++;
	}

    return ComplexityCount;
}

