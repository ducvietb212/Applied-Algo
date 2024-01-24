#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int s0[100000];
int s1[100000];
bool b0[100000];
bool b1[100000];

void solve(){
    if(a[1] % 2 == 0){
        s0[1] = a[1];
        b0[1] = true;
        b1[1] = false;
    }
    else{
        s1[1] = a[1];
        b1[1] = true;
        b0[1] = false;
    }
    for(int i = 2; i <= n; i++){
        if(a[i] % 2 == 0){
            if(b0[i-1]){
                if(s0[i-1] > 0){
                    s0[i] = s0[i-1] + a[i];
                }
                else{
                    s0[i] = a[i];
                }
                b0[i] = true;
            }
            else{
                s0[i] = a[i];
                b0[i] = true;
            }
            if(b1[i-1]){
                s1[i] = s1[i-1] + a[i];
                b1[i] = true;
            }
            else{b1[i] = false;}
        }
        else{
            if(b1[i-1]){
                    s0[i] = s1[i-1] + a[i];
                    b0[i] = true;
            }
                else{
                    b0[i] = false;
                }
            if(b0[i-1]){
                if(s0[i-1] > 0){
                    s1[i] = s0[i-1] + a[i];
                }
                else{
                    s1[i] = a[i];
                }
                b1[i] = true;
            }
            else{
                s1[i] = a[i];
                b1[i] = true;
            }
        }
    }
    int ans = -99999;
    for(int i = 1; i <= n; i++){
        if(b0[i] && ans < s0[i]){
            ans = s0[i];
        }
    }
    cout << ans;
}

int main(){
    cin >> n;
    for(int  i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve();
    return 0;
}