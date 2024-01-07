#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, z;
    cin >> n;
    for(x = 0; x <= n; x++){
        for(y = 0; y <= n-x; y++){
            for(z = 0; z<= n-x-y; z++){
                cout << x << " " << y << " " << z << endl;
            }
        }
    }
}