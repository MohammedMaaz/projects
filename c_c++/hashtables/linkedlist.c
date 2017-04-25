#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Struct link or node for both ordered and unordered linked lists
struct link
{
    int value; //integer value that a single link will hold
    struct link* pNext //each link contains the pointer(pNext) to the next link;
};
//Struct for both linked lists
struct list
{
    // list will keep track of it's own size in order to calculate the shortest and longest list
    int listSize;

    //list contains a pointer to it's first element
    struct link* pFirst;
};

struct link* insertUnordered(int value, struct list* _list, int* counter)
{
    if(_list == NULL) //if a null pointer has been sent
        return NULL; // then no need for insertion just return NULL;

    //create a new link
    struct link *newLink = malloc(sizeof(struct link));

	//new link's value should be the one that needs to be inserted
	newLink->value = value;

	/* Since it's unordered list so just insert the new link at the beginning */
	newLink->pNext = _list->pFirst; //new link will now be pointing to the previously first link
	_list->pFirst = newLink; //pFirst will now be pointing to the freshly inserted new link

	//increment listSize by 1
	_list->listSize += 1;

	//increment insertion steps counter by 1
	*counter += 1;

	// return a pointer to the front of	the list
	return _list->pFirst;
}

int searchUnordered(int value, struct list *_list, int *counter)
{
    if(_list == NULL) //if a null pointer has been sent
        return -1; // then no need for searching just return NULL;

    struct link* pCurrent = _list->pFirst; // searching starts at ‘first’
    int index = 0; //keep track of the searched item index

    while(pCurrent != NULL) //loop breaks when reaches to the end of list
    {
        // increase counter and index position by 1 for each iteration
        index += 1;
		*counter += 1;

        if (pCurrent->value == value) //if found
			return index; //return index position

        pCurrent = pCurrent->pNext; //update current pointer by it's next link
    }

    // value not found in entire list
	return -1;
}

struct link* insertOrdered(int value, struct list* _list, int* counter)
{
    if(_list == NULL) //if a null pointer has been sent
        return NULL; // then no need for insertion just return NULL;

    //create a new link
    struct link *newLink = malloc(sizeof(struct link));

	//new link's value should be the one that needs to be inserted
	newLink->value = value;

	//increment insertion steps counter by 1, because at least 1 step will always be taken
	*counter += 1;

	struct link* pPrevious = NULL; //start at first element and keep track of previous element/link
    struct link* pCurrent = _list->pFirst; //keep track of the current element iterated

    //traverse through the loop until end comes or the inserted data is less than the current item/link
    while(pCurrent != NULL && value > pCurrent->value)
    {
        pPrevious = pCurrent; //current will now become previous
        pCurrent = pCurrent->pNext;  //next element will now become current

        *counter += 1; //increment counter for every iteration
    }

    /* Appropriate place to insert new link found! time to insert it. */
    if(pPrevious==NULL) //at beginning of list?
        _list->pFirst = newLink; //just insert the new link at the beginning
    else //not at beginning
        pPrevious->pNext = newLink; //previous element will now point to new link

    newLink->pNext = pCurrent; //at last the new link will now point to pCurrent (the breaking point of loop)

    //increment listSize by 1
	_list->listSize += 1;

    // return a pointer to the front of	the list
    return _list->pFirst;
}

int searchOrdered(int value, struct list *_list, int *counter)
{
    if(_list == NULL) //if a null pointer has been sent
        return -1; // then no need for searching just return NULL;

    struct link* pCurrent = _list->pFirst; // searching starts at ‘first’
    int index = 0; //keep track of the searched item index

    //traverse through the loop until end comes or the inserted data is less than the current item/link
    while(pCurrent != NULL && value >= pCurrent->value)
    {
        // increase counter by 1
		*counter += 1;

		if (pCurrent->value == value) //if found
			return index; //return index position

        pCurrent = pCurrent->pNext; //update current link with next one, moving forward...

        //increase index position by 1 for each iteration
        index += 1;
    }

    // value not found in entire list
	return -1;
}

int getLongestList(struct list listArr[],int _size)
{
    int longest = listArr[0].listSize; //assume the first list to be longest

    for(int i=1; i<_size; ++i) //now start loop from index 1
    {
        if(listArr[i].listSize > longest) //if current list size > longest
            longest = listArr[i].listSize; //then update the longest
    }

    return longest; //return longest sized list;
}

int getShortestList(struct list listArr[],int _size)
{
    int shortest = listArr[0].listSize; //assume the first list to be longest

    for(int i=1; i<_size; ++i) //now start loop from index 1
    {
        if(listArr[i].listSize < shortest) //if current list size > longest
            shortest = listArr[i].listSize; //then update the longest
    }

    return shortest; //return longest sized list;
}

void deleteList(struct list *_list)
{
    // if _list is null then it's not a list!, so return
	if (_list == NULL)
        return;

    struct link* pCurrent = _list->pFirst; /*start at first link */
    struct link* pTemp; //A temporary buffer to hold current link
    while(pCurrent != NULL) //until end of list,
    {
        pTemp = pCurrent;    //save current link
        pCurrent = pCurrent->pNext;  //move to next link
        free(pTemp); //delete the saved current link
    }
}

void printList(struct list* _list) //only for debugging purposes
{
	// if list is null, return
	if (_list == NULL)
        return;

	struct link* pCurrent = _list->pFirst;
	int i = 0;

	// print each node in the list
	while (pCurrent != NULL)
	{
		printf("%d - %d\n", i, pCurrent->value);
		pCurrent = pCurrent->pNext;
		i++;
	}
}



