#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<int> T[50];
bool conflict[50][50];
int x[50];
int load[20];
int res = 99999;

void input(){
    cin >> m >>n;
    for(int i = 0 ; i < m; i++){
        int k;
        cin >> k;
        for(int  j = 0; j < k ; j++){
            int c;
            cin >> c;
            T[c].push_back(i); // push teacher in the list of teacher for course c.
        }
    }
    int conf;
    int u,v;
    cin >> conf;
    for(int i = 0; i < 50; i ++){
        for(int  j = 0; j < 50; j++){
            conflict[i][j] = false;
        }
    }
    for(int  i = 0; i < conf; i++){
        cin>>u >> v;
        conflict[u][v] = true;
        conflict[v][u] = true;
    }
}

bool check(int t, int k){
    for(int i = 0; i <= k-1; i++){
        if(conflict[i][k] && x[i] == t){
            return false;
        }
    }
    return true;
}

void solution(){
    int maxload = 0;
    for(int  i = 0; i < m; i++ ){
        maxload = max(maxload, load[i]);
    }
    if(res > maxload) res = maxload;
}

void Try(int k){
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i];
        if(check(t, k)){
            x[k] = t;
            load[t] += 1;
            if(k == n) solution();
            else{
                if(load[t] < res){
                    Try(k+1);
                }
            }
            load[t] -= 1;
        }
    }
}

int main(){
    input();
    for(int i = 0; i < m ; i ++){
        load[i] = 0;
    }
    Try(1);
    cout << res;
    return 0;
}



