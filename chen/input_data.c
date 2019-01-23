#include"function.h"

/*行列の要素をコピーするための関数*/
void input_ingredient(int name[ONE_SIDE],int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]);

/*hubかauthorityかの情報を入れ、更に出次数と入次数を入力する関数*/
void decide_side_and_count_degree(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]);

/*出次数の隣接リストの生成*/
void make_out_list(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]);

/*入次数の隣接リストの生成*/
void make_in_list(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]);

void confirm_matrix(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]);
void confirm_side_and_list(struct Node_t nod[ONE_SIDE]);

/*-------------------------------------------------------------------------------*/


void input_data(struct Node_t nod[ONE_SIDE]){
	int matrix_number[ONE_SIDE]={1,2,3,5,6,10};
	int matrix_copy[ONE_SIDE][ONE_SIDE];
	
	input_ingredient(matrix_number,matrix_copy,nod);
	
	decide_side_and_count_degree(matrix_copy,nod);
	
	make_out_list(matrix_copy,nod);
	
	make_in_list(matrix_copy,nod);
	
	//confirm_side_and_list(nod);
	//confirm_matrix(matrix_copy,nod);
}


/*-------------------------------------------------------------------------------*/

void input_ingredient(int name[ONE_SIDE],int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]){
	FILE *fp;
	int ingredient;
	int i=0,j=0;
	
	fp=fopen(INPUT,"r");
	
	if(fp==NULL){
		printf("%s do not open\n",INPUT);
		exit(1);
	}
	
	for(i=0;i<ONE_SIDE;i++)
	  nod[i].node_number=name[i];
	
	i=0;
	while((ingredient = fgetc(fp))!=EOF){
		if(ingredient == '\n'){
			j=0;
			i++;
		}
		else if(ingredient != ','){
			matrix[i][j]=ingredient-'0';
			j++;
		}
	}
	
	fclose(fp);
}

void decide_side_and_count_degree(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]){
	int i=0,j=0;
	int total_in=0,total_out=0;
	
	for(i=0;i<ONE_SIDE;i++){
		total_out=0;
		total_in=0;
		
		for(j=0;j<ONE_SIDE;j++){
			if(matrix[i][j]==1)
					total_out++;
			if(matrix[j][i]==1)
					total_in++;
		}
		
		if(total_out==0)
			nod[i].belong_hub = NO;
		else
			nod[i].belong_hub = YES;
		
		if(total_in==0)
			nod[i].belong_authority = NO;
		else
			nod[i].belong_authority = YES;
			
		nod[i].out_number=total_out;
		nod[i].in_number=total_in;
	}
}

void make_out_list(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]){
	int i=0,j=0;
	int count=0;
	
	for(i=0;i<ONE_SIDE;i++){
		nod[i].out_list=malloc(sizeof (int) * nod[i].out_number);
		
		for(j=0;j<ONE_SIDE;j++){
			if(matrix[i][j]==1){
				nod[i].out_list[count]=nod[j].node_number;
				count++;
			}
			if(count == nod[i].out_number){
				count=0;
				break;
			}
		}
	}
}

void make_in_list(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]){
	int i=0,j=0;
	int count=0;
	
	for(i=0;i<ONE_SIDE;i++){
		nod[i].in_list=malloc(sizeof (int) * nod[i].out_number);
		
		for(j=0;j<ONE_SIDE;j++){
			if(matrix[j][i]==1){
				nod[i].in_list[count]=nod[j].node_number;
				count++;
			}
			if(count == nod[i].in_number){
				count=0;
				break;
			}
		//printf("i=%d,j=%d,count=%d\n",i,j,count);	
		}
	}
}



void confirm_side_and_list(struct Node_t nod[ONE_SIDE]){
	int i,j;
	
	puts("<out>");
	for(i=0;i<ONE_SIDE;i++){
		printf("%2d:",nod[i].node_number);
		for(j=0;j<nod[i].out_number;j++){
			printf("%d",nod[i].out_list[j]);
			if(j!=nod[i].out_number-1)
				printf(",");
		}
		puts("");
	}

	puts("<in>");
	for(i=0;i<ONE_SIDE;i++){
		printf("%2d:",nod[i].node_number);
		for(j=0;j<nod[i].in_number;j++){
			printf("%d",nod[i].in_list[j]);
			if(j!=nod[i].in_number-1)
				printf(",");
		}
		puts("");
	}
	
	for(i=0;i<ONE_SIDE;i++)
		printf("%2d:hub=%d , authority=%d , out_number=%d , in_number=%d\n",
						nod[i].node_number,nod[i].belong_hub,nod[i].belong_authority,
						nod[i].out_number,nod[i].in_number);
}

void confirm_matrix(int matrix[ONE_SIDE][ONE_SIDE],struct Node_t nod[ONE_SIDE]){
	int i,j;
	
	for(i=0;i<ONE_SIDE;i++){
		printf("%2d:",nod[i].node_number);
		for(j=0;j<ONE_SIDE;j++){
			printf("%d",matrix[i][j]);
			if(j!=ONE_SIDE-1)
				printf(",");
			else
			puts("");
		}
	}
}

