#define BEAD(i, j) beads[i * maxValue + j]

/*---- Function Declaration ----*/
int BeadSort(int * , int );


int BeadSort(int *nArray, int arrLength)
{
    int i, j;   /* loop variables */
    static int sum, maxValue;
    unsigned char *beads; /* char pointer used to store beads */
    int ComplexityCount=0;

    /*
    #define BEAD(i, j) beads[i * maxValue + j]
    */

    /* find maximum number from array values and assign to maxValue. */
    for (i = 0; i<arrLength; i++)
    {
		if (nArray[i] > maxValue)
            maxValue = nArray[i];
    }

    /* Allocate memory to beads */
	beads = calloc(1, maxValue * arrLength);

	/* mark the beads */
	for (i = 0; i < arrLength; i++)
    {
        for (j = 0; j < nArray[i]; j++)
        {
			BEAD(i, j) = 1;
            ComplexityCount++;
        }
    }


	for (j=0; j<maxValue; j++)
    {
        /* initialize sum and find number of beads */
        sum = 0;
		for (i = 0; i < arrLength; i++)
		{
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
            ComplexityCount++;
		}

		for (i = arrLength-sum; i < arrLength; i++)
        {
            BEAD(i, j) = 1;
            ComplexityCount++;
        }
	}


	for (i = 0; i < arrLength; i++)
    {
		for (j = 0; (j<maxValue && BEAD(i, j)); j++)
        {
            nArray[i] = j;
            ComplexityCount++;
        }
	}

    /* free allocated memory from beads pointer */
	free(beads);

    return ComplexityCount;
}
