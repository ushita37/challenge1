#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[300001] = {};
    cin >> n;
    for (int i = 1; i <= n ; i++){
        int tmp;
        cin >> tmp;
        if (tmp == -1){
            arr[0] = i;
        } else {
            arr[tmp] = i;   
        }
    }

    for (int i = 0; i <= n; i++){
        cout << arr[i];
        if (i != n){
            cout << " ";
        } else {
            cout << endl;
        }
    } 

    for (int i = 1; i <= n; i++){
        if (arr[i] == -1){
            while (arr[i] != 0){
                cout << i << " ";
                i = arr[i];
            }
        }
        cout << endl;
        break;
    }

}
