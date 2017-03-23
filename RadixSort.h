/**********************************************************
Function to sort an integer array in ascending order using
radix sort.
*/
int RadixSort(int *nArray, int ArraySize)
{
	int *counts, *temp;
	int index, pval, i, j, n;
    int ComplexityCount = 0;

    /************************************************************
     * allocate memory to counts and temp int pointers
     * if memory allocation fails function will return.
     */
	if((counts = (int *)malloc(ArraySize * sizeof(int))) == NULL)
		return ComplexityCount;

	if((temp = (int *)malloc(ArraySize * sizeof(int))) == NULL)
		return ComplexityCount;

	for(n=0; n<ArraySize; n++)
	{
		for (i = 0; i < ArraySize; i++) counts[i] = 0;

		pval = (int)pow((double)ArraySize, (double)n);

		for (j = 0; j < ArraySize; j++)
		{
			index = (int)(nArray[j]/pval) % ArraySize;
			counts[index] = counts[index]+1;
            ComplexityCount++;
		}

		for (i = 1; i < ArraySize; i++)
        {
			counts[i] = counts[i] + counts[i - 1];
            ComplexityCount++;
        }

		for (j = ArraySize - 1; j >= 0; j--)
		{
			index = (int)(nArray[j]/pval) % ArraySize;
			temp[counts[index]-1] = nArray[j];
			counts[index] = counts[index]-1;
            ComplexityCount++;
		}

        /* copy temp sorted array into provided array */
		memcpy(nArray, temp, ArraySize *sizeof(int));
	}

	free(counts);
	free(temp);

    return ComplexityCount;
}
