/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 
Constraints:
1 <= m, n <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

// using recursion for all combinations of moves of a robot and reducing recursion using dynamic programming
int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
    if(i == m -1 && j == n -1) return 1;
    if (i>= m || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
}

int countPaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPaths(0, 0, m, n, dp);
}

// optimal solution using maths
int uniquePaths(int m, int n)
{
    int N = m + n - 2; // total no of directions a robot can take
    int r = m < n ? m - 1 : n - 1; // total ways of moving down (or right)
    double res = 1; // res will be combinations of directions and ways of moving. For example N choose r  = N! / ((N-r)!. r!)
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}



int main()
{
    int m = 3;
    int n = 21;
    cout << uniquePaths(m, n) << endl;
    cout << countPaths(m, n) << endl;
    return 0;
}