#include<bits/stdc++.h>
using namespace std;

int n;
int a[100001];
int res = 0;


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int  j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                res += 1;
            }
        }
    }
    cout << res;
    return 0;
}