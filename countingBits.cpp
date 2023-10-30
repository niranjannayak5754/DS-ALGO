/*
    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
    ans[i] is the number of 1's in the binary representation of i.

    Example 1:
    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10

    Example 2:
    Input: n = 5
    Output: [0,1,1,2,1,2]
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> countBits(int n){
    vector<int> dp{0};
    // cnt -> count of set Bits
    for(int i = 1; i<= n; i++){
        int cnt = (i & 1) + dp[i/2];
        dp.push_back(cnt);
    }
    return dp;
}

int main(){
    int n = 5;
    vector<int> result = countBits(n);
    for(int val : result){
        cout << val << " ";
    }
}