#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *work_load; 
	int num;
}Employee;

int search(Employee *emp,int n);

int main(){
	int n,m,number,tmp,i=0;
	Employee *employee;

	scanf("%d %d", n,m);
		
	employee = (Employee*)malloc(sizeof(Employee)*n);

	while(n--;){
		int t=0;

		scanf("%d", number);
		employee[i].num = number;
		employee[i++].work_load = (int*)malloc(sizeof(int)*number);
		
		while(number--){
			scanf("%d", tmp);
			employee[i].work_load[t++] = tmp;
		}
	}
	search(employee);

	return 0;
}
int search(Employee *emp){
	

	return ;
}
