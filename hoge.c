1 #include <stdio.h>
2 #include <stdlib.h>
3 #include <string.h>
4 char buf[128];
5
6 int main(void) {
7   fgets(buf, sizeof(buf), stdin); // 正規表現^\s+で、連続する空白も削除できる
8   printf("size: %d, %s",sizeof(buf), buf);
9   return 0;
10 }    // 正規表現^[\d]+で、2桁以上の数字を削除できる