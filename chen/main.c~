
#include"function.h"

void display(struct Node_t nod[ONE_SIDE],struct group_total_number_t gtn);

/*----------------<<main>>-----------------*/
int main(void){
  
  int i;
  FILE *fp;
	struct group_total_number_t total;
  struct Node_t node[ONE_SIDE];
  
  input_data(node);
  
  decide_group(node);
 
  count_total(node,&total);
  
  calculate_authority(node,total);
 	
 	display(node,total);
 	
 	output_data(node);
/*  
  calculate_hub();
  
  output_data();
 */ 
  return 0;
}


/*----------------<<function>>-----------------*/

void display(struct Node_t nod[ONE_SIDE],struct group_total_number_t gtn){
	int i;
	
	for(i=0;i<ONE_SIDE;i++)
      printf("%d:authority_group=%d\n",nod[i].node_number , nod[i].authority_group_name);

	puts("<total>");
 	printf("authority_total_node=%2d\nmulti_node=%2d\nmulti_in=%2d\nmono_node=%2d\nmono_in=%2d\n",
 					gtn.authority_total_node,gtn.multi_node,gtn.multi_in,gtn.mono_node,gtn.mono_in);
 					
 	for(i=0;i<ONE_SIDE;i++)
 		printf("%2d_authority_value:%f\n",nod[i].node_number,nod[i].authority_value);
 	
}
