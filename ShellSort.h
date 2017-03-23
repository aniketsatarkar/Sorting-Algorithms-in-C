/***************************************************
Function to sort an array of integers in ascending
order using Shell Sort.
*/
int ShellSort(int *nArray, int ArraySize)
{
    int i,j,k, temp;
    int ComplexityCount = 0;

    for(i=ArraySize/2; i>0; i/=2)
    {
        for(j=i; j<ArraySize; j++)
        {
            for(k=j-i; k>=0; k-=i)
            {
                ComplexityCount++;

                if(nArray[k+i] >= nArray[k])
                    break;
                else
                {
                    temp = nArray[k];
                    nArray[k] = nArray[k+i];
                    nArray[k+i] = temp;
                }
            }
            ComplexityCount++;
        }
        ComplexityCount++;
    }

    return ComplexityCount;
}
