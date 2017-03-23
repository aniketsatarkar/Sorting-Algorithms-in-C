/* ----- Function Declarations ----- */
int BidirectionalBubbleSort(int* nArrPtr, size_t arrSize);

/**********************************************************
    Function to sort array of integers in ascending order.
**/
int BidirectionalBubbleSort(int* nArrPtr, size_t arrSize)
{
    int i, it;
    int ComplexityCount = 0;

	while(1)
    {
		char flag;
		size_t start[2] = {1, arrSize-1},
			     end[2] = {arrSize, 0},
			     inc[2] = {1, -1};

		for(it=0; it<2; it++)
		{
			flag = 1;

			for(i=start[it]; i != end[it]; i+=inc[it])
            {
                if(nArrPtr[i-1] > nArrPtr[i])
                {
					_Swap(nArrPtr + i - 1, nArrPtr + i);
					flag = 0;
                    ComplexityCount++;
				}
            }
			if(flag)
                return ComplexityCount;
		}
	}

    return ComplexityCount;
}
