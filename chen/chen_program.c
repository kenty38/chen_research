
#include"function.h"

/*----------------<<main>>-----------------*/
int main(void){
  struct Node_t node[ONE_SIDE];
/*  
  input_data();
  
  decide_group();
  
  count_total();
  
  calculate_authority();
  
  calculate_hub();
  
  output_data();
 */ 
  return 0;
}


/*----------------<<function>>-----------------*/
void input_data(struct Node_t nod[ONE_SIDE]){
	FILE *fp;
	int matrix_number[6]={1,2,3,5,6,10};
	int matrix_copy[ONE_SIDE][ONE_SIDE];
	int ingredient;
	int i=0,j=0;
	
	fp=fopen(fname,"r");
	
	if(fp==NULL){
		printf("%s do not open\n",fname);
		exit(1);
	}
	
	while((ingredient = fgetc(fp))!=EOF){
		if(ingredient == '\n'){
			puts("");
			j=0;
			i++;
		}
		else if(ingredient != ','){
			matrix_copy[i][j]=ingredient-'0';
			i++;
		}
	}
	
	for(i=0;i<ONE_SIDE;i++){
		printf("%2d:",matrix_number[i]);
		for(j=0;j<ONE_SIDE;j++){
			printf("%d",matrix_copy[i][j]);
			if(j!=ONE_SIDE-1)
				printf(",");
		}
	}
	fclose(fp);
	
}


