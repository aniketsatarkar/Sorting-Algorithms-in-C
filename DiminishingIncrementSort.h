/* ---- Function Declarations ---- */
int DiminishingIncrementSort(int * , int );

/***************************************************
Function to sort an array of integers in ascending
order diminishing increment sort.
*/
int DiminishingIncrementSort(int *nArray, int ArraySize)
{
    int i, j, k;
    int ComplexityCount = 0;

    for(i=ArraySize/2; i>0; i/=2)
    {
        for(j=i; j<ArraySize; j++)
        {
            for(k=j-i; k>=0; k-=i)
            {
                if(nArray[k+i] >= nArray[k])
                    break;
                else
                {
                    Swap(&nArray[k], &nArray[k+1]);
                }

                ComplexityCount++;
            }
            ComplexityCount++;
        }
        ComplexityCount++;
    }

    return ComplexityCount++;
}
