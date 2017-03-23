/* ----- Function Declarations ----- */
void FlipArray(int *, int , int , int *);
int PancakeSort(int *, int );


/**************************************************
Function to flip an integer array.
*/
void FlipArray(int *nArray, int ArraySize, int num, int *c_count)
{
    int swap;
    int i = 0;

    for(i=0; i< (--num); i++)
    {
        swap = nArray[i];
        nArray[i] = nArray[num];
        nArray[num] = swap;

        *c_count += 1;
    }
}


/********************************************************
Function to sort an array of integers in ascending order,
using pancake sort algorithm.
*/
int PancakeSort(int *nArray, int ArraySize)
{
    int i, a, max_num_pos;
    int ComplexityCount = 0;

    if(ArraySize < 2)
        return ComplexityCount;

    for(i=ArraySize; i > 1; i--)
    {
        max_num_pos = 0;

        for(a=0; a<i; a++)
        {
            if(nArray[a] > nArray[max_num_pos])
                max_num_pos = a;

            ComplexityCount++;
        }

        ComplexityCount++;

        if(max_num_pos == (i-1))
            continue;

        if(max_num_pos)
            FlipArray(nArray, ArraySize, (max_num_pos+1), &ComplexityCount);

        FlipArray(nArray, ArraySize, i, &ComplexityCount);
    }

    return ComplexityCount;
}
