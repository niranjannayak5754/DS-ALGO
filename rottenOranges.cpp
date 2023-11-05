/*
    Rotten Oranges Problem [Medium] [BFS]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i,j}, 0});   
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int cnt = 0, tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        return cnt == cntFresh ? tm : -1; 
    }
};

int main(){
    vector<vector<int>> grid {{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> grid {{0,1}};
    Solution obj;
    cout << obj.orangesRotting(grid) << endl;
}