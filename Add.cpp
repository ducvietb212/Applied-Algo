#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    int x[20];
    int y[20];
    int res[22];
    cin >> a >>b;
    int i = 0;
    while(a > 0){
        x[i] = a % 10;
        a = a / 10;
        i ++;
    }
    i = 0;
    while(b > 0){
        y[i] = b % 10;
        b = b / 10;
        i ++;
    }
    for(int j = 0; j < 22; j++){
        res[j] = 0;
    }
    for(int j = 0; j < i; j++){
        res[j] += (x[j] + y[j]) % 10;
        res[j+1] += (x[j] + y[j]) / 10;
    }
    if(res[i] != 0) cout << res[i];
    for(int j = i-1; j >= 0; j--){
        cout <<res[j];
    }
    return 0;
}