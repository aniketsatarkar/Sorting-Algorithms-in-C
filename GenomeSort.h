/*---- Function Declaration ----*/
int GenomeSort(int * , int );


/*****************************************************
Function to sort an integer array in ascending order
using Genome Sort algorithm.
*/
int GenomeSort(int *nArray, int ArraySize)
{
    int i = 1;
    int j = 2;
    int ComplexityCount = 0;

    while(i < ArraySize)
    {
        if(nArray[i-1] <= nArray[i])
        {
            i = j;
            j++;
        }
        else
        {
            int temp = nArray[i-1];
            nArray[i-1] = nArray[i];
            nArray[i] = temp;

            i -= 1;

            if(i == 0)
            {
                i = 1;
                j = 2;
            }
        }

        ComplexityCount++;
    }

    return ComplexityCount;
}
