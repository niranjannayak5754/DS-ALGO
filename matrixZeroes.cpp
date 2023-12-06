
/*
    ********** SET MATRIX ZEROES [Medium] ********************

    Note ** traverse from last -> first so that non-zero element 
    which were latter set to zero won't affect while setting zeroes for columns
    i.e if we start from first, non-zeroes of 0th col will be set to 0 already 
    and arr[0][j] will affect while setting zeroes
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        bool flag = false;
        for(int i = 0;i< r;i++){
            if(arr[i][0]==0) flag = true;
            for(int j = 1;j<c;j++){
                if(arr[i][j]== 0)
                {
                    arr[i][0]  = 0;
                    arr[0][j] = 0;
                }
            }
        }
        
        for(int i = r-1;i>=0;i--)
        {
            for(int j =c-1;j>=1;j--){
                if(arr[i][0]==0 || arr[0][j]==0)
                    arr[i][j]= 0;
            }
            if(flag) arr[i][0] = 0;
        }
    }
};