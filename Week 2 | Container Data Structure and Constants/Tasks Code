#include <stdio.h>  /* printf */
#include <stdlib.h> /* memory management */
#include <limits.h> /* INT_MAX */

struct stack
{
	int elements;
	char* pData;
};

void stack_init(struct stack* s)
{
	/* The values of stack variables are just some random numbers by 
	   default, so we must initialize them.	*/

	// 1. Initializing s.elements variable

	// 2. Initializing s.pData pointer
}

void stack_cleanUp(struct stack* s)
{
	/* While using dynamic memory allocation, all allocated pieces of 
	   memory must be released in order to avoid unwanted memory leakages. */

	// 1. Set the elements to 0

	// 2. Release pData and free the allocated memory

	// 3. Set the value of pData to NULL.
}

int stack_push(struct stack* s, char newElement)
{
	/* Append a new element at the end of s.pData:
   - Reallocate memory (original size + 1) using a temporary pointer;
   - Copy the original content of the s.pData to the previously 
     allocated memory segment;
   - Append the newElement to stack;
   - Free the original memory of the s.pData; 
   - Redirect the s.pData pointer to the temporary pointer 
     (to the memory segment allocated at the first step).
   */

	// Temporary pointer
	char *ptrTemp;
	// Loop variable
	int i;

	/* 1. If the number of elements in the stack is INT_MAX, the stack 
	      is full (otherwise - stack overflow) 
	      In this case return -1 */
	
	// 2. Allocate new memory block using temporary pointer.
	
	/* 3. Copy the original content pointed by s.pData to a newly 
	      allocated memory segment (pointed by ptrTemp) */
	
	// 4. Put the newElement to the end of the new memory segment

	// 5. If pData is not NULL free it 
	
	// 6. Redirect the s.pData pointer to the temporary pointer (to ptrTemp)
	
	/* 7. Increment the number of elements in the stack 
	      (since we have just added one more) */
	
	return 0;
}

int stack_pop(struct stack* s)
{
    /* 
	  - If the stack is not empty, get the last inserted element from the 
	    end of the array. 
	  - Reallocate memory (original size - 1) using a temporary pointer;
	  - Copy the original content of the s.pData to the previously allocated 
	    memory segment;
	  - Free the original memory of the s.pData.
	  - If the stack turns out to be empty, than set its variables as it is 
	    written in General conditions and constraints.
	*/

	
	// Temporary pointer and return value
	char *ptrTemp, value;
	// Loop variable
	int i;

	// 1. If the stack is empty, return -1
	
	// 2. Copy the last element of the array to the 'value' variable
	
	/* 3. Decrement s.elements, which denotes the number of elements in the stack 
	      (since we have just popped one) */
	

	if(s->elements) // 4a. If the array is not empty (stack is not empty)
	{
		// 4a1. Allocate memory segment considering the new (decreased) size of the stack
	
		// 4a2. Copy the stack content to the newly allocated memory segment
	
		// 4a3. Release the old memory segment (s.pData)
	
		// 4a4. Redirect the s.pData pointer to the temporary pointer (to ptrTemp)
	
	}
	else // 4b. If after pop operation the stack becomes empty
	{
		// 4b1. Free s.pData
	
		// 4b2. Set s.pData to NULL (according to General conditions and constraints) 
	
	}

	// 5. Return the 'value' variable
}

int stack_isEmpty(struct stack* s)
{
	/* If the stack is empty return non-zero. Otherwise return 0. */
	
}

int main(void)
{
	struct stack s;
	char i;
	
	printf("Initializing stack...\n");
	stack_init(&s);

	for(i='A';i<='Z';i++)
	{		
		printf("push: %c\n",i);
		// It is adviced to follow s.pData variable by debugger, 
		// entering the function and following the step-by-step execution.
		stack_push(&s,i);		
	}

	while(!stack_isEmpty(&s))
	{
		// It is adviced to follow s.pData variable by debugger, 
		// entering the function and following the step-by-step execution.
		printf("pop: %c\n",(char)stack_pop(&s));
	}

	// Here the stack is already empty: error (-1)
	printf("pop: %d\n",stack_pop(&s));
	
	printf("Cleaning up stack...\n");
	stack_cleanUp(&s);
	return 0;
}
