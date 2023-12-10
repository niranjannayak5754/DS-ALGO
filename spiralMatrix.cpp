/*
 ******** Spiral Matrix [Medium] **************
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> res;

        while (left <= right && top <= bottom)
        {
            // move left to right at top
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            // move top to bottom at right
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // check if required to move or not at bottom
            if (top <= bottom)
            {
                // move right to left at bottom
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // check if required to move or not at left
            if (left <= right)
            {
                // move bottom to top at left
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};