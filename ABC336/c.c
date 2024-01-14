#include <stdio.h>
#include <stdlib.h>
#define P 20

struct node{
	int digit;
	struct node *next;
};

typedef struct node nd;
typedef struct node* list;

void insert(list l, int d){
	list tmp = (nd*)malloc(sizeof(nd));
	tmp->ditit = d;
	tmp->next = l->n;
	l->n = tmp;
}
		

int main(){
	long long N, num;
	int flag = 0, d;
	list l = (list)malloc(sizeof(nd)); // head
	l->next = NULL;
	

	scanf("%lld",&N);
	// check if N = 5^x or not
	

	
	for(num = 1; N > 5; N = (N%5 == 0)? N/5: N/5+1){
		d = (N%5 == 0)? N/5: N/5+1;	// from lower digit, determine num (each digit = (num-1) *2)
		d = (d-1)%5;
		insert(l, d*2);
		num++;		// number of digits (nodes)
	}
	
	insert(l, (N-1)*2 );

	while(l != NULL) printf("%d",l->digit); 


}
