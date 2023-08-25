/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// using 2sum method
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int target = -nums[i]; // since the total sum is 0 so x + y + z = 0 and y + z = -x (target)
        if(i> 0 && nums[i] == nums[i-1])
            continue; // skip duplicates
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[j] + nums[k];
            if(sum == target){
                result.push_back({nums[i], nums[j], nums[k]});
                while(j<k && nums[j] == nums[j+1])
                    j++; // skip duplicates
                while(j<k && nums[k] == nums[k-1])
                    k--; // skip duplicates
                j++;
                k--;
            }
            else if (sum < target){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return result;
}

int main(){
    Input:
    vector<int> nums {-1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = threeSum(nums);
    // Output: [[-1,-1,2],[-1,0,1]]
    for (vector<int> res : result){
        for (int x : res){
            cout << x << ",";
        }
        cout << endl;
    }
    return 0;
}