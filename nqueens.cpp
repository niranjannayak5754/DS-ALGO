#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void solve(int col, vector<string>& board, 
        vector<bool>& leftRow, vector<bool>& lowerBoundary,
        vector<bool>& upperBoundary, int n, vector<vector<string>>& res
    ){
        // base case
        if(col == n)
            res.push_back(board);

        for(int row = 0; row < n; row++){
            if(leftRow[row] == false &&
                lowerBoundary[row + col] == false &&
                upperBoundary[n-1 + col - row] == false 
            ){
                // mark as placed a queen at this position
                board[row][col] = 'Q';
                leftRow[row] = true;
                lowerBoundary[row + col] = true;
                upperBoundary[n - 1 + col - row] = true;
                solve(col + 1, board, leftRow, 
                    lowerBoundary, upperBoundary, n, res
                );
                // backtrack i.e, remove the inserted queen for other possibilities
                board[row][col] = '.';
                leftRow[row] = false;
                lowerBoundary[row + col] = false;
                upperBoundary[n - 1 + col - row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n, s);

        vector<bool> leftRow(n, false);
        vector<bool> lowerBoundary(2*n-1, false), upperBoundary(2*n-1, false);

        solve(0, board, leftRow, lowerBoundary, upperBoundary, n, res);

        return res;
    }
};