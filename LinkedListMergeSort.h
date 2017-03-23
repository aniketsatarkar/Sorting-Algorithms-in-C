/* ----- Function Declarations ----- */
/* add a ll_node to the linked list */
struct ll_node *AddNode(int , struct ll_node * );

/* preform merge sort on the linked list */
struct ll_node* ll_MergeSort(struct ll_node * , int * );

/* merge the lists.. */
struct ll_node* ll_Merge(struct ll_node * , struct ll_node * , int * );

/* Helper function to sort integer array via liked-lists */
int LinkedListMergeSort(int * , int );


/**
Structure that represent a linked list
ll_node object.
**/
struct ll_node
{
    int number;
    struct ll_node *next;
};


/********************************
Function to print a linked list.
**/
void PrintList(struct ll_node* ll_node)
{
    while(ll_node != NULL)
    {
        printf("%d \n", ll_node -> number);
        ll_node = ll_node -> next;
    }
}



/**************************************************
function to add a ll_node to the linked list.
number is an integer value to add, next is
the ll_node to which the value will belong.
*/
/* add a ll_node to the linked list */
struct ll_node* AddNode(int number, struct ll_node* next)
{
    struct ll_node *tnode;

    tnode = (struct ll_node*)malloc(sizeof(*tnode));

    if(tnode != NULL)
    {
        tnode->number = number;
        tnode->next = next;
    }

    return tnode;
}


/***********************************************
Function to perform a ll_Merge Sort on the linked
list and sort values in ascending order.
NOTE : function return a struct ll_node* pointer
which is the sorted linked list.
*/
struct ll_node* ll_MergeSort(struct ll_node *List, int *c_count)
{
    struct ll_node *head_one;
    struct ll_node *head_two;

    if((List == NULL) || (List->next == NULL))
        return List;

    head_one = List;
    head_two = List->next;

    while((head_two != NULL) && (head_two->next != NULL))
    {
        List = List->next;
        head_two = List->next->next;
        *c_count += 1;
    }

    head_two = List->next;
    List->next = NULL;

 return ll_Merge(ll_MergeSort(head_one, c_count), ll_MergeSort(head_two, c_count), c_count);
}



/***************************************************************
Function to merge the linked lists.
*/
struct ll_node* ll_Merge(struct ll_node *head_one, struct ll_node *head_two, int *c_count)
{
    struct ll_node *head_three;

    *c_count += 1;

    if(head_one == NULL)
        return head_two;

    if(head_two == NULL)
        return head_one;

    if(head_one->number < head_two->number)
    {
        head_three = head_one;
        head_three->next = ll_Merge(head_one->next, head_two, c_count);
    }
    else
    {
        head_three = head_two;
        head_three->next = ll_Merge(head_one, head_two->next, c_count);
    }

    return head_three;
}


/*********************************************************
Helper function to copy integer array into a linked list,
sort it and finally copy sorted linked-list elements
back to the input array.
**********************************************************/
int LinkedListMergeSort(int *nArray, int ArraySize)
{
    struct ll_node *linkedList;
    linkedList = NULL;
    int loopCount = 0;
    int ComplexityCount = 0;

    int i;
    for(i=0; i<ArraySize; i++)
    {
        linkedList = AddNode(nArray[i], linkedList);
    }

    linkedList = ll_MergeSort(linkedList, &ComplexityCount);

    /* Copy sorted Linked-List to input Array */
    while(linkedList != NULL)
    {
        nArray[loopCount] = linkedList -> number;
        linkedList = linkedList -> next;
        loopCount++;
        ComplexityCount++;
    }

    return ComplexityCount;
}
