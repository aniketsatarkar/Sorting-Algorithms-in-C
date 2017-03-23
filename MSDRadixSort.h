/*---- Function Declaration ----*/
int RadixSortMSD(int * , int );


/*****************************************************
Function to sort an integer array in ascending order,
using Radix MSD sort algorithm.
*/
int RadixSortMSD(int *nArray, int ArraySize)
{
    int i, maxVal=0, digitPosition=1;
    int bucket[ArraySize];
    int ComplexityCount = 0;

    /* finding maximum value from array */
	for(i=0; i<ArraySize; i++)
    {
        if(nArray[i] > maxVal)
            maxVal = nArray[i];
    }

	int pass = 1;

	while((maxVal/digitPosition) > 0)
    {
		int digitCount[10] = {0};

		for(i=0; i<ArraySize; i++)
        {
			digitCount[nArray[i]/digitPosition%10]++;
            ComplexityCount++;
        }

		for(i=1; i<10; i++)
        {
            digitCount[i] += digitCount[i-1];
            ComplexityCount++;
        }

		for(i=ArraySize-1; i>=0; i--)
        {
            bucket[--digitCount[nArray[i]/digitPosition%10]] = nArray[i];
            ComplexityCount++;
        }

		for(i=0; i<ArraySize; i++)
        {
            nArray[i] = bucket[i];
            ComplexityCount++;
        }

		pass++;
		digitPosition *= 10;

        ComplexityCount++;
	}

    return ComplexityCount;
 }
