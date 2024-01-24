#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> x[100001];
int mem[100001];

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

void solve(){
    sort(x+1, x+n, cmp);
    for(int i = 2; i <= n; i++){
        if(x[i].first > x[i-1].second){
            mem[i] = mem[i-1] + 1;
        }
        else{
            mem[i] = mem[i-1];
        }
    }
    cout << mem[n];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i].first >> x[i].second;
    }
    for(int i = 1; i <= n; i++){
        mem[i] = 1;
    }
    solve();
    return 0;
}