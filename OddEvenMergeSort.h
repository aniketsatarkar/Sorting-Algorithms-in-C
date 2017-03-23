/* ------ Function Declarations ------ */
void Compare(int nArray[], int i, int j);
void OddEvenMerge(int nArray[], int nPosition, int nLength, int nDistance, int *);
void OddEvenMerge_Sort(int nArray[], int nPosition, int nLength, int *);
int OddEvenMergeSort(int * , int );

// function to swap two array elements ----
void arr_Swap(int nArray[], int i, int j)
{
    int t = nArray[i];
    nArray[i] = nArray[j];
    nArray[j] = t;
}

// function to compare two elements ----
void Compare(int nArray[], int i, int j)
{
    if (nArray[i] > nArray[j]) arr_Swap(nArray, i, j);
}

/*************************************************************************
 * nPosition is the starting position and
 * nLength is the length of the piece to be merged,
 * nDistance is the distance of the elements to be compared
 */
void OddEvenMerge(int nArray[], int nPosition, int nLength, int nDistance, int *c_count)
{
    int m = nDistance * 2;
    int i = 0;

    *c_count += 1;

    if (m < nLength)
    {
        /*even subsequence */
        OddEvenMerge(nArray, nPosition, nLength, m, c_count);

        /* odd subsequence */
        OddEvenMerge(nArray, nPosition + nDistance, nLength, m, c_count);

        for(i = nPosition+nDistance; (i+nDistance)<(nPosition+nLength); i += m)
        {
            Compare(nArray, i, i+nDistance);
            *c_count += 1;
        }
    }
    else
    {
        Compare(nArray, nPosition, nPosition + nDistance);
    }
}


/***************************************************************
Function to sort a piece of length of the
array starting at a position nPosition
*/
void OddEvenMerge_Sort(int nArray[], int nPosition, int nLength, int *c_count)
{
    *c_count += 1;

    if (nLength > 1)
    {
        int m = nLength/2;

        OddEvenMerge_Sort(nArray, nPosition, m, c_count);
        OddEvenMerge_Sort(nArray, nPosition + m, m, c_count);
        OddEvenMerge(nArray, nPosition, nLength, 1, c_count);
    }
}


int OddEvenMergeSort(int *nArray, int ArraySize)
{
    int ComplexityCount = 0;

    OddEvenMerge_Sort(nArray, 0, ArraySize, &ComplexityCount);

    return ComplexityCount;
}

