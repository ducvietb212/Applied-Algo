#include<bits/stdc++.h>

using namespace std;

int n, M;
int a[20], x[20], t[20];
int f;
int c;

void solution(){
    if(f == M){
        c++;
    }
}

void Try(int k){
    for(int  i = 1; i <= M - f - (t[n] - t[k])/a[k]; i++){
        x[k] = i;
        f += a[k] * x[k];
        if(k == n){
            solution();
        }
        else{
            Try(k+1);
        }
        f -= a[k] * x[k];
    }
}

int main(){
    cin >> n >>M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        t[i] = t[i-1] + a[i];
    }
    Try(1);
    cout<<c;
}