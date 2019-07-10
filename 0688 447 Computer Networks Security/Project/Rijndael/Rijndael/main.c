#include <stdio.h>
#include "prototypes.h"


int main(void)
{

#if DEMO
	/* Data from project demo for testing*/	
	unsigned char input[16] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
	unsigned char key[256]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };	
	char * sboxType = "original";
#else

	unsigned char input[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xd1 };
	unsigned char key[256]  = { 0x1a, 0x0c, 0x24, 0xf2, 0x87, 0x54, 0x93, 0xbc, 0xb7, 0x08, 0x0e, 0x43, 0x93, 0x0f, 0x56, 0x81 };
	char * sboxType = "modified";
#endif
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf("ID1 = 104 337 378  (Jason Choquette) \n");
	printf("ID2 = 103 385 550  (Yu Sheng Tian) \n");
	printf("Group Code (J, Y)= (3,7) \n\n\n");
	printf("Assigned Plaintext and Key:\n");
	printf("\t");
	for (int i = 0; i < 16; i++)
		printf("%02x ", input[i]);

	printf("\n\t");
	for (int i = 0; i < 16; i++)
		printf("%02x ", key[i]);

	printf("\n\n\n");
	printf("----------------------------------------------------------\n");
	printf("Key Schedule Results for Each Round with the %s AES:\n", sboxType);
	printf("----------------------------------------------------------\n");
	
	print_expand_key(key);

	printf("\n\n");
	printf("----------------------------------------------------------\n");
	printf("Data Results for Each Round with the %s AES:\n", sboxType);
	printf("----------------------------------------------------------\n");

	AesEncrypt(input, key, 10);	

	getchar();	
	return 0;
}

