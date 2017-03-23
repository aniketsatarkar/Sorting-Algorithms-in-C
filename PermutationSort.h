#include <string.h>

/*---- Function Declarations ----*/
int scmp(const void * , const void * );
int PermutationSort(void * , int , size_t );


/*************************************
function to compare two strings.
**/
int scmp(const void *a, const void *b)
{
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

/**********************************************************
Function to sort strings in alphabetic order.
**/
int PermutationSort(void *sArray, int ArraySize, size_t mSize)
{
	char *p, *q, *tmp = malloc(mSize);
    int ComplexityCount = 0;

#	define A(i) ((char *)sArray + mSize * (i))

#	define swap(a, b) {\
		memcpy(tmp, a, mSize);\
		memcpy(a, b, mSize);\
		memcpy(b, tmp, mSize);	}

	while(1)
    {
		/* find largest k such that a[k - 1] < a[k] */
		for(p=A(ArraySize-1); (void*)p > sArray; p=q)
		{
            ComplexityCount++;
		    if (scmp(q = p - mSize, p) > 0)
				break;
		}

		if((void*)p <= sArray)
            break;

		for(p = A(ArraySize - 1); p > q; p-= mSize)
        {
            ComplexityCount++;
			if(scmp(q, p) > 0)
                break;
        }

		swap(p, q);

		for(q+=mSize, p=A(ArraySize-1); q<p; q+=mSize, p-=mSize)
        {
			swap(p, q);
            ComplexityCount++;
        }

        ComplexityCount++;
	}

	free(tmp);

    return ComplexityCount;
}
