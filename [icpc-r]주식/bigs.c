#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int max;
	int cnt;
	long long profit;
	struct Node* next;
} Node;

void put(Node* head, Node* new){
	new->next = head->next;
	head->next = new;
}

int main(){

	int case_cnt;
	int i,j;
	scanf("%d", &case_cnt);
	for(i=0; i<case_cnt; i++){
		int days;
		scanf("%d", &days);
		
		Node bs_list = {0,0,0,NULL};
		int local_max;
		int local_cnt = 1;
		long long local_profit = 0;
		scanf("%d", &local_max);
		for(j=0; j<days; j++){
			int stock;
			if( j == days-1)
				stock = 0;
			else
				scanf("%d", &stock);
			
			if(stock >= local_max){
	            local_profit += (stock-local_max) * local_cnt;
	            local_max = stock;
	            local_cnt ++;
			}else{
				Node* pre_node = &bs_list;
				for(Node *node=bs_list.next; node;){
					if(node->max <= local_max){
						local_cnt += node->cnt;
						local_profit += node->profit + node->cnt*(local_max-node->max);
						pre_node->next = node->next;
						free(node);
						node = pre_node->next;
					}else{
						break;
					}
				}
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->max = local_max;
				new_node->cnt = local_cnt;
				new_node->profit = local_profit;
				put(&bs_list, new_node);
				local_cnt = 1;
				local_profit = 0;
				local_max = stock;
				
			}
		}
		long long profit_sum = 0;
		for(Node* node=bs_list.next; node;){
//			printf("%d, %lld\n", node->max, node->profit);
			profit_sum += node->profit;
			Node* tmp_node = node;
			node = node->next;
			free(tmp_node);
		}
		printf("%lld", profit_sum);
	}
}
