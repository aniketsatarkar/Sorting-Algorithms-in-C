/** Dependency **********/
/************************/
#include <stdint.h>
#include "sort_common.h"


/**********************************************************
NOTE : SORT_TYPE macro must be defined in order to
sort an array of desired data type. This definition can
be given in the main function context. Here data type has
been defined as int.
***********************************************************/

/** Data Type to Sort **/
/***********************/
#define SORT_TYPE int
/***********************/


/** Macro definitions *****************************************************************/
/**************************************************************************************/
#define TIM_SORT_STACK_SIZE 128
#define SORT_CONCAT(x, y) x ## _ ## y
#define SORT_MAKE_STR1(x, y) SORT_CONCAT(x,y)
#define SORT_MAKE_STR(x) SORT_MAKE_STR1(SORT_NAME,x)
#define PUSH_NEXT SORT_MAKE_STR(push_next)
#define COUNT_RUN SORT_MAKE_STR(count_run)
#define BINARY_INSERTION_FIND  SORT_MAKE_STR(binary_insertion_find)
#define SORT_CMP(x, y)  ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))
#define SORT_SWAP(x,y) {SORT_TYPE __SORT_SWAP_t = (x); (x) = (y); (y) = __SORT_SWAP_t;}
/*****************************************************************************************/


/** Structures  **************************/
/*****************************************/
/* structure define tim sort store type  */
typedef struct
{
    size_t alloc;
    SORT_TYPE *storage;
}
TEMP_STORAGE_T;


/* structure define tim sort runtime. */
typedef struct
{
    uint64_t start;
    uint64_t length;
}
TIM_SORT_RUN_T;

static int ComplexityCount = 0;

/** Function Declarations *************************************************************************/
/**************************************************************************************************/
int TimSort(SORT_TYPE *, const size_t );
void BinaryInsertionSortStart(SORT_TYPE * , const size_t , const size_t );
void BINARY_INSERTION_SORT(SORT_TYPE * , const size_t );
int BINARY_INSERTION_FIND(SORT_TYPE * , const SORT_TYPE , const size_t );
int CHECK_INVARIANT(TIM_SORT_RUN_T * , const int );
int TIM_SORT_COLLAPSE(SORT_TYPE * , TIM_SORT_RUN_T * , int  , TEMP_STORAGE_T * , const size_t );
void TIM_SORT_MERGE(SORT_TYPE * , const TIM_SORT_RUN_T * , const int , TEMP_STORAGE_T * );
void TIM_SORT_RESIZE(TEMP_STORAGE_T * , const size_t );
int COUNT_RUN(SORT_TYPE * , const uint64_t , const size_t  );
void REVERSE_ELEMENTS(SORT_TYPE * , int64_t , int64_t );
int PUSH_NEXT(SORT_TYPE * , const size_t  , TEMP_STORAGE_T * ,
              const uint64_t , TIM_SORT_RUN_T * ,
              uint64_t * , uint64_t * );
/**************************************************************************************************/



/***********************************************
Function to sort an array of defined type in
ascending order using Tim sort algorithm.
*/
int TimSort(SORT_TYPE *dst, const size_t size)
{
    ComplexityCount = 0;

    if (size == 0)
        return ComplexityCount;

    uint64_t minrun;

    TEMP_STORAGE_T _store, *store;
    TIM_SORT_RUN_T run_stack[TIM_SORT_STACK_SIZE];

    uint64_t stack_curr = 0;
    uint64_t curr = 0;

    if(size < 64)
    {
        BINARY_INSERTION_SORT(dst, size);
        return ComplexityCount;
    }

    minrun = compute_minrun(size);

    store = &_store;
    store->alloc = 0;
    store->storage = NULL;

    if(!PUSH_NEXT(dst, size, store, minrun, run_stack, &stack_curr, &curr))
        return ComplexityCount;

    if(!PUSH_NEXT(dst, size, store, minrun, run_stack, &stack_curr, &curr))
        return ComplexityCount;

    if (!PUSH_NEXT(dst, size, store, minrun, run_stack, &stack_curr, &curr))
        return ComplexityCount;

    while(1)
    {
        if(!CHECK_INVARIANT(run_stack, stack_curr))
        {
            stack_curr = TIM_SORT_COLLAPSE(dst, run_stack, stack_curr, store, size);
            continue;
        }

        if(!PUSH_NEXT(dst, size, store, minrun, run_stack, &stack_curr, &curr))
            return ComplexityCount;
    }
}



