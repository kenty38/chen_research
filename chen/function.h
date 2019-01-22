
#include<stdio.h>
#include<stdlib.h>

#define ONE_SIDE 6
#define FILENAME "6_6.csv"

/*グループ名 , 0:GLOBAL,1:LOCAL*/
enum group_name{
  MONO,
  MULTI,
  NOT
};

enum hub_or_authority{
  NO,
  YES
};

struct Node_t{
  int id;                     /*順番通り*/
	int node_number;						/*別ファイルで与える*/
  int belong_hub;            	/*hubかどうか*/
  int belong_authority;       /*authorityかどうか*/ 
  int authority_group_name;   /*authority内のグループ名*/
  int out_number;             /*自分の先にいる人の数*/
  int in_number;              /*自分が指されている数*/
  int *out_list;							/*自分の先の点のリスト*/
  int *in_list;								/*自分を指す点のリスト*/
};

struct group_total_number_t{
  int authority_total_node;
  int global_total_node;
  int global_group_in;
  int local_group_node;
  int local_group_in;
};


extern void input_data(struct Node_t nod[ONE_SIDE]);
extern void make_adlist(struct Node_t nod[ONE_SIDE]);
extern void decide_group(struct Node_t nod[ONE_SIDE]);
extern void count_total(void);
extern void calculate_authority(void);
extern void calculate_hub(void);
extern void output_data(void);
