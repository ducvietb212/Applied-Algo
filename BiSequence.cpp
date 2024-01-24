#include<bits/stdc++.h>
using namespace std;

int n;
int x[21];

void printSolution(){
    for(int i = 1; i <= n; i++){
        cout<<x[i];
    }
    cout<<"\n";
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        if(!(x[k-1] == 1 && i == 1)){
            x[k] = i;
        if(k == n){
            printSolution();
        }
        else{
            Try(k+1);
        }
    }
    }
}

int main(){
    cin >> n;
    Try(1);
    return 0;
}