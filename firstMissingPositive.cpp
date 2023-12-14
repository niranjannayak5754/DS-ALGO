/*
    ******** First Missing Positive [ Hard ] *******************8
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// intuition: answer set lies in 1 to n for given array.
// if doesn't exist it's n + 1;
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        // mark all negatives to 0
        for(int i=0; i< n; i++){
            if(nums[i] < 0)
                nums[i] = 0;
        }

        // start negative marking indexes of all possible answer i.e 1 to n
        for(int i = 0; i< n; i++){
            // since the value may have been made negative at this index
            int val = abs(nums[i]);
            if(val >= 1 && val <= n){
                if(nums[val - 1] > 0)
                    nums[val-1] *= -1;
                else if(nums[val - 1] == 0)
                    nums[val - 1] = -1 * (n+1); // it's out of bound value
                // do nothing if val is already marked negative. 
                // that means it's duplicate
            }
        }

        for(int i = 1; i <= n; i++){
            if(nums[i - 1] >= 0)
                return i;
        }

        return n + 1;
    }
};