/*
    *********** Largest Rectangle in Histogram [Hard] *************

    // intuition from next greater element

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
    return the area of the largest rectangle in the histogram.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int leftSmaller[n], rightSmaller[n];

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            leftSmaller[i] = st.empty() ? 0 : st.top() + 1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n -1 ; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            rightSmaller[i] = st.empty() ? n - 1 : st.top() - 1;

            st.push(i);
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        }

        return maxi;
    }
};