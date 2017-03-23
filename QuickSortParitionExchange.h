/*----- Function Declarations -----*/
void QuickSortPE(int * , int , int * );
int QuickSortParititionExchange(int * , int );


/********************************************************
function for sorting an integer array in ascending order
using Quick Sort (Partition Exchange).
*/
void QuickSortPE(int *nArray, int ArraySize, int *c_count)
{
    int i, j, temp, patrition;

    *c_count += 1;

    if (ArraySize < 2)
        return;

    patrition = nArray[ArraySize/2];

    for(i=0, j=ArraySize-1; ; i++, j--)
    {
        while(nArray[i] < patrition)
            i++;

        while (patrition < nArray[j])
            j--;

        if (i >= j)
            break;

        temp = nArray[i];
        nArray[i] = nArray[j];
        nArray[j] = temp;

        *c_count += 1;
    }

    QuickSortPE(nArray, i, c_count);
    QuickSortPE(nArray+i, ArraySize-i, c_count);
}


int QuickSortParititionExchange(int *nArray, int ArrayLength)
{
    int ComplexityCount = 0;

    QuickSortPE(nArray, ArrayLength, &ComplexityCount);

    return ComplexityCount;
}
