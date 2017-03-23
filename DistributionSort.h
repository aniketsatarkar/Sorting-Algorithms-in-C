/*---- function Declaration ----*/
int DistributionSort(int * , int );

int DistributionSort(int *nArray, int arrSize)
{
    int i, j;
    int count[arrSize];
    int ComplexityCount = 0;

    /* assign 0 to all elements of count array. */
    for(i=0; i<arrSize; i++) count[i] = 0;

    for(i=0; i<arrSize; i++) (count[nArray[i]])++;

    /* sort array using comparison */
    for(i=0, j=0; i<arrSize; i++)
    {
        for(; count[i] > 0; count[i]--)
        {
            nArray[j++] = i;
            ComplexityCount++;
        }
        ComplexityCount++;
    }

    return ComplexityCount++;
}
