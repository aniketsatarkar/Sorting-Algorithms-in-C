/* ----- function declarations ----- */
int SlowSort(int *, int);

int SlowSort(int *nArrPtr, int ArraySize)
{
    int ComplexityCount = 0;

	while (!is_sorted(nArrPtr, ArraySize, &ComplexityCount))
	{
		shuffle(nArrPtr, ArraySize);
        ComplexityCount++;
	}

    return ComplexityCount;
}
