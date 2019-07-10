#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 256

/** Function Prototypes **/
void generate_key( int array[], int size );
void encrypt_data( char out[], const char in[], const int key[], int size );
void decrypt_data( char out[], const char in[], const int key[], int size );

int main() {

    char inputStr[SIZE];
    char encrypt[SIZE];
    char decrypt[SIZE];
    int key[SIZE];
    int i, size;

    printf( "Enter a string to encrypt: " );
    scanf( " %[^\n]s", inputStr ); //to scan a sentence from the keyboard

    size = strlen( inputStr );

    printf( "\nGenerating key...\n" );
    generate_key( key, size );

    printf("Key = ");
	for(i = 0; i < size; i++){
		printf("%d ", key[i]);
	}
	printf("\n");

    printf( "Encrypting string...\n" );
    encrypt_data( encrypt, inputStr, key, size );
	
	printf("Encrypted string is \"%s\"\n", encrypt);


    printf( "Decrypting string...\n" );
    decrypt_data( decrypt, encrypt, key, size );
	
	printf("Decrypted string is \"%s\"\n", decrypt);
    
return 0;
}




/** TODO: Documentations **/
void generate_key( int array[], int size ){
    
	srand( time( NULL ) );
	int i, j, temp, done;
	
	for(i = 0; i < size; i++){
		done = 0;
		while(!done){
			done = 1;
			temp = rand() % size;
			for(j = 0; j < i && done; j++){
				if(array[j] == temp)
					done = 0;
			}
		}
		array[i] = temp;
	}
}


/** TODO: Documentations **/
void encrypt_data( char out[], const char in[], const int key[], int size ){
    
	int i;
	for(i = 0; i < size; i++){
		out[i] = in[key[i]];
	}
}


/** TODO: Documentations **/
void decrypt_data( char out[], const char in[], const int key[], int size ){
    
	int i;
	for(i = 0; i < size; i++){
		out[key[i]] = in[i];
	}
}
