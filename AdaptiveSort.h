int AdaptiveSort(int * , int );


/*************************************************
function to sort an integer array using
adaptive or straight insertion sorting algorithm
*/
int AdaptiveSort(int *nArray, int ArraySize)
{
    int i,j,t;
    int ComplexityCount = 0;

    for(j=1; j<ArraySize; j++)
    {
        t = nArray[j];
        i = j;

        while(i > 0 && nArray[i-1] > t)
        {
            nArray[i] = nArray[i-1];
            i--;
            ComplexityCount++;
        }

        nArray[i] = t;
        ComplexityCount++;
    }

    return ComplexityCount;
}
