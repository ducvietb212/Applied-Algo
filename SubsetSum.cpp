#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10000];
int sum;
int x[10000];
int cur_sum;

void solution(){
    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        x[k] = i;
        cur_sum += x[k] * arr[k];
        if(k == n){
            if(cur_sum == sum){
                solution();
                }
        }
        else{
            Try(k+1);
        } 
        cur_sum -= x[k] * arr[k];
    }
}

int main(){
    cin >> n >> sum;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    Try(1);
    return 0;
}
