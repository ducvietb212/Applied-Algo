#include<bits/stdc++.h>
using namespace std;

string str;
vector<char> res;
int k;

int sub(int start, int j){
    int max_index = start + 1;
    for(int i = start + 1; i <= str.size() - k + j; i++){
        if(str[i] > str[max_index]) max_index = i;
    }
    return max_index;
}


void skmin(){
    int max_index = 0;
    for(int i = 0; i < k; i++){
        max_index = sub(max_index, i);
        res.push_back(str[max_index]);
    }
}

int main(){
    cin >> str;
    cin >> k;
    skmin();
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
    }
    return 0;
}
