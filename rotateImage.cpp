/*
    ******* Rotate Image by 90 degree [Medium] *********************

    Rotating 90 degree
    step 1 : take the transpose of the matrix
    step 2 : reverse each rows of the transposed matrix

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // take the transpose of the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // swap elements across the diagonal
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row of the transposed matrix
        for(int i = 0; i < n; i++){
            int left = 0, right = n - 1;
            while(left < right){
                // swap elements across the vertical axis
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};