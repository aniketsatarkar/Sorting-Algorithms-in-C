/*---- Function Declaration ----*/
int InsertionSort(int* , int );


/***************************************************
function to sort an integer array nArray of length
ArraysSize in ascending order.
*/
int InsertionSort(int* nArray, int ArraySize)
{
    int i = 0;
    int ComplexityCount = 0;

	for (i = 1; i < ArraySize; ++i)
	{
		int j = i;
		while (j > 0)
		{
            ComplexityCount++;

			if (nArray[j - 1] > nArray[j])
			{
				nArray[j - 1] ^= nArray[j];
				nArray[j] ^= nArray[j - 1];
				nArray[j - 1] ^= nArray[j];

				--j;
			}
			else
				break;
		}

        ComplexityCount++;
	}

    return ComplexityCount;
}
