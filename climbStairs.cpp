/*
    Climbing Stairs
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Example 2:
    Input: n = 3
    Output: 3

*/

#include <bits/stdc++.h>
using namespace std;

int countStairs(int n, vector<int> &dp)
{
    if (n == 0 || n - 1 == 0 || n - 2 == 0)
        return n;
    if (dp[n] != -1){
        return dp[n];
    }
    return dp[n] = countStairs(n - 1, dp) + countStairs(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return countStairs(n, dp);
}

int main(){
    int n = 26;
    cout << climbStairs(n) << endl;
    return 0;
}