#include <bits/stdc++.h>
using namespace std;

bool check(char c, int finishA, int finishB, int finishC){
    if (c  == 'A'){
        if (finishA == 2) {
            return false;   // if A was already checked
        } else if (finishB != 0 || finishC != 0){
            return false;   // if B or C is now being checked or was already checked
        } else {
            return true;    // if A was not checked or is now being checked
        }
    } else if (c == 'B'){
        if (finishB == 2){
            return false;   // if B was already checked
        } else if (finishC != 0 || finishA == 1){
            return false;   // if C is now being checked or was already checked, or A is now being checked
        } else {
            return true;    // if B was not checked or is now being checked
        }
    } else if (c == 'C'){
        if (finishC == 2){
            return false;   // if C was already checked
        } else if (finishA == 1 || finishB == 1){
            return false;   // if A is now being checked, B is now being checked
        } else {
            return true;    // if C was not checked or is now being checked
        }
    }
}


int main(){
    string s;
    cin >> s;
    int i = 0;
    int finishA = 0, finishB = 0, finishC = 0;
    // 0 : not checked yet, 1 : now checking, 2: already checked
    for(i = 0; i < s.size(); i++){
        if(s[i] == 'A' && check(s[i], finishA, finishB, finishC)){
            if (i != s.size() - 1){ // if not the last character
                finishA = 1;
            } else {
                finishA = 2;
            }
        } else if (s[i] == 'B' && check(s[i], finishA, finishB, finishC)){
            finishA = 2;
            if (i != s.size() - 1){ // if not the last character
                finishB = 1;
            } else {
                finishB = 2;
            }
        } else if (s[i] == 'C'){
            finishA = finishB = 2;
            if (i != s.size() - 1){ // if not the last character
                finishC = 1;
            } else {
                finishC = 2;
            }
        } else {
            cout << "debug" << finishA << finishB << finishC << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    if (finishA != 1 || finishB != 1 || finishC != 1){
        cout << "Yes" << endl;
    } else {
        cout << "debug" << finishA << finishB << finishC << endl;
        cout << "No" << endl;
    }
}