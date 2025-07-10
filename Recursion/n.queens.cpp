#include <bits/stdc++.h>
using namespace std;
/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9*/
class Solution {
    public:
        bool IsValid(vector<string> &board,int row,int col,int n){
            int temp_row = row;
            int temp_col = col;
            while(temp_row >= 0){
                if(board[temp_row][temp_col] == 'Q') return false;
                temp_row--;
            }
            temp_row = row;
            temp_col = col;
            while(temp_row >= 0 && temp_col >= 0){
                if(board[temp_row][temp_col] == 'Q') return false;
                temp_row--;
                temp_col--;
            }
            temp_row = row;
            temp_col = col;
            while(temp_row >= 0 && temp_col < n){
                if(board[temp_row][temp_col] == 'Q') return false;
                temp_row--;
                temp_col++;
            }
            return true;
    
        }
        void solve(int row,int n ,vector<string> &board,vector<vector<string>>&ans){ 
            if(row == n) {
                ans.push_back(board);
                return;
            }
            for(int i = 0 ; i < n ;i++){
                if(IsValid(board,row,i,n)){
                    board[row][i] = 'Q';
                    solve(row + 1,n,board,ans);
                    board[row][i] = '.';
                }
            }
            return;
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            vector<vector<string>> ans;
            solve(0,n,board,ans);
            return ans;
            
        }
    };
int main(){

}