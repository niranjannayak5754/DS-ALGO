/*
-> Letter combination in a phone number

    Given a string containing digits from 2-9 inclusive,
    return all possible letter combinations that the number could represent. Return the answer in any order. 
    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    Example 2:
    Input: digits = ""
    Output: []

    Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(string digits, vector<string> &res, string output, int idx, const vector<string> &mapping)
{
    if (idx == digits.length())
    {
        res.push_back(output);
        return;
    }
    int digit = digits[idx] - '0'; // to convert the char type to int we substracted '0'
    string string_val = mapping[digit];
    for (char ch : string_val)
    {
        output.push_back(ch);
        backtrack(digits, res, output, idx + 1, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if (digits.length() == 0)
        return res;
    string output;
    const vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    backtrack(digits, res, output, 0, mapping);
    return res;
}

int main()
{
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    for (string val : res)
    {
        cout << val<< endl;
    }
    return 0;
}