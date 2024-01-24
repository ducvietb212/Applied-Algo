#include<bits/stdc++.h>
using namespace std;

int n,k,m;
int a[21];
vector<int> x(k+1);
bool visited[21];
int sum;
set<vector<int>> res;


int sum_j(int j){
    if(j == 0){
        return 0;
    }
    int sum = 0;
    for(int  i = 1; i <= j; i++){
        sum += x[i];
    }
    return sum;
}

void Try(int j){
    for(int i = 1; i <= n; i++){
        if(a[i] <= m - sum_j(j-1) - (k-j) && !visited[i]){
            x[j] = a[i];
            sum += x[j];
            visited[i] = true;
        if(j == k){
            if(sum == m){
                res.insert(x);
            }
        }
        else{
            Try(j+1);
        }
        visited[i] = false;
        sum -= x[j];
        }
    }
}

void print_vector(vector<int> res){
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
}

int main(){
    cin >> n>>k>>m;
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
    
    for(int i = 0; i <= k; i++){
        x[i] = 0 ;
    }
    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    Try(1);
    cout << res.size();
    return 0;
}