#include<bits/stdc++.h>
using namespace std;

bool checkPhone(string s){
    if(s.length() != 10){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if(!(s[i] > '0' && s[i] < '9')){
            return false;
        }
    }
    return true;
}

int timeDuration(string s_time, string e_time){
    int t1, t2;
    t1 = ((s_time[0] - '0')*10 + (s_time[1] - '0')) * 3600 + ((s_time[3] - '0')*10 +(s_time[4] - '0'))*60 + ((s_time[6] - '0')*10 + (s_time[7] - '0'));
    t2 = ((e_time[0] - '0')*10 + (e_time[1] - '0')) * 3600 + ((e_time[3] - '0')*10 +(e_time[4] - '0'))*60 + ((e_time[6] - '0')*10 + (e_time[7] - '0'));
    return t2 - t1;
}

map<string, int> numberCalls;
map<string, int> timeCalls;
int main(){
    int total = 0;
    int incorrect_num = 0;
    string cmd;
    string f_num, t_num, date, s_time, e_time;
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        cin >> f_num >> t_num >> date >> s_time >> e_time;
        total += 1;
        if(!(checkPhone(f_num) && checkPhone(t_num))){
            incorrect_num += 1;
        }
        numberCalls[f_num] += 1;
        timeCalls[f_num] += timeDuration(s_time, e_time);
    }
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        if(cmd == "?check_phone_number"){
            if(incorrect_num == 0){
                cout<<1<<endl;
            }
            else{
                cout << 0<<endl;
            }
        }
        if(cmd == "?number_calls_from"){
            cin >>f_num;
            cout<<numberCalls[f_num]<<endl;
        }
        if(cmd == "?number_total_calls"){
            cout<<total<<endl;
        }
        if(cmd == "?count_time_calls_from"){
            cin >>f_num;
            cout<<timeCalls[f_num]<<endl;
        }
    }
    return 0;
}