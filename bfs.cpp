/*
    Breadth First Search in Graph

    Time Complexity : O(N) + O(2E)
    Space Complexity : O(3N)
*/
#include<iostream>
#include<vector
#include<queue>

using namespace std;

vector<int> bfs_search(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto i : adj[node]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(node);
            }
        }
    }
    return bfs;
}

int main(){
    return 0;
}