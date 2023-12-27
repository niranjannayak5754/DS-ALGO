/*
    WildCard Matching of String and Pattern

    pattern can have "." or "*"
    "." -> matches with any single character
    "*" -> matches with 0 or more length of subsequence characters

    For eg: pattern = ab*cd and string = abdefcd returns true.
    Since * matches the subsequence def with length 3

    pattern = "***" and string = "" return true
    since * matches with 0 chars (nothing)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkMatch(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '.')
        {
            return dp[i][j] = checkMatch(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*')
        {
            return dp[i][j] = checkMatch(i, j - 1, s, p, dp) | checkMatch(i - 1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return checkMatch(s.size() - 1, p.size() - 1, s, p, dp);
    }
};

class Tabulation
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case : considering 1-based indexing
        dp[0][0] = true;
        // all i > 0 for j = 0 are by default set to false

        // for j > 0 and i = 0
        for (int j = 1; j <= m; j++)
        {
            bool flag = true;
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        // copy the recursion and make it iterative
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i] == p[j] || p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*')
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
class TabulationOptimized
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1, false), curr(m+1, false);

        // base case : considering 1-based indexing
        prev[0] = true;
        // all i > 0 for j = 0 are by default set to false

        // for j > 0 and i = 0
        for (int j = 1; j <= m; j++)
        {
            bool flag = true;
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        // copy the recursion and make it iterative
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i] == p[j] || p[j] == '.')
                    curr[j] = prev[j - 1];
                else if (p[j] == '*')
                    curr[j] = curr[j - 1] | prev[j];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};

int main()
{
    Solution obj;
    cout << obj.isMatch("abdefcd", "ab*cd") << endl;

    Tabulation obj1;
    cout << obj1.isMatch("abdefcd", "ab*cd") << endl;

    TabulationOptimized obj2;
    cout << obj2.isMatch("abdefcd", "ab*cd") << endl;

    return 0;
}