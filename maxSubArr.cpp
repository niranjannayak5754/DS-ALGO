/*
    Maximum SubArray [Kadane's Algorithm]
    Given an integer array nums, find the subarray
    with the largest sum, and return its sum.

    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.

    Example 2:
    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.
*/
#include<bits/stdc++.h>

using namespace std;

// Kadane's Algorithm [0(n)]
int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN;
    int sum = 0;
    int idx = 0;
    int start, end;
    for (int i = 0; i < nums.size(); i++)
    {
        if(sum == 0) idx = i;
        sum += nums[i];
        if (sum > res){
            res = sum;
            start = idx;
            end = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout << start << " : " << end << endl;
    return res;
}

int find_common_sum(vector<int>&nums, int l, int m, int r){
    int left_max = INT_MIN, right_max = INT_MIN;
    int sum = 0;
    for(int i=m; i>=l; i--){
        sum += nums[i];
        if(sum > left_max) left_max = sum;
    }
    sum = 0;
    for(int i= m+1; i<=r; i++){
        sum += nums[i];
        if(sum > right_max) right_max = sum;
    }
    return left_max + right_max;
}

int divide_and_conquer(vector<int>&nums, int l, int r){
    
    if(l == r) return nums[l];
    int m = (l+r)/2;
    int left_sum = divide_and_conquer(nums, l, m);
    int right_sum = divide_and_conquer(nums, m+1, r);
    int common_sum = find_common_sum(nums,l, m, r);
    return max(max(left_sum, right_sum), common_sum);
}


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    cout << divide_and_conquer(nums, 0, nums.size() -1) << endl;
    return 0;

}