/*
    Longest Substring without repeating characters [Medium] [two pointer approach, map]
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int lenOfLongestSubString(string s){
    int n = s.size();
    vector<int> mp(256, -1); // there can be only 256 differenct characters in a string
    // alternatively we can initialize this map; vector<char> mp(n, -1)
    // vector<char> mp(n, -1);
    int left = 0, right = 0, len = 0;
    while(right < n){
        if(mp[s[right]] != -1){
            left = max(mp[s[right]]+1, left);
        }
        mp[s[right]] = right;
        len = max(len, right-left+1);
        right++;
    }
    return len;
}

int main(){
    string s = "abcabcbda";
    string b = "abcabcbb";
    cout << lenOfLongestSubString(s) << endl;
    cout << lenOfLongestSubString(b) << endl;
    return 0;
}