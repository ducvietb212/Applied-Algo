#include<bits/stdc++.h>
using namespace std;

int n;
int x[20];
int occupied[400];

int conflict(int x, int k){
    int row_x = x/n + 1;
    int col_x = x%n + 1;
    int row_k = k/n + 1;
    int col_k = k%n + 1;
    if (row_x == row_k || col_x == col_k || abs(row_k - row_x) == abs(col_k - col_x)){
        return 1;
    } 
    else{
        return 0;
        }
}

int check_conflict(int i, int k, int x[20]){
    if(k == 0) return 0;
    for(int j = 1; j <= k; j++){
        if(conflict(i, x[j]) == 1){
            return 1;
        }
    }
    return 0;
}

void solution(){
    int queen = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int block = i * n + j;
            for(int k = 1; k <= n; k++){
                if(x[k] == block){
                    queen = 1;
                }
            }
            if(queen == 1){
                printf("Q ");
                queen = 0;
            }
            else{
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

bool check_solution(int x[20], int n){
    for(int i = 1; i < n ; i++ ){
        if(x[i] > x[i+1]) return false;
    }
    return true;
}

void Try(int k){
    for(int i = 0; i < n*n; i++){
        if(occupied[i] == -1 && check_conflict(i, k-1, x) == 0){
            x[k] = i;
            occupied[i] = 1;
            if(k == n){
                if(check_solution(x,n)){
                solution();
                }
            }
            else{
                Try(k+1);
            }
            occupied[i] = -1;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i <= n*n; i++){
        occupied[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        x[i] = 0;
    }
    Try(1);
    return 0;
}