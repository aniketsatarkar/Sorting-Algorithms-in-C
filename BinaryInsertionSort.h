/* ----- Function Declarations ----- */
int BinarySearch(int *, int , int , int );
int BinaryInsertionSort(int *, int );

/***************************************************************
 * Info : Here we are using binary search to reduce the number *
 * of comparisons in normal insertion sort.                    *
 ***************************************************************/


/*****************************************************
A binary search based function to find the position
where item should be inserted in nArray[low..high]
*/
int BinarySearch(int *nArray, int Item, int Low, int High)
{
    int mid;

    if (High <= Low)
        return (Item > nArray[Low])?  (Low + 1): Low;

    mid = (Low + High)/2;

    if(Item == nArray[mid])
        return mid+1;

    if(Item > nArray[mid])
        return BinarySearch(nArray, Item, mid+1, High);

    return BinarySearch(nArray, Item, Low, mid-1);
}


/***********************************************
Function to sort an array integer array using
binary insertion sort.
*/
int BinaryInsertionSort(int *nArray, int ArraySize)
{
    int i, j, loc, selected;
    int ComplexityCount=0;

    for(i=1; i<ArraySize; i++)
    {
        j = i-1;
        selected = nArray[i];

        loc = BinarySearch(nArray, selected, 0, j);
        ComplexityCount++;

        while(j >= loc)
        {
            nArray[j+1] = nArray[j];
            j--;
            ComplexityCount++;
        }

        nArray[j+1] = selected;
        ComplexityCount++;
    }

    return ComplexityCount;
}
