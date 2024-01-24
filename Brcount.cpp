#include<bits/stdc++.h>
using namespace std;

bool check(string str){
    vector<char> stack;
    char c;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            stack.push_back(str[i]);
        }
        if(str[i] == ')'){
            c = stack.pop_back();
            if(c != '('){
                return false;
            }
        }
    }
    if(stack.size() > 0) return false;
    return true;
}

int main(){
    string str;
    cin >> str;
    cout << check(str);
    return 0;
}