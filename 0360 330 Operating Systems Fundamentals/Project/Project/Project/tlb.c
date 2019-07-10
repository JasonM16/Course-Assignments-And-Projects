



#include "Addresses.h"
#include "Constants.h"
#include "tlb.h"
#include "Function_Prototypes.h"




int main(int argc, char *argv[])
{	
	tlb_t my_tlb;
	page_t page_num = 10;
	frame_t frame_num = 3;

	init_tlb(&my_tlb);
	diplay_tlb(my_tlb);

	return 0;
}


int initialize_tlb(tlb_t *tlb)
{
	for (int i = 0; i < TLB_SIZE; i++)
		tlb->tlb_entry[i].valid = FALSE;
	return 0;
}


int diplay_tlb(tlb_t tlb)
{
	for (int i = 0; i < TLB_SIZE; i++)
	{
		printf("TLB entry %d, page number: %d, frame number: %d, ", i,
			tlb.tlb_entry[i].page_num,
			tlb.tlb_entry[i].frame_num);

		if (tlb.tlb_entry[i].valid == FALSE) printf("Invalid\n");
		else printf("Valid\n");
	}

	return 0;
}
