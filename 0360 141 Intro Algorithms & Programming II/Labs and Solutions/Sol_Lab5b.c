#include<stdio.h>
#include<time.h>
#define SIZE 20

void FillArray ( int *array, int size );
void PrintArray ( int *array, int size );
void BubbleSort ( int *array, int size );
void Swap ( int *x, int *y );

int main()
{
	int NumList[SIZE];
	FillArray( NumList, SIZE );

	printf("Unsorted array:\n");
	PrintArray( NumList, SIZE );

	BubbleSort( NumList, SIZE );

	printf("Sorted array:\n");
	PrintArray( NumList, SIZE );

	return 0;
}

void FillArray ( int *array, int size )
{
	int i;

	srand(time(NULL));

	for(i = 0; i < size; i++)
		*(array + i) = rand() % 101;
}

void PrintArray ( int *array, int size )
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", *(array + i));

	printf("\n");
}

void BubbleSort ( int *array, int size )
{
	int i, j;

	for(i = 0; i < size; i++)
		for(j = 0; j < size - 1; j++)
			if(*(array+j) < *(array+j+1))
				Swap(array+j, array+j+1);
}

void Swap ( int *x, int *y )
{
	int temp = *x;
	*x = *y;
	*y = temp;
}