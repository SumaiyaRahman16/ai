#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    int i, j;
    for(i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    for(i=row,j=col;i>=0 && j<N;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if(row>=N) return true;
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col,N)){
            board[row][col]=1;
            if(solveNQueens(board,row+1,N)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main() {
    int N;
    cout<<"Enter the value of N: ";
    cin>>N;
    vector<vector<int>> board(N,vector<int>(N,0));

    if(solveNQueens(board,0,N)){
        cout<<"\nSolution for "<<N<<"-Queens:\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<". ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No solution exists for N = "<<N<<endl;
    }
    return 0;
}