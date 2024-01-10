/*
    Majority Element [Medium] [Moore's Voting Algorithm]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int majorityElement(vector<int>& nums){
		int n = nums.size();

		if(n == 0) return -1;
		
		int count = 1;
		int candidate = nums[0];
		
		for(int i = 1; i < n; i++){
			if(nums[i] == candidate){
				count++;
			}
			else{
				if(--count < 0){
					candidate = nums[i];
					count = 1;
				};
			}
		}
		
		return candidate;
	}
};


int main(){
	vector<int> nums {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,4,5,2,1,1,2,2,2,3,3,3,3,33,4};
	Solution obj;
	cout << obj.majorityElement(nums) << endl;
	return 0;
}
