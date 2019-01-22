
#include"function.h"

/*----------------<<main>>-----------------*/
int main(void){
  
  int i;
  struct Node_t node[ONE_SIDE];
  
  input_data(node);
  
  decide_group(node);
  
  for(i=0;i<ONE_SIDE;i++)
      printf("%d:authority_group=%d\n",node[i].node_number , node[i].authority_group_name);
 /* 
  count_total();
  
  calculate_authority();
  
  calculate_hub();
  
  output_data();
 */ 
  return 0;
}


/*----------------<<function>>-----------------*/


