/**
    Solution, Lab 3, 60-141, W, 2013.
    =================================
    This program handles some manipulations with
    2D array of any size, such as populating the array
    with  random numbers, search the
    array for a value, shift array elements, etc.

    Modified by: Quazi Rahman. Jan 2013
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 6 // number of columns
#define N 5 // number of rows
#define RANDMIN 15 //Minimum value of the random numbers
#define RANDMAX 75 //Maximum value of the random numbers

void PrintArray2D(int array[][N], int numRows, int numCols);
void PopulateRandom2D(int array[][N], int numRows, int numCols, int rmin, int rmax);
void LinearSearch2D(int array[][N], int numRows, int numCols, int numToFind);
void LeftShift2D(int array[][N], int numRows, int numCols);

int main () {

    int i, j;
    int intArray[M][N];     //original array
    int copyArray[M][N];    //a copy array
    int numToFind;

    //Populate the array with random integers
    PopulateRandom2D(intArray, M, N, RANDMIN, RANDMAX);

    //Print the array in a tabular format
    printf("Randomized array:\n");
    PrintArray2D(intArray, M, N);

    //Search the array for a number using linear search
    printf("Please enter a value to seach for: ");
    scanf("%d", &numToFind);
    LinearSearch2D(intArray, M, N, numToFind);

    //Copy the array to keep the original array intact
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            copyArray[i][j] = intArray[i][j];

    //Left shift the array
    LeftShift2D(copyArray, M, N);

    //Print the shifted array
    printf("Left shifted array:\n");
    PrintArray2D(copyArray, M, N);

    return 0;
}


/**
 * PopulateRandom2D:  Populates an array with random integers in the range rmin ... rmax
 * Input: The array to populate, the number of rows and columns to populate (starting top-left)
          and the range of the random numbers in terms of minimum and maximum.
 * Output: None
**/
void PopulateRandom2D(int array[][N], int numRows, int numCols, int rmin, int rmax) {
    int row, col;

    // seed the random number generator, so the numbers are different each time
    srand(time(NULL));

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            array[row][col] = rmin + rand() % (rmax - rmin + 1);
        }
    }
}


/**
 * PrintArray2D:  Prints the specified array in a tabular format
 * Input:  The array to print, the number of rows and columns to print (starting top-left)
 * Output: None
**/
void PrintArray2D(int array[][N], int numRows, int numCols) {
    int row, col;

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            printf("%10d", array[row][col]);
        }
        printf("\n"); //at the end of each row, start a new line
    }
    printf("\n"); // put a blank line between printouts, for readability
}


/**
 * LinearSearch2D:  Searches an array for the specified number, using linear search
 * Input:  The array to search, the number of rows and columns to search (starting top-left)
 * Output: No output
**/
void LinearSearch2D(int array[][N], int numRows, int numCols, int numToFind) {
    int row, col;
    int found = 0;

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            if (array[row][col] == numToFind) {
                printf ("Value %d was found at (%d,%d).\n", numToFind, row+1, col+1);
                found = 1;
            }
        }
    }

    if (!found)
        printf ("Value %d was not found.\n", numToFind);
}


/**
 * LeftShift2D:  Shifts each element one position to the 'left' (including up to the previous row)
 * and wraps the first element (top-left) into the last (bottom-right) position.
 * Input:   The array to shift, the number of rows and columns
 * Output:  returns void
**/
void LeftShift2D(int array[][N], int numRows, int numCols) {
    int firstValue;
    int row, col;

    // the first value has to move to the last position
    firstValue = array[0][0];

    // start shifting from the first row
    for (row = 0; row < numRows; row++) {

        // shift each column to the left, strating from the begining
        for (col = 0; col < numCols-1; col++) {
            //shift to the left
            array[row][col] = array[row][col+1];
        }

        //shift the first element of the next row
        //to the last position of this row
        //Skip this action for last row.
        if(row < numRows-1)
            array[row][numCols-1] = array[row+1][0];
    }

    // copy the old first value to the last position
    array[numRows-1][numCols-1] = firstValue;
}
