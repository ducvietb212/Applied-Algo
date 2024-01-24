#include<bits/stdc++.h>
using namespace std;

int n,m;
int x[10001], y[10001];
int mem[10001][10001];

int lcs(int i, int j){
    int res = -1;
    if(mem[i][j] != -1) return mem[i][j];
    if(i == 0 || j == 0){
        res = 0;
        mem[i][j] = res;
        return res;
    }
    if(x[i] == y[j]){
        res = max(res, lcs(i-1, j-1) + 1);
    }
    else{
        res = max(lcs(i-1, j), lcs(i, j-1));
    }
    mem[i][j] = res;
    return res;
}

int main(){
    cin >> n >>m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int j = 0; j < m; j++){
        cin >> y[j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mem[i][j] = -1;
        }
    }
    int ans = 0;
    cout << lcs(n-1,m-1);
    return 0;
}