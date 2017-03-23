/*----- Function Declarations -----*/
void Swap(int * , int * );
void _Swap(int* , int * );
int NewGap(int );
void _InsertionSort(int * , int , int * );
int is_sorted(int * , int , int * );
void shuffle(int * , int );
int Partition(int * , int , int , int * );


/****************************
Function to swap two values.
*/
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


/****************************************
 Function to swap two array elements.
*/
void _Swap(int* x, int* y)
{
    if(x == y) return;

    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}


int NewGap(int gap)
{
    gap = (gap * 10) / 13;

    if((gap == 9 )|| (gap == 10))
        gap = 11;

    if(gap < 1)
        gap = 1;

    return gap;
}


/***************************************************
function to sort an integer array nArray of length
ArraysSize in ascending order.
*/
void _InsertionSort(int* nArray, int ArraySize, int *c_count)
{
    int i = 0;

	for (i = 1; i < ArraySize; ++i)
	{
		int j = i;
		while (j > 0)
		{
		    *c_count += 1;

			if (nArray[j - 1] > nArray[j])
			{
				nArray[j - 1] ^= nArray[j];
				nArray[j] ^= nArray[j - 1];
				nArray[j - 1] ^= nArray[j];

				--j;
			}
			else
			{
				break;
			}
		}

        *c_count += 1;
	}
}


/********************************************************
function to check if the array is sorted or not.
*/
int is_sorted(int *nArrPtr, int ArraySize, int *c_count)
{
	while ((--ArraySize) >= 1)
	{
        *c_count += 1;
		if (nArrPtr[ArraySize] < nArrPtr[ArraySize - 1]) return 0;
	}

	return 1;
}


/****************************************
Function to shuffle array elements.
*/
void shuffle(int *nArrPtr, int ArraySize)
{
	int i, temp1, temp2;

	for (i=0; i<ArraySize; i++)
	{
		temp1 = nArrPtr[i];
		temp2 = rand() % ArraySize;
		nArrPtr[i] = nArrPtr[temp2];
		nArrPtr[temp2] = temp1;
	}

}


/****************************************************
function used to create partition of provided array.
*/
int Partition(int* nArray, int left, int right, int *c_count)
{
	int pivot = nArray[right];
	int temp;
	int i = left;
    int j;

	for (j = left; j < right; ++j)
	{
		if (nArray[j] <= pivot)
		{
			temp = nArray[j];
			nArray[j] = nArray[i];
			nArray[i] = temp;
			i++;
		}

        *c_count += 1;
	}

	nArray[right] = nArray[i];
	nArray[i] = pivot;

	return i;
}
