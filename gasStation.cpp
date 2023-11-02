/*
    Gas Station:
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
    You have a car with an unlimited gas tank and
    it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
    You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index 
    if you can travel around the circuit once in the clockwise direction, otherwise return -1. 
    If there exists a solution, it is guaranteed to be unique
    
    Example 1:
    Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    Output: 3
*/

#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalDistance = 0, n = gas.size(), fuel = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = gas[i] - cost[i];
        totalDistance += diff;
        fuel += diff;
        if (fuel < 0)
        {
            idx = i + 1;
            fuel = 0;
        }
    }

    return totalDistance < 0 ? -1 : idx;
}

int main(){
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}