/* ----- Function Declarations ----- */
int ComboSort(int nArray[], int ArraySize);


/***********************************************************
Function to sort an integer array nArray of size ArraySize
in ascending order using combo sort algorithm.
**/
int ComboSort(int nArray[], int ArraySize)
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

    return ComplexityCount++;
}
