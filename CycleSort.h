/*---- Function Declaration ----*/
int CycleSort(int* , int );

/*****************************************************************
Function to sort an integer array using cycle sort algorithm in
ascending order.
*/
int CycleSort(int* nArray, int ArraySize)
{
    int cycleStart, i;
    int ComplexityCount = 0;

    for(cycleStart=0; cycleStart < (ArraySize-1); cycleStart++)
    {
        int item = nArray[cycleStart];
        int pos = cycleStart;
        int swap_tmp;

        for(i=(cycleStart+1); i<ArraySize; i++)
        {
            if(nArray[i] < item)
                ++pos;
        }

        ComplexityCount++;

        if(pos == cycleStart)
            continue;

        while(item == nArray[pos])
            ++pos;

        swap_tmp = nArray [pos];
        nArray [pos] = item;
        item = swap_tmp;

        while(pos != cycleStart)
        {
            pos = cycleStart;

            for(i=(cycleStart+1) ; i<ArraySize; i++)
            {
                if(nArray[i] < item)
                    ++pos;
            }

            while(item == nArray[pos])
                ++pos;

            swap_tmp = nArray [pos];
            nArray [pos] = item;
            item = swap_tmp;

            ComplexityCount++;
        }
    }
}
