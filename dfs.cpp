/*
    Depth First Search
    It uses recursion

    Time Complexity = N + 2E
    Space Complexity = 3N
*/
#include <iostream>
#include <vector>
using namespace std;

int dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfs_search_algorithm(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> ls;
    dfs(0, adj, vis, ls);
    return ls;
}

int main()
{
    return 0;
}
