/*---- Function Declaration ----*/
int OptimizedQuickSort(int * , int );


/*****************************************************
Function to sort an integer array in ascending order
using Optimized Quick Sort algorithm.
*/
int OptimizedQuickSort(int *nArray, int ArraySize)
{
    #define  MAX_LEVELS  1000

    int i=0;
    int piv, l, r;
    int beg[MAX_LEVELS], end[MAX_LEVELS];
    int ComplexityCount = 0;

    beg[0]=0;
    end[0]=ArraySize;

    while (i>=0)
    {
        l=beg[i]; r=end[i]-1;
        if (l<r)
        {
            piv=nArray[l];

            if(i==MAX_LEVELS-1)
                return;
            while (l<r)
            {
                while(nArray[r]>=piv && l<r)
                    r--;

                if (l<r)
                    nArray[l++]=nArray[r];

                while (nArray[l]<=piv && l<r)
                    l++;

                if (l<r)
                    nArray[r--]=nArray[l];

                ComplexityCount++;
            }

            nArray[l]=piv; beg[i+1]=l+1; end[i+1]=end[i]; end[i++]=l;
        }
        else
        {
            i--;
        }

        ComplexityCount++;
    }

    return ComplexityCount;
}
