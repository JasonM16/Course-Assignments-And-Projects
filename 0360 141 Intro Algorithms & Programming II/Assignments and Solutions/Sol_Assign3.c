/****
    This program reads data from an input file,
    It identifies the data fields, extracts values
    from the data fields and calculates the
    value of a "concept" from other two concepts
    using the formula P = U * I.

    Written by: Quazi Rahman, Mar. 12, 2012.
    modified by: Quazi Rahman, Feb. 15, 2013
****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CalculateValue(char *str1, char *str2, float *value, char *concept);
float modifiy_data(float data, char *str);

int main()
{
    int prob_count, data_count, curr_prob;
    float value;
    char concept, buffer[20], str1[20], str2[20];

    scanf("%d", &prob_count);   	//read the number of problems to solve
    printf("\n");

	curr_prob = 0;
    while(curr_prob < prob_count)  	//solve each of the 'prob_count' problems
    {
        curr_prob++;
        printf("Problem #%d\n", curr_prob);

        data_count = 0;
        while(data_count < 2)   	//need two values to calculate the third one
        {
            scanf("%s", buffer); 	//read a word from the 'stdin'

            if(buffer[1] == '=') 	//found a data field
            {
                if(data_count < 1)
                    strcpy(str1, buffer);
                else
                    strcpy(str2, buffer);

                data_count++;
            }
        }

        CalculateValue(str1, str2, &value, &concept);

        if(concept == 'P')
            printf("P=%.2fW\n\n", value);
        if(concept == 'U')
            printf("U=%.2fV\n\n", value);
        if(concept == 'I')
            printf("I=%.2fA\n\n", value);
    }

    return 0;
}


//calculates the value and determines the concept
void CalculateValue(char* str1, char* str2, float* value, char* concept)
{
    float data1, data2;

    data1 = atof(str1+2);   	//we know where the values start, after '='.
    data2 = atof(str2+2);		//Extract data and convert from string to float

    data1 = modifiy_data(data1, str1);	//if any prefix is there
    data2 = modifiy_data(data2, str2);	//modify the values


    if(str1[0] == 'P')			//if the first data is for P,
    {
        if(str2[0] == 'U')		//and the second data is for U
            *concept = 'I';		//then we have to calculate I
        else //if(str2[0] == 'I'), otherwise,
            *concept = 'U';		//we have to calculate U

       *value = data1 / data2;	// x = P / y
    }

    else if(str1[0] == 'U')		//if the first data is for U,
    {
        if(str2[0] == 'P')		//and the second data is for P
        {
            *concept = 'I';		//then we have to calculate I
            *value = data2 / data1;	// I = P / U
        }
        else //if(str2[0] == 'I'), otherwise,
        {
            *concept = 'P';			//we have to calculate P
            *value = data1 * data2;	// P = U * I
        }
    }

    else //if(str1[0] == 'I'), if the first data is for I,
    {
        if(str2[0] == 'P')		// and the second data is for P
        {
            *concept = 'U';		//then we have to calculate U
            *value = data2 / data1;	// U = P / I
        }
        else //if(str2[0] == 'U'), otherwise,
        {
            *concept = 'P';		//we have to calculate P
            *value = data1 * data2;	// P = I * U
        }
    }

}

//modifies data according to the modifier
float modifiy_data(float data, char *str)
{
    if(strchr(str, 'm'))  //if the unit is 'mili'
        data /= 1000;

    else if(strchr(str, 'k')) //if the unit is 'kilo'
        data *= 1000;

    else if(strchr(str, 'M')) //if the unit is 'Mega'
        data *= 1000000;

    return data;
}