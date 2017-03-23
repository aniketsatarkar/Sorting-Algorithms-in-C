/* ----- Function Declarations ----- */
int PiagonholeSort(int * , int );
void pigonhole_sort(int , int , int * , int * );


/*****************************************************************
Function to sort an array of integers in ascending order,
using Pigonhole sorting algorithm.
NOTE : This method is a wrapper of pigonhole_sort() function.
this function used to calculate minimum and maximum values from
array and pass forward to pigonhole_sort() function to
sort an array.
*/
int PiagonholeSort(int *nArray, int ArraySize)
{
    int i, min, max;
    int ComplexityCount = 0;

    min = nArray[0];
    max = nArray[0];

    for(i=1; i<ArraySize; i++)
    {
        if(nArray[i] < min)
            min = nArray[i];

        if(nArray[i] > max)
            max = nArray[i];
    }

    pigonhole_sort(min, max, nArray, &ComplexityCount);

    return ComplexityCount;
}

/********************************************************
Function to sort an integer array, provided minimum and
maximum values in array.
NOTE : Do not use this function directly for sorting
instead use the PiagonholeSort() which will find out
minimum and maximum values from array on your behalf.
*/
void pigonhole_sort(int Minimun, int Maimum, int *nArray, int *c_count)
{
    int size, count = 0, i;

    int *current;
    current = nArray;

    size = Maimum - Minimun + 1;

    int holes[size];

    for(i=0; i<size; i++)
    {
        holes[i] = 0;
        *c_count += 1;
    }

    for(i=0; i < size; i++, current++)
    {
        holes[*current-Minimun] += 1;
        *c_count += 1;
    }

    for(count=0, current = &nArray[0]; count < size; count++)
    {
        while((holes[count]--) > 0)
        {
            *current++ = count + Minimun;
            *c_count += 1;
        }
        *c_count += 1;
    }
}
