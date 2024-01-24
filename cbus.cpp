#include<bits/stdc++.h>

using namespace std;
const int N = 15;
int n,k, c[N][N], res;
bool dd[N];
void Try(int u, int p, int s, int prev){
     if(u == 2*n){ // số lượng đỉnh đã đi qua = 2*n => Dừng đệ quy
        res = min(res, s + c[prev][0]);
        return;
     }
     for(int  i = 1; i <= 2*n; i++){
        if(dd[i] == true) continue; //Không xét lại những đỉnh đã đi qua
        if(p == k && i <= n) continue;// Nếu số người trên xe đầy, di đến điểm đón thêm người => không xét
        if(i <= n){ // Đón thêm người
            dd[i] = true;
            Try(u+1, p+1, s+ c[prev][i], i);
            dd[i] = false;
          }
        else{  // Trả người
            if(dd[i - n] == false) continue; // Nếu người thứ i không có trên xe, không xét
            dd[i] = true;
            Try(u+1, p-1, s+ c[prev][i], i);
            dd[i] = false;
        }
     }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i <= 2 *n; i++){
        for(int j = 0; j <= 2*n ; j++){
            cin >> c[i][j];
        }
    }
}
