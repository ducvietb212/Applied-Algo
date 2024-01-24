#include<bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int m;
int iMem[10000][10000];
int i,j;
int sum = 0;

void rmq(){
    for(int i = 0; i < n ; i++){
        iMem[i][i] = a[i]; 
    }
    for(int  i = n-2; i >= 0; i --){
        for( int j = i+1; j < n; j++){
            iMem[i][j] = min(iMem[i+1][j], iMem[i][j-1]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    rmq();
    cin >> m;
    for(int k = 0; k < m ; k++){
        cin >>i>>j;
        sum += iMem[i][j];
    }
    cout << sum;
    return 0;
}
/*
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10
*/
