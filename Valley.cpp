#include<bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int rise_edge = 0;
int down_edge = 0;
int max_ans, min_ans;
vector<int> res;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = 0;
        while(a[i] < a[i+1] && i < n-1){
            rise_edge += 1;
            i ++;
        }
        if(rise_edge > 0){
            res.push_back(rise_edge);
            rise_edge = 0;
        } 
        while(a[i] > a[i+1] && i < n-1){
            down_edge -= 1;
            i ++;
        }
        if(down_edge < 0){
            res.push_back(down_edge);
            down_edge = 0;
        }
    /*
    for(auto x: res){
        cout << x <<" ";
    }
    cout<<"\n";
    */
    //cout <<"\n\n"<< res.size()<<"\n";
    for(int i = 0; i < res.size() - 1; i++){
        if(res[i] > res[i+1]){
            max_ans = max(max_ans, min(abs(res[i]), abs(res[i+1])));
        }
        else{
            min_ans = max(min_ans, min(abs(res[i]), abs(res[i+1])));
        }
    }
    cout << max_ans << "\n"<< min_ans;
    return 0;
}