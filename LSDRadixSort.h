/*---- Function Declaration ----*/
int LSDRadixSort(int * , int );



/************************************************
Function to sort an array of integers to sort in
ascending order using LAD Radix Sort algorithm.
**/
int LSDRadixSort(int *nArray, int ArraySize)
{
    int min = 0, tempArr[ArraySize];
    int k, i, j, temp, t, n;
    int ComplexityCount = 0;

    for (i = 0; i < ArraySize; i++)
    {
        tempArr[i] = nArray[i];
    }

    for(k=0; k<3; k++)
    {
        ComplexityCount++;

        for(i=0; i<ArraySize; i++)
        {
            ComplexityCount++;

            /* To find minimum lsd */
            min = nArray[i] % 10;
            t = i;

            for(j=i+1; j<ArraySize; j++)
            {
                ComplexityCount++;

                if (min > (nArray[j]%10))
                {
                    min = nArray[j]%10;
                    t = j;
                }
            }

            Swap(&tempArr[t], &tempArr[i]);
            Swap(&nArray[t], &nArray[i]);

        }

        /*to find MSB */
        for (j=0; j<ArraySize; j++)
        {
            nArray[j] = nArray[j]/10;
            ComplexityCount++;
        }
    }

    for(i=0; i<ArraySize; i++)
        nArray[i] = tempArr[i];
}
