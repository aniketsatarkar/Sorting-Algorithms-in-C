/* Type and structure definitions */
typedef struct node_t *node, node_t;
struct node_t { int v; node next; };
typedef struct { node head, tail; } slist;


/* Function Declarations */
void push(slist * , node );
node removehead(slist * );
void join(slist * , slist * );
void merge(slist * , slist * , int * );
int StrandSort(int * , int );


void push(slist *l, node e)
{
	if(!l->head)
        l->head = e;

	if(l->tail)
        l->tail->next = e;

	l->tail = e;
}

node removehead(slist *l)
{
	node e = l->head;
	if (e)
    {
		l->head = e->next;
		e->next = 0;
	}

	return e;
}

void join(slist *a, slist *b)
{
	push(a, b->head);
	a->tail = b->tail;
}

void merge(slist *a, slist *b, int *c_count)
{
	slist r = {0};
	while (a->head && b->head)
    {
		push(&r, removehead(a->head->v <= b->head->v ? a : b));
        *c_count += 1;
    }

	join(&r, ((a->head) ? a : b));
	*a = r;
	b->head = b->tail = 0;
}


/*******************************************
Strand sort using singly linked list.
*/
int StrandSort(int *nArrray, int ArraySize)
{
    int i;
    node e;
	node_t all[ArraySize];
    int ComplexityCount = 0;

	// array to list
	for (i = 0; i < ArraySize; i++)
    {
		all[i].v = nArrray[i];
		all[i].next = i < ArraySize-1 ? (all+i+1) : 0;
        ComplexityCount++;
    }

	slist list = {all, all + ArraySize- 1}, rem, strand = {0},  res = {0};

	for (e = 0; list.head; list = rem)
    {
		rem.head = rem.tail = 0;

		while ((e = removehead(&list)))
        {
			push((!strand.head || e->v >= strand.tail->v) ? &strand : &rem, e);
            ComplexityCount++;
        }

		merge(&res, &strand, &ComplexityCount);
        ComplexityCount++;
	}

	// list to array
	for (i = 0; res.head; i++, res.head = res.head->next)
    {
		nArrray[i] = res.head->v;
        ComplexityCount++;
    }

    return ComplexityCount;
}
