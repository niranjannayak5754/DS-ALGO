/*
    ********** MINIMUM WINDOW SUBSTRING **************** [ Medium ] [ Sliding Window Technique ]

    Given strings s and t. Find the minimum window to get the substring of s which has all chars of t including the duplicates.

    Example: s = "abcdghfqrsa" and t = "fsa"
    Output = "fqrsa"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size() > n) 
            return "";

        unordered_map<char, int> mp;

        for(char ch : t){
            mp[ch]++;
        }

        int i = 0, j = 0;
        int reqCnt = t.size();

        int minWinSize = INT_MAX;
        int start_i = 0;
        
        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0)
                reqCnt--;

            mp[ch]--;

            while(reqCnt == 0){
                int currWinSize = j - i + 1;

                if(minWinSize > currWinSize){
                    minWinSize = currWinSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    reqCnt++;

                i++;
            }
            
            j++;
        }

        return minWinSize == INT_MAX ? "" : s.substr(start_i, minWinSize);
    }
};