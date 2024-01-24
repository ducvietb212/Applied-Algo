#include<bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int iMem[10000];

int MaxSum(int j){
    int res = -9999;
    if(j == 0){
        iMem[j] = a[j];
        return a[j];
    }
    if(iMem[j] != -1) return iMem[j];
    res = max(MaxSum(j-1) + a[j], a[j]);
    iMem[j] = res;
    return res;
}

int main(){
    cin >> n;
    for(int  i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++){
        iMem[i] = -1;
    }
    int ans = -9999;
    for(int i = 0; i < n; i++){
        ans = max(ans, MaxSum(i));
    }
    cout << ans;
    return 0;
}