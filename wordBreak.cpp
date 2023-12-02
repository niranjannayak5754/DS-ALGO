/*
    Word Break [Medium]
    Give a string s and wordDict(list of words);
    Return if a string s can be formed from combinations of words in wordDict.
    A word in wordDict can be used multiple times.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkWordBreak(unordered_set<string> &word_set, string s, unordered_map<string, bool>& dp)
    {
        if(s.empty()) return true;
        if(dp.find(s) != dp.end()) return dp[s];
        string currWord;
        bool res;
        for (int i = 0; i < s.size(); i++)
        {
            currWord = s.substr(0, i + 1);
            if (word_set.find(currWord) == word_set.end())
                continue;
            dp[s] = checkWordBreak(word_set, s.substr(i + 1), dp);
            if (dp[s])
                return true;
        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = wordDict.size();
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> dp;
        return checkWordBreak(word_set, s, dp);
    }
};

int main()
{
    string s = "leetcode";
    // cout << s.substr(8, 8) << endl;
    vector<string> wordDict{"leet", "code"};
    Solution obj;
    cout << obj.wordBreak(s, wordDict) << endl;
    return 0;
}