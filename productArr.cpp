/*
    Product of Array Except Self
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
*/


// TITLE: Array and Prefix Sum
#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    int left_prod = 1, right_prod = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        result.push_back(left_prod);
        left_prod *= nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        result[i] *= right_prod;
        right_prod *= nums[i];
    }
        return result;    
}

int main(){
        vector<int> inputArr{-1, 1, 0, -3, 3};
        vector<int> result = productExceptSelf(inputArr);
        // Output: [24,12,8,6]
        for (int x : result)
        {
        cout << x << ",";
    }
    return 0;
}