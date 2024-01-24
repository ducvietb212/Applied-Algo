#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int l1,l2;
int iMem[100000];

int mining(int j){// The sub sequence end at j
    int res = 0;
    if(iMem[j] != -1) return iMem[j];
    if(j <= l1){
        res = a[j];
        iMem[j] = res;
        return res;
    }
    if(j <= l2){
        for(int i = 1; i <= j-l1; i++){
            res = max(res, a[j] + mining(i));
        }
        iMem[j] = res;
    }
    for(int i = j - l2; i <= j-l1; i++){
        res = max(res, a[j] + mining(i));
    }
        iMem[j] = res;
    return res;
}

int main(){
    cin >>n>>l1>>l2;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        iMem[i] = -1; //Nhớ lưu kết quả
        
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans, mining(i));
    }
    cout << ans;
    return 0;
}