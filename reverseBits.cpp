/*
    Reverse 32 bit integer

    1010...1111 to 1111......0101
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for(int i = 0; i<32; i++){
            res = (res << 1) | (n & 1);
            n = n >> 1;
        }
        
        return res;
    }
};