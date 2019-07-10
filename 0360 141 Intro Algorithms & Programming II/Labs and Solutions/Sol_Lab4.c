/*
	Ans to Q1. 
	*salary = 200
	salary1 = 20000
	salary2 = 60000
	salary3 = 2008
*/

/* Ans Q2, Q3, Q4 */
#include<stdio.h>
#define SIZE 10
int *Largest(int *array, int size);
void Swap(int *x, int *y);
int main()
 {
	int i;
	int array[SIZE] = {1, 13, 2, 5, 10, 9, 15, 4, 6};
	int *ptrLargest = NULL, *ptrIndex = NULL;
	
	ptrIndex = array;
	printf("The original array is:\n");
	for( i = 0; i < SIZE; i++)
	{
		printf("%d ", *ptrIndex);
		ptrIndex++;
	}
	printf("\n");
	ptrIndex = NULL;
	
	ptrLargest = Largest( array, SIZE );
	printf("The largest element is %d\n", *ptrLargest);
	
	Swap(array, array+1);
	
	ptrIndex = array;
	printf("The modified array is:\n");
	for( i = 0; i < SIZE; i++)
	{
		printf("%d ", *ptrIndex);
		ptrIndex++;
	}
	printf("\n");
	ptrIndex = NULL;
	
	return 0;
 }
 
 int *Largest(int *array, int size)
 {
	int i, *ptrLargest;
	ptrLargest = array;
	for( i = 1; i < SIZE-1; i++)
	{
		if(*ptrLargest < *(array+i))
			ptrLargest = array+i;
	}
	return ptrLargest;
 }
 
 void Swap(int *x, int *y)
 {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
 }
 