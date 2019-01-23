
#include"function.h"

void count_total(struct Node_t nod[ONE_SIDE],struct group_total_number_t *gtn){
	int i;	
	
	(*gtn).authority_total_node=0;
  (*gtn).multi_node=0;
  (*gtn).multi_in=0;
  (*gtn).mono_node=0;
  (*gtn).mono_in=0;	
 	
 	for(i=0;i<ONE_SIDE;i++){
 		if(nod[i].belong_authority==NO)
 			continue;
 		
 		(*gtn).authority_total_node++;	
 		if(nod[i].authority_group_name==MULTI){
 			(*gtn).multi_node++;
 			(*gtn).multi_in+=nod[i].in_number;
 		}
 		else{
 			(*gtn).mono_node++;
 			(*gtn).mono_in+=nod[i].in_number;
 		}	
 	}
}
