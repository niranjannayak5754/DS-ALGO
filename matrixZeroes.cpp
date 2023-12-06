
/*
    ********** SET MATRIX ZEROES [Medium] ********************88
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