#include<bits/stdc++.h>
using namespace std;

int a[8] = {0, 100, 10, 2, -100, 1000, 100, 10};
int x[8];
int res = 0;
int ans = 0;
int n;

void Try(int k){
    for(int i = 1; i <= 9; i++){
        x[k] = i;
        res += x[k] * a[k];
        if(k == 7){
            if(res == n){
                ans ++;
            }
        }
        else{
            Try(k+1);
        }
        res -= x[k] * a[k];
    }
}

int main(){
    cin >> n;
    n = n + 62;
    Try(1);
    cout << ans;
    return 0;
}