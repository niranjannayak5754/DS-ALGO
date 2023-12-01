/*
    Longest Palindromic Substring -> Medium
    Given a string s, return the longest palindromic substring in s.

    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Example 2:
    Input: s = "cbbd"
    Output: "bb"

    Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();

    // Create a table to store results of subproblems
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    int start = 0;     // Start index of the longest palindromic substring
    int maxLength = 1; // Length of the longest palindromic substring

    // Check for substring of length 2
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for substrings of length 3 and more
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1; // Ending index of the substring

            // Check if the substring is palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                dp[i][j] = true;

                // Update the longest palindromic substring
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, maxLength);
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    string r = "abbd";
    cout << longestPalindrome(r) << endl;
    return 0;
}