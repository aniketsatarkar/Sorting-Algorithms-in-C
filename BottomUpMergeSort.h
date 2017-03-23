#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define min(A, B) (A < B) ? A : B


/* ----- Function Declarations ----- */
void bu_merge(int * , int , int , int );
void bu_mergesort(int * , int , int );
int BottomUpMergeSort(int * , int );

/* temporary array */
int *tempArr;
static int ComplexityCount;

/*********************************************************
function to bu_merge array elements.
**/
void bu_merge(int *nArray, int Start, int End, int ArraySize)
{
    int i, j, k;

    for(i=End+1; i>Start; i--)
    {
        tempArr[i-1] = nArray[i-1];
    }

    for(j=End; j<ArraySize; j++)
    {
        tempArr[ArraySize+End-j] = nArray[j+1];
    }

    for(k=Start; k<=ArraySize; k++)
    {
        if (less(tempArr[j], tempArr[i]))
            nArray[k] = tempArr[j--];
        else
            nArray[k] = tempArr[i++];

        ComplexityCount++;
    }

    ComplexityCount++;
}


/***************************************************
function to sort an integer array in Bottom-Up
bu_merge sort algorithm.
**/
void bu_mergesort(int *nArray, int Index, int ArraySize)
{
    int i, m;

    for (m = 1; m <= ArraySize-Index; m = m+m)
    {
        for (i = Index; i <= ArraySize-m; i += m+m)
        {
            bu_merge(nArray, i, i+m-1, min(i+m+m-1, ArraySize));
        }
    }
}


/*****************************************
Wrapper function to sort an integer array
using Bottom-Up bu_merge sort.
**/
int BottomUpMergeSort(int *nArray, int ArraySize)
{
    ComplexityCount = 0;

    /* allocate memory to tempArr */
    tempArr = malloc(ArraySize * sizeof(int));

    /* calling sorting function. */
    bu_mergesort(nArray, 0, ArraySize-1);

    /* free memory from tempArr */
    free(tempArr);

    return ComplexityCount;
}
