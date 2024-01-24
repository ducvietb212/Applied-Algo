#include<bits/stdc++.h>
using namespace std;

int c;
int n;
int w[30];
int iMem[30];
int ans = 0;

int thuhoach(int i){
    if(i == 0){
        return 0;
    }
    /*
    if(i == 1){
        if(w[i] > c){
            return 0;
        }
        else{
            return w[i];
        }
    }
    */
    int res = 0;
    if(iMem[i] != -1){
        return iMem[i];
    }
    for(int j = 1; j < i; j++){
        if(thuhoach(j) + w[i] <= c){
            res = max(res, thuhoach(j) + w[i]);
        }
    }
    iMem[i] = res;
    return res;
}

int main(){
    cin >> n >> c;
    for(int  i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int  i = 0 ; i < 30; i++){
        iMem[i] = -1;
    }
    for(int  i = 1; i <= n; i++){
        ans = max(ans, thuhoach(i));
    }
    cout << ans;
    return 0;
}