/*********************************************
binary sort helper function
*/
void BINARY_INSERTION_SORT_START(SORT_TYPE *dst, const size_t start, const size_t size)
{
    uint64_t i;

    for(i=start; i<size; i++)
    {
        ComplexityCount++;

        int64_t j;
        SORT_TYPE x;
        int64_t location;

        if(SORT_CMP(dst[i - 1], dst[i]) <= 0)
            continue;

        x = dst[i];
        location = BINARY_INSERTION_FIND(dst, x, i);

        for(j = i - 1; j >= location; j--)
            dst[j + 1] = dst[j];

        dst[location] = x;
    }
}


/***********************************************************
binary insertion sort function used internally in TIM_SORT()
*/
void BINARY_INSERTION_SORT(SORT_TYPE *dst, const size_t size)
{
    if (size == 0)
        return;

  BINARY_INSERTION_SORT_START(dst, 1, size);
}


/******************************************************************************
Binary insertion sort helper function.
*/
int BINARY_INSERTION_FIND(SORT_TYPE *dst, const SORT_TYPE x, const size_t size)
{
    int64_t l, c, r;
    SORT_TYPE cx;
    l = 0;
    r = size - 1;
    c = r >> 1;

    if (SORT_CMP(x, dst[0]) < 0)
        return 0;
    else if (SORT_CMP(x, dst[r]) > 0)
        return r;

    cx = dst[c];

    while (1)
    {
        ComplexityCount++;

        const int val = SORT_CMP(x, cx);

        if (val < 0)
        {
            if (c - l <= 1)
            {
                return c;
            }

            r = c;
        }
        else
        {
            if (r - c <= 1)
                return c + 1;
            l = c;
        }

        c = l + ((r - l) >> 1);
        cx = dst[c];
    }
}


int CHECK_INVARIANT(TIM_SORT_RUN_T *stack, const int stack_curr)
{
    int64_t A, B, C;

    if(stack_curr < 2)
        return 1;

    if(stack_curr == 2)
    {
        const int64_t A1 = stack[stack_curr - 2].length;
        const int64_t B1 = stack[stack_curr - 1].length;

        if(A1 <= B1)
            return 0;

        return 1;
    }

    A = stack[stack_curr - 3].length;
    B = stack[stack_curr - 2].length;
    C = stack[stack_curr - 1].length;

    if((A <= B + C) || (B <= C))
        return 0;

    return 1;
}




int TIM_SORT_COLLAPSE(SORT_TYPE *dst, TIM_SORT_RUN_T *stack, int stack_curr, TEMP_STORAGE_T *store, const size_t size)
{
    while(1)
    {
        int64_t A, B, C, D;
        int ABC, BCD, CD;

        ComplexityCount++;

        /* if the stack only has one thing on it, we are done with the collapse */
        if (stack_curr <= 1)
        {
            break;
        }

        /* if this is the last merge, just do it */
        if((stack_curr == 2) && (stack[0].length + stack[1].length == size))
        {
            TIM_SORT_MERGE(dst, stack, stack_curr, store);
            stack[0].length += stack[1].length;
            stack_curr--;
            break;
        }
        else if((stack_curr == 2) && (stack[0].length <= stack[1].length))
        {
            TIM_SORT_MERGE(dst, stack, stack_curr, store);
            stack[0].length += stack[1].length;
            stack_curr--;
            break;
        }
        else if(stack_curr == 2)
        {
            break;
        }

        B = stack[stack_curr - 3].length;
        C = stack[stack_curr - 2].length;
        D = stack[stack_curr - 1].length;

        if(stack_curr >= 4)
        {
            A = stack[stack_curr - 4].length;
            ABC = (A <= B + C);
        }
        else
        {
            ABC = 0;
        }

        BCD = (B <= C + D) || ABC;
        CD = (C <= D);

        if(!BCD && !CD)
        {
            break;
        }

        if(BCD && !CD)
        {
            TIM_SORT_MERGE(dst, stack, stack_curr - 1, store);
            stack[stack_curr - 3].length += stack[stack_curr - 2].length;
            stack[stack_curr - 2] = stack[stack_curr - 1];
            stack_curr--;
        }
        else
        {
            TIM_SORT_MERGE(dst, stack, stack_curr, store);
            stack[stack_curr - 2].length += stack[stack_curr - 1].length;
            stack_curr--;
        }
    }

    return stack_curr;
}


