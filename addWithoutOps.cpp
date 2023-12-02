/*
    Adding two intergers a and b without using + or - operator.

    Using Bit Manipulation
    Intuition:

    xor_value = a ^ b;
    carry_value = (a&b) << 1;

    sum = xor_value ^ carry_value [carry_value should be carried in iteration unless it becomes 0]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry = b, sum;
        while(carry != 0){
            sum = a ^ b;
            carry = (a&b) << 1;

            a = sum;
            b = carry;
        }
        return a;
    }
};

int main(){
    Solution obj;
    cout << obj.getSum(5, 12) << endl;
    return 0;
}