#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string> &res, int n, int openC, int closedC, string &p) {
    if (openC == n && closedC == n) { // Corrected the base case condition
        res.push_back(p);
        return;
    }

    if (openC < n) {
        p += "(";
        backtrack(res, n, openC + 1, closedC, p);
        p.pop_back(); // Backtrack by removing the added '('
    }

    if (closedC < openC) {
        p += ")";
        backtrack(res, n, openC, closedC + 1, p);
        p.pop_back(); // Backtrack by removing the added ')'
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string p = "";
    backtrack(res, n, 0, 0, p);
    return res;
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> validParentheses = generateParenthesis(n);

    cout << "Valid combinations of parentheses for " << n << " pairs are:\n";
    for (const string& parentheses : validParentheses) {
        cout << parentheses << "\n";
    }

    return 0;
}
