/*
    Duplicates in an array - [Medium] [Hashing] [Index Switching]
    Given an array of intergers of size n having elements [1, n].
    Each element apperas once or twice only.
    Find all the duplicates in the array

    Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [2,3]

    Example 2:
    Input: nums = [1,1,2]
    Output: [1]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(vector<int>& nums){
    int n = nums.size();
    vector<int> res;
    for(int curr : nums){
        int idx = abs(curr) - 1;
        if(nums[idx] < 0)
            res.push_back(abs(curr));
        else
            nums[idx] = -nums[idx];
    }
    return res;
}

int main(){
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> res = duplicates(nums);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}