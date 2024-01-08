/*
	Daily Temperatures [Medium] [ Array ] [ Stack ] [ Next Greater Element ]
	
	Problem : Given temperatures array of size n. Get me the the no of days for next warmer day
		  If no warmer day is found in future, put 0.
	
	Return the array containing no of days for next warmer day to come for each days.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Intuition: Next Greater Element
    // instead of next greater element we put indexes to calculate the distance
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); // initially 0, stores distance between curr element and it's
        // next greater element
        stack<int> S;

        for(int i = n-1; i >= 0; i--){
            while(!S.empty() && temperatures[S.top()] <= temperatures[i])
                S.pop();
            // stack is empty means no greater element found so default 0 will be value
            if(!S.empty())
                res[i] = S.top() - i;
            
            S.push(i);
        }

        return res;
    }
};
