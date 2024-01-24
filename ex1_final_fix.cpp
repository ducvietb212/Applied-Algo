#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1003;

int n, m;
int c[maxn][maxn];
int x[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    cin >> m;
    for (int i=1; i<=m; i++) 
        cin >> x[i];
    int res = 0;
    for (int i=2; i<=m; i++) 
        res += c[x[i-1]][x[i]];
    cout << res;
    return 0;
}
