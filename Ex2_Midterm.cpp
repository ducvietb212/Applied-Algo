#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[100000];
    int max = -99999;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        //if (a[i] > max) max = a[i];
    }
    sort(a, a+n);
    string cmd;
    while(1){
        cin>>cmd;
        if(cmd.compare("insert") == 0){
            cin >> x;
            int  i = 0;
            while(x > a[i]){
                i ++;
            }
            for(int j = n-1; j >= i; j--){
                a[j+1] = a[j];
            }
            a[i] = x;
            n ++;
        }
        if(cmd.compare("delete-max") == 0){
            cout << a[n-1]<<endl;
            n --;
        }
        if(cmd.compare("*") == 0){
            break;
        }
    }
    return 0;
}