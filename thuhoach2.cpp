#include<bits/stdc++.h>
using namespace std;

int c,n;
int w[30];
int res = 0;
int x[30];
int ans = 0;

void Try(int k){
    for(int i = 0; i <= 1; i++){
        x[k] = i;
        res += x[k] * w[k];
        if(k == n){
            if(res > ans && res <= c){
                ans = res;
            }
        }
        else{
            Try(k+1);
        }
        res -= x[k] * w[k];
    }
}

int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    Try(1);
    cout << ans;
    return 0;
}