/*
    Longest Increasing Subsequence (Medium)
    Given an integer array nums, return the length of the longest strictly increasing
    subsequence.

    Example 1:

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

    Example 2:

    Input: nums = [0,1,0,3,2,3]
    Output: 4

    Example 3:

    Input: nums = [7,7,7,7,7,7,7]
    Output: 1

    Constraints:
    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubsequenceLenght(vector<int>& nums){
    vector<int> temp{nums[0]};
    int l = 1;
    for (int i = 1; i< nums.size(); i++){
        int x = nums[i];
        if(x > temp.back()){
            temp.push_back(x);
            l++;
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
            temp[idx] = x;
        }
    }
    return l;
}
int main()
{
    // vector<int> input{10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> input{0,1,0,3,2,3};
    vector<int> input{7,7,7,7,7,7};
    int l = longestSubsequenceLenght(input);
    cout << l;
    return 0;
}