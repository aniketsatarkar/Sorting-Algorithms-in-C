/*----- Function Declarations -----*/
int BubbleSort(int * , int );


/******************************************
Function to sort an array of integers in
ascending sort using Bubble sort. Return
Complexity of sorting.
*******************************************/
int BubbleSort(int *nArray, int ArraySize)
{
	int i, j;
    int ComplexityCount = 0;

	for(i=0; i<ArraySize; i++)
	{
		for(j=0; j<ArraySize; j++)
		{
			if(nArray[i]<nArray[j])
			{
                Swap(&nArray[i], &nArray[j]);
			}
            ComplexityCount++;
		}
        ComplexityCount++;
	}

    return ComplexityCount++;
}
