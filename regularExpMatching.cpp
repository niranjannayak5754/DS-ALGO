/*
    Hard -> Regular Expression Matching
    "." -> matches any single character
    "*" -> matches zero or more of precedent character
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(const string &text, const string &pattern, int i, int j, unordered_map<string, bool> &mp)
    {
        if (j == pattern.length())
        {
            return i == text.length();
        }

        string key = to_string(i) + "," + to_string(j);
        if (mp.find(key) != mp.end())
            return mp[key];

        bool current_match = (i < text.length() && (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*')
        {
            return mp[key] = isMatch(text, pattern, i, j + 2, mp) || (current_match && isMatch(text, pattern, i + 1, j, mp));
        }
        else
        {
            return mp[key] = current_match && isMatch(text, pattern, i + 1, j + 1, mp);
        }
    }

    bool isMatch(const string &text, const string &pattern)
    {
        unordered_map<string, bool> mp;
        return isMatch(text, pattern, 0, 0, mp);
    }
};

class Tabulation
{
public:
    bool isMatch(const string &text, const string &pattern)
    {
        int n = text.size(), m = pattern.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // set the base case for 1-based indexing
        dp[0][0] = true;

        // Handle patterns with '*' at the beginning
        for (int j = 2; j <= n; j += 2) {
            if (pattern[j - 1] == '*' && dp[0][j - 2]) {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pattern[j - 1] == text[i - 1] || pattern[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (text[i - 1] == pattern[j - 2] || pattern[j - 2] == '.'));
                }
            }
        }

        return dp[n][m];
    }
};
