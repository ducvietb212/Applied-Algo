#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, M;
    int a[20000];
    int sum ;
    int res = 0;
    cin >> n>>m >> M;
    for(int  i = 0; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            if( sum >= m && sum <= M){
                res ++;
            }
        }
    }
    cout << res;
    return 0;
}