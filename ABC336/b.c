#include <stdio.h>

int main(){
	int i = 0, N;
	scanf("%d",&N);
	for(;N > 1; N = N>>1){
		if(N%2 == 0) i++;
		else break;
	}
	printf("%d\n", i);
}
