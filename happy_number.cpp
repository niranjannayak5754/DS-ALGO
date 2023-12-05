/*
    Easy -> Happy Number [Hash Table]

    Intuition:

    The isHappy function takes an integer as input and uses a unordered_set to keep track of previously seen numbers. 
    he outer loop continues until the number becomes 1 (happy) or enters a cycle (unhappy),
    and the inner loop calculates the sum of the squares of its digits.


*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int num) {
    unordered_set<int> seen;

    while (num != 1 && seen.find(num) == seen.end()) {
        seen.insert(num);
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        num = sum;
    }

    return num == 1;
}

int main() {
    int number_to_check = 19;

    if (isHappy(number_to_check)) {
        cout << number_to_check << " is a happy number" << std::endl;
    } else {
        std::cout << number_to_check << " is not a happy number" << std::endl;
    }

    return 0;
}
