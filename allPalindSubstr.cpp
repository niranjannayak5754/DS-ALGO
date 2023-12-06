/*
    ************* Palindromic Substrings [Medium] *********8
    Given a string s, return the number of palindromic substrings in it.

    A string is a palindrome when it reads the same backward as forward.

    A substring is a contiguous sequence of characters within the string.

    

    Example 1:

    Input: s = "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".
    Example 2:

    Input: s = "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    /*
        Approach : a a a b

        -> take first character and assume it as mid of sub str and move left and right and count palindromic substrings
        -> take 2 same elements at one time as mid and move left and right and count palindromic substrings

        Why 2?
        Because take 1 character as mid at one time will directly go to 3, 5, 7 and so on after each iteration. so leaves substrings of even lengths
        That's why taking 2 characters as mid at one time will go to 4, 6, 8, and so on after each iterations. so substrings of all lengths are covered.

    */
    int countPalindrome(string s, int l, int r){
        int count = 0;

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i< s.size(); i++){
            // counting all the odd substrings having i-th element as mid
            res += countPalindrome(s, i, i);
            
            // counting all the even substrings having (i)th and (i+1)th same element as mid
            res += countPalindrome(s, i, i+1);
        }

        return res;
    }
};