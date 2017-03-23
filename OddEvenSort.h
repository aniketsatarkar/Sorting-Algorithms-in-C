/* ----- Function Declarations ----- */
int OddEvenSort(int * , int );

/****************************************************
 * NOTE: this algorithm can only have maximum value *
 * less than or equal to the length of the array.   *
 ****************************************************/


/**********************************************
Function to sort an integer array in ascending
order using odd-even sorting algorithm.
*/
int OddEvenSort(int *nArrya, int ArraySize)
{
    int sort = 0, i;
    int ComplexityCount = 0;

    while(!sort)
    {
        sort = 1;

        for(i=1; i<ArraySize; i+=2)
        {
            if(nArrya[i] > nArrya[i+1])
            {
                Swap(&nArrya[i], &nArrya[i+1]);
                sort = 0;
            }

            ComplexityCount++;
        }

        for(i=0; i<ArraySize-1; i += 2)
        {
            if(nArrya[i] > nArrya[i+1])
            {
                Swap(&nArrya[i], &nArrya[i+1]);
                sort = 0;
            }
            ComplexityCount++;
        }

        ComplexityCount++;
    }

    return ComplexityCount;
}
