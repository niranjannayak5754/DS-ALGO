#include <iostream>
#include <vector>

using namespace std;

// using binary search find the index of lower bound for given target value in a sorted array
// index = smallest index of element >= target value

// for upper bound, index = smallest index of element > target value
int upper_bound(vector<int>& nums, int target, int n){
    int low = 0, high = n-1, ans = n;
    while(low <= high){
        int mid = low + (high -low)/2;
        if(nums[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int lower_bound(vector<int>& nums, int target, int n){
    int low = 0, high = n-1, ans = n;
    while(low <= high){
        int mid = low + (high -low)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums{0,1,2,13,13, 13, 113,114};
    int target = 10;
    int lower_idx = lower_bound(nums, target, nums.size());
    cout << lower_idx;
    int upper_idx = upper_bound(nums, target, nums.size());
    cout << upper_idx;
    return 0;
}