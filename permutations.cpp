#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& ds, vector<bool>& mp, vector<int>& nums){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!mp[i]){
                mp[i] = true;
                ds.push_back(nums[i]);
                backtrack(ans, ds, mp, nums);
                mp[i] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> mp(nums.size(), false);

        backtrack(ans, ds, mp, nums);

        return ans;
    }
};

class Swapping {
public:
    void backtrack(int index, vector<vector<int>>& ans, vector<int>& nums){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            backtrack(index + 1, ans, nums);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, ans, nums);
        return ans;
    }
};