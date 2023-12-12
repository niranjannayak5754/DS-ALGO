/*
    *************** Next Permutation [Medium] ***************88

    Given an array. Find the next permutation of that arrays.
    This means, get the permutation of given arrays which is just greater than the original array. 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int pos = -1;
        for(int i = n -2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
    
        for(int i = n-1; i > pos; i--){
            if(nums[i] > nums[pos]){
                swap(nums[i], nums[pos]);
                break;
            }
        }

        reverse(nums.begin()+ pos + 1, nums.end());

    }
};

int main(){
    Solution obj;
    // vector<int> nums = {1,2,3};
    vector<int> nums {1, 4, 5, 18, 12, 6, 2, 1};

    obj.nextPermutation(nums);
    for(int val : nums)
        cout << val << " ";
    
    return 0;
}