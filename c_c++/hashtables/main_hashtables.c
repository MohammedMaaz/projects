#include "linkedlist.c"

int main()
{
    //Declare the array of 1000 int values
    int values[1000];


    srand(time(NULL)); //seed the random number generator
    //Randomly generate 1000 int values between 0 and 999,999 and place them into values[]
    for(int i=0; i<1000; ++i)
    {
        values[i] = rand()%1000000; //store random numbers in values[]
    }


    //main work goes here
    for(int j=0; j<3; ++j) //3 iterations for 3 different sizes of hash tables
    {
        int cInsU = 0, cInsO = 0, cSearchU = 0, cSearchO = 0; //initializing all counters
        int _size = 22+j; //initial size is 23, then 24, then 25

        //Declare 2 arrays of lists, lists1 is for unordered and lists2 is for ordered
        struct list lists1[_size], lists2[_size];

        //initializing all pointers in lists1 and lists2 to NULL and their sizes to 0
        for(int i=0; i<_size; ++i)
        {
            //for unordered
            lists1[i].pFirst = NULL;
            lists1[i].listSize = 0;

            //for ordered
            lists2[i].pFirst = NULL;
            lists2[i].listSize = 0;
        }

        //looping 1000 times to insert values[i] into hash table
		for (int i=0; i<1000; ++i)
        {
			// Inserting value into both lists using hash function, i.e value % arraysize
			insertUnordered(values[i], &lists1[values[i] % _size], &cInsU);
			insertOrdered(values[i], &lists2[values[i] % _size], &cInsO);
		}

		//looping 5000 times to search for different random numbers in hash table
		for (int i=0; i<5000; ++i)
		{
		    int searchVal; //value to search
		    int index = rand() % 1000; //random index for values[]

            if(i%3) // after every 3 iterations
                searchVal = rand()%1000000; //use a new random number b/w 0 to 999999
            else //other wise
                searchVal = values[index]; //use a random number from values[]

            // search searchVal in both lists through hash function
			searchUnordered(searchVal, &lists1[searchVal % _size], &cSearchU);
			searchOrdered(searchVal, &lists2[searchVal % _size], &cSearchO);
		}

		//print summary on the screen for each sized hash table
		printf("================================================\n");
		printf("For array size %d\n", _size+1);
		printf("Number of Operations (ordered lists)   : %d\n", cInsO+cSearchO); //insertions + searches
		printf("Number of Operations (unordered lists) : %d\n", cInsU+cSearchU); //insertions + searches
		printf("Longest list                           : %d\n", getLongestList(lists1,_size)); //get the longest list among all, since both ordered and unordered will have same size
		printf("Shortest list                          : %d\n", getShortestList(lists1,_size)); //get the shortest list among all, since both ordered and unordered will have same size
		printf("================================================\n\n");

        for(int i=0; i<_size; ++i)
        {
            deleteList(&lists1[i]);
            deleteList(&lists2[i]);
        }
    }

    return 0;
}
