#include<bits/stdc++.h>

using namespace std;

int n;
int a[100000];
int iMem[100000];

int lis(int i){
    int res = 1;
    if(iMem[i] != -1){
        return iMem[i];
    }
    for(int j = 1; j < i; j++){
        if(a[j] < a[i]){
            res = max(res, 1+lis(j));
        }
    }
    iMem[i] = res;
    return res;
}

int main(){
    
    cin >> n;
    for(int i = 0; i <= n; i++){
        iMem[i] = -1;
    }
    for(int  i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ans < lis(i)){
            ans = lis(i);
        }
    }
    cout << ans;
}