#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,k,a,b;
    int x[100000];
    int ans = 0;
    cin >> n>>k>>a>>b;
    for(int i = 0; i < n; i++){
        cin>> x[i];
    }
    int sum = 0;
    for(int i = 0; i <= k-1; i++){
        sum += x[i];
    }
    if(sum >= a && sum <= b){
        ans ++;
    }
    for(int i = 1; i < n-k+1 ; i++ ){
        sum = sum - x[i-1] + x[i + k -1];
        if(sum >= a && sum <= b){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}