/*
	JUMP GAME II [ Medium ] 
	
	Given nums array of size n where nums[i] = no. of steps he can jump from i costing 1 jump
	Provided that starting from 0 you can always reach the (n-1)th position.
	
	Now, find the minimum no. of jumps required to reach (n-1)th position.
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            nums[i] = max(nums[i-1], nums[i] + i);
        }

        int jumps = 0;
        int idx = 0;

        while(idx < n - 1){
            idx = nums[idx];
            jumps++;
        }

        return jumps;
    }
};

int main(){
    vector<int> nums {2,3,1,1,2,5};
    Solution obj;
    cout << obj.jump(nums) << endl;
    return 0;
}
