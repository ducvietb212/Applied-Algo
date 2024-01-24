#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 101;
int m,n,k;
int a[N][N];
bool visited[N][N];

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

int bfs(int sx, int sy) {
    int sizeLake = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (u > m || u < 1) continue;
            if (v > n || v < 1) continue;

            if (a[u][v] && !visited[u][v]) {
                ++sizeLake;
                visited[u][v] = true;
                q.push({u,v});
            }
        }
    }
    return sizeLake;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++) {
        fill_n(visited[i], n+1, false);
        fill_n(a[i], n+1, 0);
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    vector<int> res;
    int ans = 0;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j] && !visited[i][j])
                // cout << bfs(i,j) << " " << i <<" " << j<< endl;
                res.push_back(bfs(i,j));
    for (int i=0; i<res.size(); i++)
        ans = max(res[i], ans);
    cout << ans;
    return 0;
}