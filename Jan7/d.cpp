#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k = 1;
    cin >> n;
    // 高橋くん = 0、龍の1 ~ n-1番目のパーツは1 ~ n-1として、配列に格納
    int a[n][n];
    int x = (n-1)/2;
    int y = (n-1)/2;
    a[x][y] = 0; // 高橋くんの座標
    for(int i = 1; i < n*n; i++){
        a[x][y+1] = i;
        if(i <= k*k && i < (k*(k+1))){
            x++;
        } else if(i <= (k*(k+1)) && i < (k+1)*(k+1)){
            y++;
        } else if(i <= (k+1)*(k+1) && i < (k+1)*(k+2)){
            x--;
        } else if(i <= (k+1)*(k+2) && i < (k+2)*(k+2)){
            y--;
        }
        if(i == (k+2)*(k+2)-1){
            k ++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (a[i][j] == 0) cout << a[i][j] << " ";
            else cout << 'T';
        }
        cout << endl;
    }
}