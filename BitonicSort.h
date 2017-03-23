#define UP 0    /* UP define ascending sorting flag. */
#define DOWN 1  /* Down define descending sorting flag. */

/* ----- Function Declarations ----- */
void swap(int *, int *);
void BitonicSort(int , int , int * , int );
int BitonicAscendingSort(int * , int );
int BitonicDescendingSort(int * , int );

/* Global Variable */
static int ComplexityCount;


/************************************
Function to swap two integer values.
**/
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


/**********************************************************
Function represent C implementation of Bitonic Sort.
**/
void BitonicSort(int start, int length, int *seq, int flag)
{
	int i;
	int split_length;
    int complx_count = 0;

	if (length == 1)
		return;

	split_length = length / 2;

	for(i=start; i < start+split_length; i++)
	{
		if(flag == UP)
		{
			if (seq[i] > seq[i + split_length])
            {
				swap(&seq[i], &seq[i+split_length]);
            }
		}
		else
		{
			if (seq[i] < seq[i+split_length])
            {
				swap(&seq[i], &seq[i+split_length]);
            }
		}

        complx_count++;
	}

    complx_count++; // For recursive loop...
    ComplexityCount += complx_count;

	BitonicSort(start, split_length, seq, flag);
	BitonicSort(start + split_length, split_length, seq, flag);
}


/*********************************************
Wrapper function for ascending bitonic sort.
**/
int BitonicAscendingSort(int *nArray, int ArraySize)
{
    ComplexityCount = 0;
    BitonicSort(0, ArraySize, nArray, UP);
    return ComplexityCount;
}


/**********************************************
Wrapper function for descending bitonic sort.
**/
int BitonicDescendingSort(int *nArray, int ArraySize)
{
    ComplexityCount = 0;
    BitonicSort(0, ArraySize, nArray, DOWN);
    return ComplexityCount;
}
