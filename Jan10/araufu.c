#include <stdio.h>
int main(){
    for(int i = 0; i < 100; i++){
        if(i%15 == 0) printf("araaraufufu");
        else if(i%3 == 0) printf("araara");
        else if(i%5 == 0) printf("ufufu");
        else printf("%d", i);
        putchar('\n');
    }
}
