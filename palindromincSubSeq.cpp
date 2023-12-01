/*
    Longest Palindromic SubSequence -> Medium
    Given a string s, return the length of longest palindromic subsequence in s.

    Example 1:
    Input: s = "babad"
    Output: 3 -> because "bab" is longest palindromic subsequence
    Explanation: "aba" is also a valid answer.

    Example 2:
    Input: s = "cbbd"
    Output: 2 -> because of "bb"

    Example 3:
    Input: s = "babadab"
    Output: 5 -> because of "babab" is longest palindromic subsequence

    Constraints: 
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

string reverse_string(string s){
    int n = s.size();
    string t  = "";
    for(int i = n-1; i>=0; i--){
        t += s[i];
    }
    return t;
}

int longestPalindrome(string s)
{
    string t = reverse_string(s);
    // string z = s;
    // reverse(z.begin(), z.end());
    int res = longestCommonSubsequence(s, t);
    return res;
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    string r = "abbd";
    cout << longestPalindrome(r) << endl;
    string z = "babadab";
    cout << longestPalindrome(z) << endl;
    return 0;
}