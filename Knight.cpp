#include<bits/stdc++.h>
using namespace std;

int n;
int block[100][100];
int x,y;

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int isSafe(int x, int y, int block[100][100], int n) 
{ 
    return (x >= 0 && x < n && y >= 0 && y < n 
            && block[x][y] == -1); 
} 

void solution(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << block[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Try(int k){
    for(int i = 0; i < 8; i++){
        if(isSafe(x + xMove[i], y + yMove[i], block ,n)){
            x = x + xMove[i];
            y = y + yMove[i];
            block[x][y] = k;
            if(k == n*n - 1){
                solution();
                break;
            }
            else{
                Try(k+1);
            }
            block[x][y] = -1;
            x -= xMove[i];
            y -= yMove[i];
            }
    }
}

int main(){
    x = 0;
    y = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            block[i][j] = -1;
        }
    }
    block[0][0] = 0;
    Try(1);
    return 0;
}
