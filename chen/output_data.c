
#include"function.h"

void output_data(struct Node_t nod[ONE_SIDE]){
	int i;
	FILE *fp;

	fp=fopen(OUTPUT,"w");
 	if(fp==NULL){
 		printf("%s do not open\n",OUTPUT);
		exit(1);
 	}
 	
 	for(i=0;i<ONE_SIDE;i++){
 		fprintf(fp,"%.3f",nod[i].authority_value);
 		if(i!=(ONE_SIDE-1))
 			fprintf(fp,",");
 	}
}
