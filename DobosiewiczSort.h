/* ----- Function Declarations ----- */
int DobosiewiczSort(int * , int );

int DobosiewiczSort(int *nArray, int ArraySize)
{
    int gap = ArraySize;
    int temp, i;
    int ComplexityCount = 0;

    for(;;)
    {
        gap = NewGap(gap);
        int swapped = 0;

        for(i=0; i<ArraySize-gap; i++)
        {
            int j = i + gap;

            if(nArray[i] > nArray[j])
            {
                temp = nArray[i];
                nArray[i] = nArray[j];
                nArray[j] = temp;

                swapped = 1;
            }

            ComplexityCount++;
        }

        ComplexityCount++;

        /* break out of infinite loop */
        if(gap == 1 && !swapped) break;
    }

    return ComplexityCount;
}
