/*----- Function Declarations  -----*/
int CircleSortInner(int *, int *);
int CircleSort(int *, int );

/* Global Variable */
static int ComplexityCount;


/*****************************************
Implementation of circle sort in C.
function represent circle sort algorithm,
internally called by CircleSort().
*/
int CircleSortInner(int *start, int *end)
{
	int *p, *q, t, swapped;

	if (start == end) return 0;

	// funny "||" on next line is for the center element of odd-lengthed array
	for (swapped=0, p=start, q=end; p<q || (p==q && ++q); p++, q--)
    {
		if (*p > *q)
        {
			t = *p, *p = *q, *q = t, swapped = 1;
        }
        ComplexityCount++;
    }

    ComplexityCount++;

	// q == p-1 at this point
	return swapped | CircleSortInner(start, q) | CircleSortInner(p, end);
}


/***********************************************************
Function to sort an integer array in ascending order
using circle sort algorithm.
NOTE : CircleSort() simply call CircleSortInner() function
until array is sorted.
*/
int CircleSort(int *nArray, int ArraySize)
{
    ComplexityCount = 0;

    /* recursively call function until array is sorted */
    while(CircleSortInner(nArray, nArray + (ArraySize-1)));

    return ComplexityCount;
}

