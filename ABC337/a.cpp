#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, taka = 0, aoki = 0, x, y;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    taka += x;
    aoki += y;
  }
  
  if (taka > aoki){
    cout << "Takahashi" << endl;
  } else if (taka < aoki) {
    cout << "Aoki" << endl;
  } else {
    cout << "Draw" << endl;
  }
}