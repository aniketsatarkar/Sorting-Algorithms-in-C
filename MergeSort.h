/* ----- Function Declarations -----*/
int MergeSort(int *, int );
void m_sort(int *, int *, int , int, int * );
void Merge(int *, int *, int , int , int , int *);


/**********************************************
Function to sort an integer array in ascending
order using merge sort algorithm.
*/
int MergeSort(int *nArray, int ArraySize)
{
    int tempArr[ArraySize];
    int ComplexityCount = 0;

    m_sort(nArray, tempArr, 0, ArraySize-1, &ComplexityCount);

    return ComplexityCount;
}


/* merger sort recursive method */
void m_sort(int *nArray, int *TempArray, int left, int right, int *c_count)
{
    int mid;

    *c_count += 1;

    if (right > left)
    {
        mid = (right + left) / 2;
        m_sort(nArray, TempArray, left, mid, c_count);
        m_sort(nArray, TempArray, mid+1, right, c_count);
        Merge(nArray, TempArray, left, mid+1, right, c_count);
    }
}

/* function to merger lists */
void Merge(int *nArray, int *TempArray, int left, int mid, int right, int *c_count)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;

    *c_count += 1;

    while((left <= left_end) && (mid <= right))
    {
        if (nArray[left] <= nArray[mid])
        {
            TempArray[tmp_pos] = nArray[left];
            tmp_pos = tmp_pos + 1;
            left = left +1;
        }
        else
        {
            TempArray[tmp_pos] = nArray[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }

        *c_count += 1;
    }

    while (left <= left_end)
    {
        TempArray[tmp_pos] = nArray[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;

        *c_count += 1;
    }

    while (mid <= right)
    {
        TempArray[tmp_pos] = nArray[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;

       *c_count += 1;
    }

    for (i = 0; i <= num_elements; i++)
    {
        nArray[right] = TempArray[right];
        right = right - 1;

        c_count += 0;
    }
}
