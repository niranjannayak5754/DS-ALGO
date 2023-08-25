#include<bits/stdc++.h>
using namespace std;
// PROBLEM STATEMENT: TWO SUM ARRAY
vector<int> twoSum(vector<int>& nums, int target) {
    // hash map containing value and index as key:value pair
    map<int, int> h;
    h[nums[0]] = 0;
    for(int i=1;i<nums.size(); i++){
        if(h.find(target - nums[i]) != h.end()){
            return vector<int> {h[target-nums[i]], i};
        }
        else{
            h[nums[i]] = i;
        }
    }
    return vector<int> {0, 0};
}

int main(){
    vector<int> nums {2,7,11,15};
    int target = 17;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << "  ->  "<<result[1] << endl;
    return 0;
}