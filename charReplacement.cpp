/*
    ************ Longest Repeating Character Replacement [Medium] [sliding window] ***************
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
    You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.



    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int max_freq(unordered_map<int, int> &mp)
    {
        // time complexity will be O(26) i.e. constant time O(1) since set can have maximum 26 elements
        int max_f = INT_MIN;

        for (auto &it : mp)
        {
            max_f = max(it.second, max_f);
        }

        return max_f;
    }

    // time complexity is 26.O(n) since it calculates max_freq for every character
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> mp;
        int res = 0, l = 0, r = 0;
        // sliding window technique
        while (r < s.size())
        {
            mp[s[r]]++;

            // windowLen = r - l + 1
            while (r - l + 1 - max_freq(mp) > k)
            {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};

class SolutionB
{
public:
    // time complexity is O(N) since it takes count of prev max_f
    // as res will only increase when new max_f will be found
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> mp;
        int res = 0, l = 0, r = 0;
        int max_f = INT_MIN;
        while (r < s.size())
        {
            mp[s[r]]++;
            max_f = max(max_f, mp[s[r]]);
            // windowLen = r - l + 1
            while (r - l + 1 - max_f > k)
            {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};