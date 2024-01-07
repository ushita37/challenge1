#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q, flag, ptr, p, x[1200001], y[1200001];   
    char c;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        x[n-i] = i;    // x座標, 配列の左側に龍の尾が、右側に龍の頭がある
        y[n-i] = 0;    // y座標
    }
    ptr = n-1; // 龍の頭に相当する配列のインデックス
    for(int k = 0; k < q; k++){ // クエリをq個処理する
        cin >> flag;
        if(flag == 1){
            cin >> c;
            // 龍の頭を移動させる
            if((char)c == 'L'){
                x[ptr+1] = x[ptr] -1;  // x座標を-1
                y[ptr+1] = y[ptr];     // y座標はそのまま
            } else if((char)c == 'R'){
                x[ptr+1] = x[ptr] +1;  // x座標を+1
                y[ptr+1] = y[ptr];     // y座標はそのまま
            } else if((char)c == 'U'){
                x[ptr+1] = x[ptr];     // x座標はそのまま
                y[ptr+1] = y[ptr] +1;  // y座標を+1
            } else if((char)c == 'D'){
                x[ptr+1] = x[ptr];     // x座標はそのまま
                y[ptr+1] = y[ptr] -1;  // y座標を-1
            } else {
                cout << "error1" << endl;
                return 1;
            }
            ptr++;

        } else if(flag == 2){
            cin >> p;
            // c番目の座標を求める
            cout << x[ptr+1-p] << " " << y[ptr+1-p] << endl;
        } else {
            cout << "error2" << endl;
            return 1;
        }
    }
}