/*
    Move Zeroes [Easy] Using Two pointer approach

    Given interger array nums, move all 0's to the end of nums,
    maintaining the relative order of non zero elements

    Input : [0,1,0,3,12]
    Output : [1,3,12,0,0]
*/
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>&nums){
    int p1=0, i=0, n = nums.size();
    while(i<n){
        if(nums[i]==0){
            i++;
            continue;
        }
        swap(nums[i], nums[p1]);
        p1++;
        i++;
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int i: nums)
        cout << i << " ";
    return 0;
}