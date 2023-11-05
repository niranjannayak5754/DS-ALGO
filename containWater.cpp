/*
    Container With Most Water

    You are given an integer array height of length n.
    There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:
    Input: height = [1,1]
    Output: 1

    Constraints:
    n == height.length
    2 <= n <= 10^5
    0 <= height[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

int maxArea_1(vector<int> &height)
{
    int n = height.size();
    int water;
    int maxwater = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++){
            water = min(height[i], height[j]) * (j-i);
            if (water > maxwater) maxwater = water;
        }
    }
    return maxwater;
}

int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int maxWater = 0;
    int water;
    while(l<r){
        water = min(height[l], height[r]) * (r-l);
        maxWater = max(water, maxWater);
        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxWater;
}


int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea_1(height) << endl;
    cout << maxArea(height) << endl;
    return 0;
}