void TIM_SORT_MERGE(SORT_TYPE *dst, const TIM_SORT_RUN_T *stack, const int stack_curr, TEMP_STORAGE_T *store)
{
    const int64_t A = stack[stack_curr - 2].length;
    const int64_t B = stack[stack_curr - 1].length;
    const int64_t curr = stack[stack_curr - 2].start;
    SORT_TYPE *storage;
    int64_t i, j, k;
    TIM_SORT_RESIZE(store, MIN(A, B));
    storage = store->storage;

    /* left merge */
    if(A < B)
    {
        memcpy(storage, &dst[curr], A * sizeof(SORT_TYPE));
        i = 0;
        j = curr + A;

        for(k = curr; k < curr + A + B; k++)
        {
            if((i < A) && (j < curr + A + B))
            {
                if(SORT_CMP(storage[i], dst[j]) <= 0)
                {
                    dst[k] = storage[i++];
                }
                else
                {
                    dst[k] = dst[j++];
                }
            }
            else if(i < A)
            {
                dst[k] = storage[i++];
            }
            else
            {
                dst[k] = dst[j++];
            }

            ComplexityCount++;
        }
    }
    else
    {
        /* right merge */
        memcpy(storage, &dst[curr + A], B * sizeof(SORT_TYPE));
        i = B - 1;
        j = curr + A - 1;

        for(k = curr + A + B - 1; k >= curr; k--)
        {
            if((i >= 0) && (j >= curr))
            {
                if (SORT_CMP(dst[j], storage[i]) > 0)
                {
                    dst[k] = dst[j--];
                }
                else
                {
                    dst[k] = storage[i--];
                }
            }
            else if (i >= 0)
            {
                dst[k] = storage[i--];
            }
            else
            {
                dst[k] = dst[j--];
            }

            ComplexityCount++;
        }
    }
}


void TIM_SORT_RESIZE(TEMP_STORAGE_T *store, const size_t new_size)
{
    if(store->alloc < new_size)
    {
        SORT_TYPE *tempstore = (SORT_TYPE *)realloc(store->storage, new_size * sizeof(SORT_TYPE));

        if (tempstore == NULL)
        {
            fprintf(stderr, "Error allocating temporary storage for tim sort: need %lu bytes",
            sizeof(SORT_TYPE) * new_size);
            exit(1);
        }

        store->storage = tempstore;
        store->alloc = new_size;
    }
}



int PUSH_NEXT(SORT_TYPE *dst, const size_t size, TEMP_STORAGE_T *store,
              const uint64_t minrun, TIM_SORT_RUN_T *run_stack,
              uint64_t *stack_curr, uint64_t *curr)
{
    uint64_t len = COUNT_RUN(dst, *curr, size);
    uint64_t run = minrun;

    if(run > size - *curr)
    {
        run = size - *curr;
    }

    if(run > len)
    {
        BINARY_INSERTION_SORT_START(&dst[*curr], len, run);
        len = run;
    }

    run_stack[*stack_curr].start = *curr;
    run_stack[*stack_curr].length = len;
    (*stack_curr)++;
    *curr += len;

    if(*curr == size)
    {
        /* finish up */
        while (*stack_curr > 1)
        {
            ComplexityCount++;
            TIM_SORT_MERGE(dst, run_stack, *stack_curr, store);
            run_stack[*stack_curr - 2].length += run_stack[*stack_curr - 1].length;
            (*stack_curr)--;
        }

        if(store->storage != NULL)
        {
            free(store->storage);
            store->storage = NULL;
        }

        return 0;
    }

    return 1;
}



int COUNT_RUN(SORT_TYPE *dst, const uint64_t start, const size_t size)
{
    uint64_t curr;

    if (size - start == 1)
        return 1;

    if(start >= size - 2)
    {
        if(SORT_CMP(dst[size - 2], dst[size - 1]) > 0)
            SORT_SWAP(dst[size - 2], dst[size - 1]);

        return 2;
    }

    curr = start + 2;

    if(SORT_CMP(dst[start], dst[start + 1]) <= 0)
    {
        /* increasing run */
        while (1)
        {
            ComplexityCount++;

            if(curr == size - 1)
                break;

            if(SORT_CMP(dst[curr - 1], dst[curr]) > 0)
                break;

            curr++;
        }

        return curr - start;
    }
    else
    {
        /* decreasing run */
        while (1)
        {
            ComplexityCount++;

            if(curr == size - 1)
                break;

            if(SORT_CMP(dst[curr - 1], dst[curr]) <= 0)
                break;

            curr++;
        }

        REVERSE_ELEMENTS(dst, start, curr - 1);
        return curr - start;
    }
}


void REVERSE_ELEMENTS(SORT_TYPE *dst, int64_t start, int64_t end)
{
    while(1)
    {
        ComplexityCount++;

        if(start >= end)
            return;

        SORT_SWAP(dst[start], dst[end]);
        start++;
        end--;
    }
}
