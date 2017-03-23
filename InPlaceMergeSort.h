/* ----- Function Declarations ----- */
void merge_sort(int * , int * , int , int , int *);
void ipmerge(int *, int *, int , int , int , int *);
int InPlaceMergeSort(int * , int );


/*************************************************
Wrapper function for merge_sort, used to pass a
temporary array of size ArraySize.
*/
int InPlaceMergeSort(int *nArray, int ArraySize)
{
    int temp[ArraySize];
    int ComplexityCount = 0;

    merge_sort(nArray, temp, 0, ArraySize-1, &ComplexityCount);

    return ComplexityCount;
}


/**************************************************************
Recursive in-place merge sort
*/
void merge_sort(int *nArray, int *tempArr, int Left, int Right, int *c_count)
{
    int mid;

    *c_count += 1;

    if(Right > Left)
    {
        mid = (Right + Left) / 2;
        merge_sort(nArray, tempArr, Left, mid, c_count);
        merge_sort(nArray, tempArr, mid+1, Right, c_count);
        ipmerge(nArray, tempArr, Left, mid+1, Right, c_count);
    }
}


/******************************************************************
Function to merge arrays.
*/
void ipmerge(int *nArray, int *tempArr, int Left, int Mid, int Right, int *c_count)
{
    int i, left_end, num_elements, tmp_pos;

    *c_count += 1;

    left_end = Mid - 1;
    tmp_pos = Left;
    num_elements = Right - Left + 1;

    while((Left <= left_end) && (Mid <= Right))
    {
        if(nArray[Left] <= nArray[Mid])
        {
            tempArr[tmp_pos] = nArray[Left];
            tmp_pos = tmp_pos + 1;
            Left = Left +1;
        }
        else
        {
            tempArr[tmp_pos] = nArray[Mid];
            tmp_pos = tmp_pos + 1;
            Mid = Mid + 1;
        }

        *c_count += 1;
    }

    while(Left <= left_end)
    {
        tempArr[tmp_pos] = nArray[Left];
        Left = Left + 1;
        tmp_pos = tmp_pos + 1;

        *c_count += 1;
    }

    while(Mid <= Right)
    {
        tempArr[tmp_pos] = nArray[Mid];
        Mid = Mid + 1;
        tmp_pos = tmp_pos + 1;

        *c_count += 1;
    }

    for(i=0; i<=num_elements; i++)
    {
        nArray[Right] = tempArr[Right];
        Right = Right - 1;

        *c_count += 1;
    }
}
