#include <stdio.h>
int main()
{
int a = 7;
int *aPtr;
aPtr = &a;

printf("%p\n", &a);			//The address of 'a'

printf("%p\n", aPtr);		//The value of 'aPtr', which is the memory address of 'a'

printf("%p\n", &aPtr);		//The memory address of 'aPtr'

printf("%d\n", a);			//The value of 'a'

printf("%d\n", *aPtr);		//The value at the location pointed by 'aPtr' (the value of 'a')

printf("%p\n", *&aPtr);		//The value at the memory address of 'aPtr' (the address of 'a')

printf("%p\n", &*aPtr);		//The the memory address of the location pointed by 'aPtr' (the address of 'a')

printf("%d\n", *&a);		//The value at the memory address of 'a' (the value of 'a')

//printf("%d\n", &*a);		//Illegal operation

return 0;
}