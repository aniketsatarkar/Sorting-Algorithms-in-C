/*---- Function Declaration ----*/
int CountingSort(int *nArray, int ArraySize);


/*****************************************************
Function to sort an integer array in ascending order
using counting sort algorithm.
*/
int CountingSort(int *nArray, int ArraySize)
{
	int i, j, k;
	int min, max;
	int index = 0;
    int ComplexityCount = 0;

	min = max = nArray[0];

	for(i = 1; i < ArraySize; i++)
    {
		min = (nArray[i] < min) ? nArray[i] : min;
		max = (nArray[i] > max) ? nArray[i] : max;
	}

	k = max - min + 1;

	/* creates k buckets */
	int B[k];

	for(i = 0; i < k; i++)
        B[i] = 0;

	for(i = 0; i < ArraySize; i++)
    {
        B[nArray[i] - min]++;
        ComplexityCount++;
    }

	for(i = min; i <= max; i++)
    {
        for(j = 0; j < B[i - min]; j++)
        {
            nArray[index++] = i;
            ComplexityCount++;
        }
        ComplexityCount++;
    }

    return ComplexityCount;
}
