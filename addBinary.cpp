/*
    Add Binary [Easy]
*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();

        if(n1 < n2)
            return addBinary(b, a);
        
        b = string(n1-n2, '0') + b;
        int carry = 0;
        string res = "";

        int sum;
        while(n1--){
            sum = (a[n1] - '0') + (b[n1] - '0') + carry;
            res = to_string(sum % 2) + res;
            cout << res << endl;
            carry = sum/2;
        }

        if(carry > 0)
            res = to_string(carry) + res;
        
        return res;
    }
};