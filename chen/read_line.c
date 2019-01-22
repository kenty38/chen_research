
#include<stdio.h>

int main(void){
	FILE *fp;
	char fname[]="6_6.csv";
	int a[7];
	int chr;
	int i;
	
	fp=fopen(fname,"r");
	
	if(fp==NULL){
		printf("%s do not open\n",fname);
		return -1;
	}
/*	
	while(fscanf(fp,"%d,%d,%d,%d,%d,%d,%d",
				&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]) != EOF){
		printf("%2d,%d,%d,%d,%d,%d,%d\n",
				a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
	}
*/
	i=0;
	while((chr = fgetc(fp))!=EOF){
		if(chr == '\n'){
			puts("");
			i=0;
		}
		else if(chr != ','){
			a[i]=chr-'0';
			printf("%d,",a[i]);
			i++;
		}
	}	
	fclose(fp);
	
	return 1;
}
