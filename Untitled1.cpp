#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10][10];
    int n,m;
    int x[10001];
    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    cin >> m;
    cin >> x[1];
    for(int i = 2; i <= m; i++){
        cin >> x[i];
        sum += a[x[i]][x[i-1]];
    }
    cout << sum;
    return 0;
}
