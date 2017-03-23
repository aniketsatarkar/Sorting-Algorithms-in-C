/***************************************************
function to sort an array of integers in ascending
order using selection sort.
*/
int SelectionSort(int *nArray, int ArraySize)
{
    int i,j,index, temp;
    int ComplexityCount = 0;

    for(i=0; i<ArraySize-1; i++)
    {
        index = i;

        for(j=i+1; j<ArraySize; j++)
        {
            if(nArray[index] > nArray[j])
                index = j;
            ComplexityCount++;
        }

        if(index != i)
        {
            temp = nArray[i];
            nArray[i] = nArray[index];
            nArray[index] = temp;
        }

        ComplexityCount++;
    }

    return ComplexityCount;
}
