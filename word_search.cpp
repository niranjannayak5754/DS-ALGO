
/*
    Word Search [ Medium ] [Matrix | Backtracking | Array]

    Given an m x n grid of characters board and a string word, return true if word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cells, 
    where adjacent cells are horizontally or vertically neighboring.
    The same letter cell may not be used more than once.

    Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true

    Example 2:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    int size;
    bool is_valid(int x, int y, vector<vector<bool>>& vis) {
        return x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y];
    }
    bool backtrack(vector<vector<char>>& board, string word, int x, int y, int idx, vector<vector<bool>>& vis){
        if(idx == size) return true;

        if(!is_valid(x, y, vis)|| board[x][y] != word[idx]){
            return false;
        }

        vis[x][y] = true;

        // Check adjacent cells
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < 4; ++i) {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if (backtrack(board, word, new_x, new_y, idx + 1, vis)) {
                return true;
            }
        }

        // If the word is not found in the current path, mark the cell as unvisited
        vis[x][y] = false;

        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        size = word.size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i = 0; i<rows; i++ ){
            for(int j = 0; j < cols; j++){
                if(backtrack(board, word, i, j, 0, vis))
                    return true;
            }
        }
        return false;
    }
};