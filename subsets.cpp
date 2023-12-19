/*
    SubSets [Medium] [Bit Manipulation] [ Recursion ]
    Power Set

*/
#include<iostream>
#include<vector>

using namespace std;

class Recursion {
public:
    void backtrack(int idx, vector<int> &temp, vector<int>& nums, vector<vector<int>>& res){
        if(idx == nums.size()){
            res.push_back(temp);
            for(auto &it : temp)
                cout << it << " ";
            cout << endl;
            return;
        }
        
        temp.push_back(nums[idx]);
        backtrack(idx + 1, temp, nums, res);
        temp.pop_back();
        backtrack(idx+1,temp, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0, temp, nums, res);
        return res;
    }
};

class BitManipulation {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        // (i << n) == 2^n
        for(int i = 0; i < (1 << n); i++){
            // these are possibilities of subsets
            vector<int> temp;
            for(int j = 0; j < n; j++){
                // if it is set bit, add to the temp set
                if((i & (1 << j)) != 0){
                    temp.push_back(nums[j]);
                    cout << nums[j] << " ";
                }
            }
            cout << endl;
            res.push_back(temp);
        }

        return res;
    }
};

int main(){
    cout << "Recursion" << endl;
    Recursion obj;
    vector<int> nums{1,2,3};
    obj.subsets(nums);
    cout << "Bit Manipulation" << endl;
    BitManipulation obj1;
    obj1.subsets(nums);
    return 0;
}
