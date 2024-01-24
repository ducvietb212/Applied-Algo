#include<bits/stdc++.h>
using namespace std;

int n,k;
int u,v;
vector<pair<int,int>> condition;
int drawed[5001];
vector<int> res;

int main(){
    cin >> n >>k;
    for(int i = 0; i < n; i++){
        drawed[i] = 0;
    }
    for(int i = 0; i < k; i++){
        cin >> u >> v;
        condition[i].first = u;
        condition[i].second = v;
        for(int i = condition[i].first; i <= condition[i].second; i++){
            drawed[i] = drawed[i] + 1;
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = i; j < k; j++){
            int ans = 0;
            for(int k = condition[i].first; k <= condition[i].second; k++){
                drawed[k] -= 1;
            }
            for(int k = condition[j].first; k <= condition[j].second; k++){
                drawed[k] -= 1;
            }
            for(int i = 0; i < n; i++){
                if(drawed[i] > 0){
                    ans += 1;
                }
            }
            res.push_back(ans);
            for(int k = condition[i].first; k <= condition[i].second; k++){
                drawed[k] += 1;
            }
            for(int k = condition[j].first; k <= condition[j].second; k++){
                drawed[k] += 1;
            }
        }
    }
    int final_ans = 0;
    for(int i = 0; i < res.size(); i++){
        if(res[i] > final_ans) final_ans = res[i];
    }
    cout << final_ans;
    return 0;
}