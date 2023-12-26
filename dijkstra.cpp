/*
    Dijkstra's Algorith -> Shortest Path in graph [ Medium ]
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    //  V -> no. of nodes
    // S -> source node
    vector<int> shortest_paths(int V, vector<vector<int>> adjList[], int S)
    {
        vector<int> dist(V, 1e8);
        // min heap of pairs of {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, S});
        dist[S] = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for (auto it : adjList[node])
            {
                int adjNode = it[0];
                int edgeDist = it[1];

                if (distance + edgeDist < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    vector<vector<int>> adjList[]{
        {{1, 4}, {2, 4}},                         // 0
        {{0, 4}, {2, 1}},                         // 1
        {{0, 4}, {1, 1}, {3, 3}, {4, 2}, {5, 6}}, // 2
        {{2, 3}, {5, 3}},                         // 3
        {{2, 2}, {5, 3}},                         // 4
        {{3, 2}, {4, 3}},                         // 5
    };

    Solution obj;
    vector<int> res = obj.shortest_paths(6, adjList, 0);
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}