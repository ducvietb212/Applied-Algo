#include<bits/stdc++.h>

using namespace std;

int a[10001][10001];
bool visited[10001][10001];
int n,m,k;
int res = 0;
vector<int> res_list;
int max_res = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void find_bond(int x, int y){
     if(visited[x][y]) return;
     res += 1;
     visited[x][y] = true;
     for(int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        find_bond(new_x, new_y);
     }
     res_list.push_back(res);
     res = 0;
}

int main(){
    cin >> n>>m >>k;
    int u,v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = 0;
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < k; i++){
        cin >> u>>v;
        a[u][v] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                find_bond(i,j);
            }
        }
    }
    for(int i = 0; i < res_list.size(); i++){
        if(res_list[i] > max_res) max_res = res_list[i];
    }
    cout << max_res;
    return 0;
}
