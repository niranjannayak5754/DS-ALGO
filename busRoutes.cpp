/*
    ************* Bus Routes [Hard] [BFS] [Graph] *************
    You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7],
    this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
    You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target.
    You can travel between bus stops by buses only.
    Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

    Example 1:
    Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
    Output: 2
    Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

    Example 2:
    Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
    Output: -1

    Constraints:
    1 <= routes.length <= 500.
    1 <= routes[i].length <= 105
    All the values of routes[i] are unique.
    sum(routes[i].length) <= 105
    0 <= routes[i][j] < 106
    0 <= source, target < 106
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, vector<int>> bStopToBIds;
        for (int i = 0; i < routes.size(); i++)
        {
            int bId = i;
            vector<int> bStops = routes[i];
            for (auto bStop : bStops)
                bStopToBIds[bStop].push_back(bId);
        }
        queue<pair<int, int>> q;
        unordered_map<int, bool> bVis, bStopVis;
        q.push({source, 0});
        bStopVis[source] = true;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> p = q.front();
                q.pop();

                int currStop = p.first;
                int busTravelled = p.second;
                if (currStop == target)
                    return busTravelled;
                for (auto bus : bStopToBIds[currStop])
                {
                    if (bVis[bus])
                        continue;
                    bVis[bus] = true;
                    for (auto busStop : routes[bus])
                    {
                        if (bStopVis[busStop])
                            continue;
                        bStopVis[busStop] = true;
                        q.push({busStop, busTravelled + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> routes1
    {
        {1, 2, 7},
        {
            3, 6, 7
        }
    };
    int source1 = 1;
    int target1 = 6;
    vector<vector<int>> routes2{
        {24},
        {3, 6, 11, 14, 22},
        {1, 23, 24},
        {0, 6, 14},
        {1, 3, 8, 11, 20}};
    int source2 = 20;
    int target2 = 8;
    Solution obj;
    cout << obj.numBusesToDestination(routes1, source1, target1) << endl;
    cout << obj.numBusesToDestination(routes2, source2, target2) << endl;
    return 0;
}