#define DEMO 0

void AesEncrypt(unsigned char *blk, unsigned char *key, int Nr);
static void AddRoundKey(unsigned char *col, unsigned char *key, int round);
static void SubBytes(unsigned char *col);
static void ShiftRows(unsigned char *col);
static void MixColumns(unsigned char *col);
static unsigned char xtime(unsigned char x);
unsigned char gmultiply(unsigned char a, unsigned char b);
unsigned char gmul_inverse(unsigned char in);
void rotate(unsigned char * in);
unsigned char rcon(unsigned char in);
unsigned char csbox(unsigned char in);
void schedule_core(unsigned char * in, unsigned char i);
void print_expand_key(unsigned char * in);
