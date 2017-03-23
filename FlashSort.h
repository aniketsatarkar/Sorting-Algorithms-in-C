/* --- global constants --- */
const int THRESHOLD = 75;
const int CLASS_SIZE = 75; /* minimum value for m (dimension) */

/* ----- Function Declarations ----- */
void flash_sort(int *, int , int , int * , int * );
int FlashSort(int *, int );


/*******************************************************************
Function to sort an integer array of size ArraySize with dimension
m, function also take a temporary integer pointer.
*/
void flash_sort(int *nArray, int ArraySize, int m, int *TempPtr, int *c_count)
{
    int *l, nmin, nmax, i, j, k, nmove, nx, mx;
    int c1, c2, flash, hold;


    /* allocate space for the l vector */
    l=(int*)calloc(m,sizeof(int));


    /***** CLASS FORMATION ****/
    nmin = nmax = 0;

    for (i=0; i<ArraySize; i++)
    {
        if (nArray[i] < nArray[nmin])
            nmin = i;
        else if(nArray[i] > nArray[nmax])
            nmax = i;
    }


    if((nArray[nmax]==nArray[nmin]) && (TempPtr==0))
    {
        /*
        printf("All the numbers are identical, the list is sorted\n");
        */
        return;
    }

    c1=(m-1)/(nArray[nmax]-nArray[nmin]);
    c2=nArray[nmin];

    l[0]=-1; /* since the base of the "a" (data) array is 0 */

    for (k=1; k < m ; k++)
        l[k]=0;

    for(i=0; i<ArraySize; i++)
    {
        k=floor(c1*(nArray[i]-c2) );
        l[k]+=1;
    }

    for (k=1; k<m; k++)
        l[k]+=l[k-1];

    hold=nArray[nmax];
    nArray[nmax]=nArray[0];
    nArray[0]=hold;


    /**** PERMUTATION *****/
    nmove=0;
    j=0;
    k=m-1;

    while(nmove < ArraySize)
    {
        while(j > l[k])
        {
            j++;
            k = floor(c1*(nArray[j]-c2));
            *c_count += 1;
        }

        flash = nArray[j];

        while ( j <= l[k] )
        {
            k = floor(c1*(flash-c2));

            hold = nArray[l[k]];
            nArray[l[k]] = flash;
            flash=hold;

            l[k]--;
            nmove++;

            *c_count += 1;
        }
        *c_count += 1;
    }

    /* Perform RECURSION or INSERTION sort */
    for (k=0; k<(m-1); k++)
    {
        if ((nx=l[k+1]-l[k]) > THRESHOLD)  /* then use recursion */
		{
			flash_sort(&nArray[l[k]+1], nx, CLASS_SIZE, TempPtr, c_count);
			(*TempPtr)++;
		}
		else  /* use insertion sort */
        {
            _InsertionSort(nArray, ArraySize, c_count);
        }
        *c_count += 1;
    }

    for (i=l[k+1]-1; i > l[k]; i--)
    {
        if (nArray[i] > nArray[i+1])
        {
            hold = nArray[i];
            j = i;

            while(hold > nArray[j+1])
                nArray[j++] = nArray[j+1];

            nArray[j] = hold;
        }
        *c_count += 1;
    }

    /* free memory from l vector */
    free(l);
}


/*********************************************
Wrapper function to sort an integer array in
ascending order using flash sort.
*/
int FlashSort(int *nArray, int ArraySize)
{
    /* temporary integer pointer */
    int *temp_ptr;
    int ComplexityCount = 0;

    /* calling flashsort() function to sort nArray.    */
    /* dimension parameter 'm' is passed as ArraySize. */
    flash_sort(nArray, ArraySize, ArraySize, temp_ptr, &ComplexityCount);

    return ComplexityCount;
}
