/*
    Reverse Number -> Medium -> Math
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1],
    then return 0.
*/

#include <iostream>
#include<climits> // for limits of INT_MAX and INT_MIN of 32_bits

using namespace std;

int reverse(int x)
{
    int temp = x;
    int rev = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        // to avoid overflow
        if(rev > (INT_MAX/10 - rem/10) || rev < (INT_MIN/10 - rem/10))
            return 0;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    return rev;
}

int main(){
    int x = -2147483648;
    cout << reverse(x) << endl;
    return 0;
}