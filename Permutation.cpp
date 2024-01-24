#include<bits/stdc++.h>
using namespace std;

int n;
int x[21];
bool visited[21];

void printSolution(){
    for(int i = 1; i <= n; i++){
        cout<<x[i];
    }
    cout<<"\n";
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            x[k] = i;
            visited[i] = true;
            if(k == n){
                printSolution();
            }
            else{
                Try(k+1);
            }
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
    return 0;
}