/* ----- Function Declarations ----- */
//void arrange(int * , int * , int );
void postman_sort(int * , int * , int , int *);
int PostmanSort(int * , int );


/************************************************************
function to arrange elements in array.
void arrange(int *nArray, int *tempArr, int ArraySize)
{
    int i, j;
    int *intPtr;

    for(i=0; i<ArraySize-1; i++)
    {
        for(j=i+1; j<ArraySize; j++)
        {
            if(tempArr[i] > tempArr[j])
            {
                Swap(&tempArr[i], &tempArr[j]);

                intPtr = &nArray[i];
                *intPtr %= 10;
            }
        }
    }
}
*/


/**********************************************************
function to sort an integer array in ascending
order using postman sorting algorithm.
*/
void postman_sort(int *nArray, int *tempArr, int ArraySize, int *c_count)
{
    int i, j;
    int t, t1;
    int max=0, maxDigits=0, n=1, c=0;

    for(i=0; i<ArraySize; i++)
	{
        tempArr[i] = nArray[i];
    }

    for(i=0; i<ArraySize; i++)
    {
        t = nArray[i];

        while(t > 0)
        {
            c++;
            t = t/10;
            *c_count += 1;
        }

        if(maxDigits < c)
            maxDigits = c;

        c = 0;

        *c_count += 1;
    }

    while(--maxDigits)
    {
        n = n * 10;
        *c_count += 1;
    }

    for(i=0; i<ArraySize; i++)
    {
		max = nArray[i]/n;
        t = i;

        for(j=i+1; j<ArraySize; j++)
        {
            if(max > (nArray[j]/n))
            {
                max = nArray[j]/n;
                t = j;
            }

            *c_count += 1;
        }

         Swap(&tempArr[t], &tempArr[i]);
         Swap(&nArray[t], &nArray[i]);

        *c_count += 1;
    }

    while(n >= 1)
    {
        for(i=0; i<ArraySize; )
        {
            t1 = nArray[i]/n;
            i = j;

            *c_count += 1;
        }

		n = n/10;
        *c_count += 1;
    }
}


/**********************************************
Wrapper function for postman_sort() function,
used to pass a temporary to target function.
*/
int PostmanSort(int *nArray, int ArraySize)
{
    int tempArray[ArraySize];
    int ComplexityCount = 0;

    postman_sort(nArray, tempArray, ArraySize, &ComplexityCount);

    return ComplexityCount;
}
