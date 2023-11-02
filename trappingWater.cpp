/*
    Trapping Rain Water [Hard]
    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it can trap after raining.

    Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

    Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9

    Constraints:
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/
#include<bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    int l = 0, r = height.size() - 1, l_max = 0, r_max = 0, res = 0;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= l_max)
                l_max = height[l];
            else
                res += (l_max - height[l]);
            l++;
        }
        else
        {
            if (height[r] >= r_max)
                r_max = height[r];
            else
                res += (r_max - height[r]);
            r--;
        }
    }
    return res;
}

int main(){
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height) << endl;
    return 0;
}