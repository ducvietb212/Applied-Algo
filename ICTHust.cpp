#include<bits/stdc++.h>
using namespace std;

int a[8] = {0, 100, 10, 2, -100, 1000, 100, 10};
int x[8];
int recent_sum = 0;
int n;
int res = 0;
int ans = 0;

int remain_sum(int k){
    int res = 0;
    for(int i = k+1; i <= 8; i++){
        res += a[i];
    }
    return res;
}

void Try(int k){
    int N = n + 62;
    for(int i = 1; i <= (N - recent_sum - remain_sum(k))/a[k]; i++){
        x[k] = i;
        res += x[k] * a[k];
        recent_sum += x[k] * a[k];
        if(k == 8){
            if(res == N){
                ans ++;
            }
        }
        else{
            Try(k+1);
        }
        res -= x[k] * a[k];
        recent_sum -= x[k] * a[k];
    }
}

int main(){
    cin >> n;
    Try(1);
    cout << ans;
    return 0;
}