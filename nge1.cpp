/*
	Next Greater Element 1 [ Easy ]
	
	nums1 is subset of nums
	get the next greater element of nums1 each value corresponding to those values in nums
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]] = i;
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(!st.empty())
                if(mp.find(nums[i]) != mp.end())
                    ans[mp[nums[i]]] = st.top();

            st.push(nums[i]);
        }

        return ans;
    }
};
