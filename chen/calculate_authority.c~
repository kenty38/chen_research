
#include"function.h"

void calculate_authority(struct Node_t nod[ONE_SIDE],struct group_total_number_t gtn){
 	int i;
 	
 	for(i=0;i<ONE_SIDE;i++){
 		nod[i].authority_value=0;
 		
 		if(nod[i].belong_authority==NO)
 			continue;
 		else if(nod[i].authority_group_name==MULTI)
 			nod[i].authority_value=(double)(gtn.multi_node)/(gtn.authority_total_node) * (nod[i].in_number)/gtn.multi_in;
 		else
 			nod[i].authority_value=(double)(gtn.mono_node)/(gtn.authority_total_node) * (nod[i].in_number)/gtn.mono_in;
 	}

}
