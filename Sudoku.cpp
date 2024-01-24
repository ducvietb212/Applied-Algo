#include<bits/stdc++.h>
using namespace std;

#define N 9

int grid[N][N];

void solution()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num){
    for(int i = 0; i <= 8; i ++){
        if(grid[row][i] == num){
            return false;
        }
    }

    for(int i = 0; i <= 8; i ++){
        if(grid[i][col] == num){
            return false;
        }
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for(int i = start_row; i <= start_row + 2; i++){
        for(int j = start_col; j <= start_col + 2; j++){
            if(grid[i][j] == num){
                return false;
            }
        }
    }

    return true;
}

void Try(int k){
    int row = k/9;
    int col = k % 9;
    
    if(grid[row][col] > 0) Try(k+1);
    
    for(int i = 1; i <= 9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(k == N*N-1){
                solution();
                break;
            }
            else{
                Try(k+1);
            }
            grid[row][col] = 0;
        }
    }
}

int main(){
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    Try(0);
    return 0;
}