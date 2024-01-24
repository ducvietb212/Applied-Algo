#include<bits/stdc++.h>
using namespace std;

int n;
int c[23][23];
int res = 99999;
int tmp = 0;
int x[11];
int cmin = 99999;
bool visited[11];

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            x[k] = i;
            visited[i] = true;
            tmp = tmp + c[x[k-1] + n][x[k]] + c[x[k]][x[k] + n];
            if(k == n){
                tmp = tmp + c[x[k] + n][0];
                if (tmp < res){
                    res = tmp;
                }
            }
            else{
                if((tmp + (2*n - 2*k +1) * cmin) < res){
                Try(k + 1);
                }
            }
            tmp = tmp - (c[x[k-1] + n][x[k]] + c[x[k]][x[k] + n]);
            if(k == n){
                tmp -= c[x[k] + n][0]; //Nhớ cập nhật cả bước cuối
            }
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> c[i][j];
            if(c[i][j] < cmin) cmin = c[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
    x[0] = -n;
    Try(1);
    cout << res<<"\n";
    //for(int i = 1; i <= n; i++){
      //  cout << x[i]<<" ";
    //}
    return 0;
}