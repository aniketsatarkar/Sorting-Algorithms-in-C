#include <stdint.h>

/* unsigned integer array containing Leonardo numbers */
static const uint32_t L[] =
{
    1UL, 1UL, 3UL, 5UL, 9UL, 15UL, 25UL, 41UL, 67UL, 109UL, 177UL,
    287UL, 465UL, 753UL, 1219UL, 1973UL, 3193UL, 5167UL, 8361UL,
    13529UL, 21891UL, 35421UL, 57313UL, 92735UL, 150049UL,
    242785UL, 392835UL, 635621UL, 1028457UL, 1664079UL, 2692537UL,
    4356617UL, 7049155UL, 11405773UL, 18454929UL, 29860703UL,
    48315633UL, 78176337UL, 126491971UL, 204668309UL, 331160281UL,
    535828591UL, 866988873UL, 1402817465UL, 2269806339UL,
    3672623805UL
};


/* structure define heapsize data type */
typedef struct
{
    uint64_t mask;
    int offset;
}heapsizes;


/* ----- function Declarations ----- */
heapsizes Heapify(int * , uint32_t , int * );
void Extract(int * , uint32_t  , heapsizes , int * );
void SiftIn(int * , int , int * );
void InterheapSift(int * , heapsizes , int *);
int SmoothSort(int *, uint32_t );


/*************************************************
Function to sort an integer array in ascending
order using smooth sort algorithm.
*/
int SmoothSort(int *nArray, uint32_t ArraySize)
{
    heapsizes hsz;
    int ComplexityCount = 0;

    if (ArraySize < 2)
        return ComplexityCount;

    hsz = Heapify(nArray, ArraySize, &ComplexityCount);
    Extract(nArray, ArraySize, hsz, &ComplexityCount);

    return ComplexityCount;
}


/*******************************************
Function to create a heap of array values.
*/
heapsizes Heapify(int *nArray, uint32_t ArraySize, int *c_count)
{
    heapsizes hsz;
    uint32_t i;
    int wbf;

    hsz.mask = 1;
    hsz.offset = 1;

    for(i=1; i<ArraySize; i++)
    {
        if(hsz.mask & 2)
        {
            hsz.mask = (hsz.mask>>2) | 1;
            hsz.offset += 2;
        }
        else if(hsz.offset == 1)
        {
            hsz.mask = (hsz.mask << 1) | 1;
            hsz.offset = 0;
        }
        else
        {
            hsz.mask = (hsz.mask << (hsz.offset-1)) | 1;
            hsz.offset = 1;
        }

        wbf = ((hsz.mask & 2) && i+1 < ArraySize ) || ( hsz.offset > 0 && 1ULL+i+L[hsz.offset-1] < ArraySize );

        if (wbf)
            SiftIn(nArray+i, hsz.offset, c_count);
        else
            InterheapSift(nArray+i, hsz, c_count);

        *c_count += 1;
    }

    return hsz;
}


/***********************************************************
Function to retrieve values from the heap.
*/
void Extract(int *nArray, uint32_t ArraySize, heapsizes hsz, int *c_count)
{
    uint32_t i;

    uint32_t ch[2];

    int j;

    for(i=ArraySize-1; i>1; i--)
    {
        if(hsz.offset<2)
        {
            do
            {
                hsz.mask >>= 1;
                hsz.offset ++;
                *c_count += 1;
            }
            while(!(hsz.mask&1));
        }
        else
        {
            ch[1] = i - 1;
            ch[0] = ch[1] - L[hsz.offset-2];

            hsz.mask &= ~1ULL;

            for(j=0; j<2; j++)
            {
                hsz.mask = (hsz.mask << 1) | 1;
                hsz.offset --;

                InterheapSift(nArray+ch[j], hsz, c_count);
                *c_count += 1;
            }
        }

        *c_count += 1;
    }
}


void SiftIn(int *root, int size, int *c_count)
{
    int *left, *right;
    int *next;
    int tmp;
    int nsz;

    if(size < 2)
        return;

    tmp = *root;

    do
    {
        right = root - 1;
        left = right - L[size-2];

        if (*right < *left)
        {
            next = left;
            nsz = size - 1;
        }
        else
        {
            next = right;
            nsz = size - 2;
        }

        if (*next <= tmp)
            break;

        *root = *next;
        root = next;
        size = nsz;

        *c_count += 1;

    }while (size > 1);

    *root = tmp;
}


/*******************************************
function to swap heaps
*/
void InterheapSift(int *root, heapsizes hsz, int *c_count)
{
    int *next;
    int *left;
    int *right;
    int tmp;
    int max;

    tmp = *root;

    while(hsz.mask != 1)
    {
        max = tmp;

        if(hsz.offset > 1)
        {
            right = root - 1;
            left = right - L[hsz.offset-2];

            if (max < *left)
                max = *left;

            if (max < *right)
                max = *right;
        }

        next = root - L[hsz.offset];

        if(*next <= max)
            break;

        *root = *next;
        root = next;

        do
        {
            hsz.mask >>= 1;
            hsz.offset ++;
            *c_count += 1;
        }
        while (!(hsz.mask&1));

        *c_count += 1;
    }

    *root = tmp;
    SiftIn (root, hsz.offset, c_count);
}
