/* macro for swapping values */
#define SWAP(r, s) do{ temp=r; r=s; s=temp;}while(0)

/*---- Function Declaration ----*/
int StoogeSort(int * , int );
void Stooge_Sort(int * , int , int , int *);


/****************************************************
Wrapper function for StoogeSort(), sort entire array.
*/
int StoogeSort(int *nArray, int ArraySize)
{
    int ComplexityCount = 0;
    Stooge_Sort(nArray, 0, ArraySize, &ComplexityCount);

    return ComplexityCount;
}


/***********************************************************
function to sort an integer array in ascending order using
Stooge Sort algorithm.
NOTE : to sort entire array set StartIndex argument to 0
*/
void Stooge_Sort(int *nArray, int StartIndex, int ArraySize, int *c_count)
{
    int temp;

    *c_count += 1;

    if(nArray[ArraySize] < nArray[StartIndex])
        SWAP(nArray[StartIndex], nArray[ArraySize]);

    if(ArraySize-StartIndex > 1)
    {
        temp = (ArraySize-StartIndex + 1) /3;
        Stooge_Sort(nArray, StartIndex, ArraySize-temp, c_count);
        Stooge_Sort(nArray, StartIndex+temp, ArraySize, c_count);
        Stooge_Sort(nArray, StartIndex, ArraySize-temp, c_count);
    }
}
