/*
    No of Islands [Medium] [BFS or DFS]

    Find the no of islands surrounded by water where 
    islands can be connected from all 8 directions to each other.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
private:
    void bfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int drow = -1; drow <= 1; drow++)
                for (int dcol = -1; dcol <= 1; dcol++)
                {
                    int nrow = r + drow;
                    int ncol = c + dcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && (!vis[nrow][ncol]))
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(i, j, n, m, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<char>> grid {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution obj;
    cout << obj.numIslands(grid)<< endl;
    return 0;
}