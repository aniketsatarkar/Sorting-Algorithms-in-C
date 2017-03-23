#define MIN_SORTABLE_LENGTH 128

/*---- Function Declaration ----*/
int HistogramSort(int * , int );


/**************************************************************
This function sorts an array of integers in place using a math
sort based histogram sort. 2*ArraySize locations of auxiliary
space are used, where ArraySize is nArray length.
*/
int HistogramSort(int *nArray, int ArraySize)
{
    int i, j, ifac, temp;
    int nArray_min, nArray_max, index_min;
    int *space, *cmp_index, *cum, *hist, *sorted;
    int ComplexityCount = 0;

    /* if array only contain one element just return... */
    if(ArraySize <= 1)
        return ComplexityCount;

    /* if array only contain two elements compare, swipe and return... */
    if(ArraySize == 2)
    {
        if (nArray[0] > nArray[1])
        {
            temp = nArray[0];
            nArray[0] = nArray[1];
            nArray[1] = temp;
        }
        return ++ComplexityCount;
    }

    nArray_min  = nArray[0];
    nArray_max  = nArray[0];
    index_min = 0;

    for(i=ArraySize; --i>0; )
    {
        if(nArray[i] < nArray_min)
        {
            nArray_min  = nArray[i];
            index_min = i;
        }
   }

    if(index_min != 0)
    {
        nArray[index_min] = nArray[0];
        nArray[0] = nArray_min;
    }

    if(ArraySize >= MIN_SORTABLE_LENGTH)
    {
        for (i=ArraySize; --i>0;)
        {
            if (nArray[i] > nArray_max)
                nArray_max  = nArray[i];
        }

        /* Compute interpolation function */
        ifac = (nArray_max - nArray_min)/(ArraySize -1);

        if(ifac<=0)
            ifac=1;
        else
            while(((nArray_max-nArray_min)/ifac)>(ArraySize-1)) ifac++;

        /* allocate index and histogram space */
        space = malloc((2*ArraySize+1)*sizeof(int));

        if(!space)
            return ComplexityCount;

        cmp_index = space;
        cum = space + ArraySize;
        hist = cum + 1;
        sorted = hist;

        memset(cum, 0, (ArraySize+1)*sizeof(int));

        /* Compute raw interpolation indices */
        for(i=ArraySize; --i>=0;)
        {
            hist[cmp_index[i] = (nArray[i] - nArray_min)/ifac] += 1;
            ComplexityCount++;
        }

        for(i=1;i<ArraySize;i++)
        {
            cum[i] += cum[i-1];
            ComplexityCount++;
        }

        for(i=0;i<ArraySize;i++)
        {
            cmp_index[i] = cum[cmp_index[i]]++;
            ComplexityCount++;
        }


        /* Math sort proper */
        for(i=ArraySize; --i >= 0;)
        {
            sorted[cmp_index[i]] = nArray[i];
            ComplexityCount++;
        }

        memcpy(nArray, sorted, ArraySize*sizeof(int));

        free(space);
    }

    /* End of sort section, begin insertion sort section */
    {
        for(i=1; i<ArraySize; i++)
        {
            ComplexityCount++;

            if(nArray[i] >= nArray[i-1])
                continue;

            temp = nArray[i];
            nArray[i] = nArray[i-1];

            for (j=i-2; temp < nArray[j]; j--)
            {
                nArray[j+1] = nArray[j];
                ComplexityCount++;
            }

            nArray[j+1] = temp;
      }
   }/* end of of code block */

    return ComplexityCount++;
}
