/* ----- Function Declarations -----*/
int AddressCalculationSort(int *, int );
void InsertNumber(int , int );
int LargeNumber(int *, int );
int FindIndex(int ,int );


/***************************************
Structure represent a node in a linked
list.
*/
struct  node
{
    int number;
    struct node *link;
};

struct node *head[10];


/********************************************************
Function to sort an integer array in ascending order
using Address Calculation Sort algorithm.
*/
int AddressCalculationSort(int *nArray, int ArraySize)
{
	int i,k;
	int addr;
	struct node *p;
    int complexityCount=0;


	k = LargeNumber(nArray, ArraySize);

	for(i=0; i<ArraySize; i++)
		head[i]=NULL;

	for(i=0; i<ArraySize; i++)
	{
		addr=FindIndex(nArray[i], k);
		InsertNumber(nArray[i], addr);
	}

	for(i=0; i<ArraySize; i++)
	{
        p=head[i];

		while(p!=NULL)
        {
			p=p->link;
			complexityCount++;
        }
	}

	i=0;

	for(k=0; k<ArraySize; k++)
	{
		p=head[k];
		while(p!=NULL)
		{
			nArray[i++] = p->number;
			p=p->link;
            complexityCount++;
		}
	}

    return complexityCount;
}


/***********************************************
Function to insert a number in the liked list.
*/
void InsertNumber(int Number, int Address)
{
	struct node *q,*tmp;
	tmp = malloc(sizeof(struct node));
	tmp->number = Number;

   /*list empty or item to be added in begining */
	if(head[Address] == NULL || Number < head[Address]->number)
	{
		tmp->link=head[Address];
		head[Address]=tmp;
		return;
	}
	else
	{
		q=head[Address];

		while(q->link != NULL && q->link->number < Number)
			q=q->link;

		tmp->link=q->link;
		q->link=tmp;
	}
}


/****************************************
Function to find number of digits in the
largest element of the list.
*/
int LargeNumber(int *nArray, int ArraySize)
{
    int i=0;
	int large = 0, ndig = 0;

	for(i=0; i<ArraySize; i++)
	{
		if(nArray[i] > large)
			large = nArray[i];
	}

	while(large != 0)
	{
		ndig++;
		large = large/10;
	}

	return(ndig);
}


/*********************************************
Function to find index number of the Number.
*/
int FindIndex(int Number,int Index)
{
	int i, digit, addr;

	for(i=Index; i<=Index; i++)
	{
		digit = Number%10;
		Number /= 10 ;
	}

	addr = digit;

    return(addr);
}
