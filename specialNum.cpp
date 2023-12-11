/*
    ******** Special Num [ Easy ] ******************

Given an integer array sorted in non-decreasing order, 
there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Intuition:
        Whenever you have a sorted array, you should try to think how binary search could be applied to it. 
        In this approach, we will continue to take advantage of the fact that the input is sorted and
        use similar ideas from the previous approach.

        Let's continue thinking about the array being split into blocks of similar elements.
        The answer block has a length greater than n / 4, and thus it must overlap at
        least one of the following positions in the array:

        A quarter of the way through at index n / 4.
        Halfway through at index n / 2.
        Three-quarters of the way through at index 3n / 4.

        These elements are the possible candidates. Find their position
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int k = n/4;
        vector<int> candidates = {arr[n/4], arr[n/2], arr[3*n/4]};

        for(int candidate : candidates){
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if(right - left + 1 > k)
                return candidate;
        }

        return -1;
    }
};