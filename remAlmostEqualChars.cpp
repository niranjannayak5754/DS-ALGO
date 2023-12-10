/*
    ********** Remove Adjacent Almost-Equal Characters [Medium] *******************
You are given a 0-indexed string word.

In one operation, you can pick any index i of word and change word[i] to any lowercase English letter.

Return the minimum number of operations needed to remove all adjacent almost-equal characters from word.

Two characters a and b are almost-equal if a == b or a and b are adjacent in the alphabet.

 

Example 1:

Input: word = "aaaaa"
Output: 2
Explanation: We can change word into "acaca" which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.
Example 2:

Input: word = "abddez"
Output: 2
Explanation: We can change word into "ybdoez" which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.
Example 3:

Input: word = "zyxyxyz"
Output: 3
Explanation: We can change word into "zaxaxaz" which does not have any adjacent almost-equal characters. 
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 3.
*/

#include<bits/stdc++.h>
using namespace std;


/*
    Intuition : 
        take first 3 characters. If there any char to replace it's mid so that it has no almost equal chars together 
        That implies for 3 characters, we need to changes 3/2 = 1 char

        Similary, if there are 4 characters, we might need to replace 2 chars either 1 or 3 or 2 or 4
        That implies 4/2 = 2 chars

        Now in loop we move forward and find the window in which we need to replace atmost chars
        Or we find window which have all almost common chars. 
        so that to replace chars will be size of window/2 i.e cnt/2;
*/
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int res = 0;
        int cnt;

        for(int i = 0;  i < word.size(); i++){
            cnt = 1;

            while(i + 1 < word.size() && abs(word[i+1] - word[i]) <= 1){
                cnt++;
                i++;
            }

            res += cnt/2;
        }

        return res;
    }
};