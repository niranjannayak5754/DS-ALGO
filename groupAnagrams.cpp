/*
    **** Group Anagrams [Medium] [Sorting] [Array] [Hashing] *****************

    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
    typically using all the original letters exactly once.

    

    Example 1:

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    Example 2:

    Input: strs = [""]
    Output: [[""]]
    Example 3:

    Input: strs = ["a"]
    Output: [["a"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        int i = 0;
        for(string word : strs){
            string temp = word;
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()){
                res[mp[temp]].push_back(word);
            } else{
                mp[temp] = i;
                res.push_back(vector<string>{word});
                i++;
            }
        }
        
        return res;
    }
};