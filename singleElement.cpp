/*
    Single Element

    Given non empty array of integers nums;
    Nums has every element twice except one element. Find that single element

    Example 1: 
    Input : [2,2,1]
    Output : 1
*/
#include<bits/stdc++.h>
using namespace std;

/*
    XOR operator Functionality:
    XOR with itself gives 0. i.e, X^X = 0
    XOR with 0 gives the number itself. i.e, X^0 = X
*/
int singleElement(vector<int>& nums){
    int res = 0;
    for(int i: nums){
        res = res ^ i;
    }
    return res;
}

int main(){
    vector<int> nums = {22,22,21};
    cout << singleElement(nums) << endl;
    return 0;
}