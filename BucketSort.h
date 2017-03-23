/*---- function Declaration ----*/
int BucketSort(int * , int );


/********************************************************************
* following function represent an algorithm for bucket sort.
* NOTE : This algorithm will only work for an array containing
*        values less than the size of that array.
* for example : if an array of 10 elements contain a value 12,
* algorithm will not work, array can only have values less than 10.
*********************************************************************/

int BucketSort(int *nArray, int arrSize)
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
