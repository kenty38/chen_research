#include"function.h"

void decide_group(struct Node_t nod[ONE_SIDE]){
  int i,j;
  int opposite_hub_id;
  
  for(i=0;i<ONE_SIDE;i++){
    if(nod[i].belong_authority==NO){
      nod[i].authority_group_name=NOT;
      continue;
    }
    else if(nod[i].in_number>=2){
      nod[i].authority_group_name=MULTI;
      continue;
    }
    
    for(j=0;j<ONE_SIDE;j++){
      if(nod[j].node_number==nod[i].in_list[0]){
        opposite_hub_id=j;
        break;
      }
    }
    
    if(nod[opposite_hub_id].out_number==1)
      nod[i].authority_group_name=MONO;
    else
      nod[i].authority_group_name=MULTI;
  }
}  
  
