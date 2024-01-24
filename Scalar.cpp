#include<bits/stdc++.h>
using namespace std;

int m,n;


void min_sum(){
    vector<int> a, b;
    int x;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for(int  i = 0; i < n; i++){
        sum += a[i] * b[i];
    }
    cout << sum << "\n";
}

int main(){
    cin >> m;
    for(int  i = 0; i < m; i++){
        min_sum();
    }
    return 0;
}