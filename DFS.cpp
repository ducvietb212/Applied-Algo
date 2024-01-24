#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
//vector<bool> marked(100001, false);
vector<bool> visited(100001, false);
vector<int> res;

void dfs(int i){
        if(visited[i]) return;
        visited[i] = true;
        res.push_back(i);
        for(int j = 0; j < adj[i].size(); j++){
            dfs(adj[i][j]);
        }
}

int main(){
    int u,v;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin >>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 0; i < res.size(); i++){
        cout << res[i]<<" ";
    }
    /*
    cout<<"\n\n"<<res.size()<<"\n\n";
    for(int i = 0; i < adj[1].size(); i++){
        cout << adj[1][i]<<" ";
    }
    cout<<"\n\n";
    */
   return 0;
}