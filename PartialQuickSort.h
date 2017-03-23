/*---- Function Declarations ----*/
int LT(int , int );
int GT(int , int );
int PartialQuickerSort(int * , int );
void partial_quickersort(int * , int , int , int *);


/****************************************
Function to find if x is greater than y
if so, return 1 otherwise 0.
*/
int LT(int x, int y)
{
    if(x < y)
        return 1;
    else
        return 0;
}


/****************************************
Function to find if x is greater than y
if so, return 1 otherwise 0.
*/
int GT(int x, int y)
{
    if(x > y)
        return 1;
    else
        return 0;
}


/****************************************
Wrapper function for partial_quicksort().
Initially pass lower bound as 0, and
upper bound as length of an array.
*/
int PartialQuickerSort(int *nArray, int ArraySize)
{
    int ComplexityCount = 0;

    partial_quickersort(nArray, 0, ArraySize, &ComplexityCount);

    return ComplexityCount;
}


/***********************************************************
Function to sort an integer array in ascending order using
partial quick sort algorithm.

NOTE : nArray[Upper+1] holds the maximum possible key, with
a cutoff value of cut_off, which is initially set to zero.
change in the cutoff value may cause while() loop to progress
infinitely.
*/
void partial_quickersort(int *nArray, int Lower, int Upper, int *c_count)
{
    int	i, j;
    int	temp, pivot;
    int cut_off = 0; /* SEE THE NOTE ABOVE */

    if (Upper-Lower > cut_off)
    {
        Swap(&nArray[Lower], &nArray[(Upper+Lower)/2]);

        i = Lower;
        j = Upper + 1;
        pivot = nArray[Lower];

        while(1)
        {
            do i++; while(LT(nArray[i], pivot));
            do j--; while(GT(nArray[j], pivot));

            *c_count += 1;

            if (j<i) break;

            Swap(&nArray[i], &nArray[j]);
        }

        Swap(&nArray[Lower], &nArray[j]);

        partial_quickersort(nArray, Lower, j - 1, c_count);
        partial_quickersort(nArray, i, Upper, c_count);
    }
}


/************************************************************
void  PartialQuickerSort(int *nArray, int ArraySize)
{
    int	i, j;
    int	temp, pivot;
    int cut_off = 0;

    Lower = 0;
    Upper = ArraySize;

    if (Upper-Lower > cut_off)
    {
        Swap(&nArray[Lower], &nArray[(Upper+Lower)/2]);

        i = Lower;
        j = Upper + 1;
        pivot = nArray[Lower];

        while(1)
        {
            do i++; while(LT(nArray[i], pivot));
            do j--; while(GT(nArray[j], pivot));

            if (j<i) break;

            Swap(&nArray[i], &nArray[j]);
        }

        Swap(&nArray[Lower], &nArray[j]);

        PartialQuickerSort(nArray, Lower, j - 1);
        PartialQuickerSort(nArray, i, Upper);
    }
}
*************************************************************/
