#include<bits/stdc++.h>
using namespace std;

vector<bool> visited(100001, false);
vector<int> adj[100001];
queue<int> q;
vector<int> res;
int n,m;

void bfs(int start){
    q.push(start);
    visited[start] = true;
    res.push_back(start);
    while(!q.empty()){
        int u = q.front();
        q.pop(); 
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!visited[v]){
            visited[v] = true;
            q.push(v);
            res.push_back(v);
            }
        }
    }
}

int main(){
    int u,v;
    cin >>n >>m;
    for(int i = 0; i < m; i++){
        cin >> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] <<" ";
    }
    return 0;
}