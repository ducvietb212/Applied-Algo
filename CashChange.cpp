#include<bits/stdc++.h>
using namespace std;

int x; //Cash
int n;
int d[101];
int iMem[100000][10];

int MinCoin(int x, int i){
    if(x < 0) return 999999;
    if(x == 0) return 0;
    if(i == 0) return 999999;
    if(iMem[x][i] != -1){
        return iMem[x][i];
    }
    int res = 999999;
    res = min(res, 1 + MinCoin(x - d[i], i));
    res = min(res, MinCoin(x, i - 1));
    iMem[x][i] = res;
    return res;
}

int main(){
    cin >> n>> x;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    cout << MinCoin(x, n);
    return 0;
}
