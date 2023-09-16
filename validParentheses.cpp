#include <iostream>
#include <stack>
#include <string>

using namespace std; // Use the std namespace

bool isBalanced(const string& str) {
    stack<char> st;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;  // Unmatched closing parenthesis
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;  // Mismatched opening and closing parenthesis
            }
        }
    }

    return st.empty();  // True if all parentheses are balanced
}

int main() {
    string input;
    // cout << "Enter a string with parentheses: ";
    // cin >> input;
    input = "()[({(})})]";
    cout << isBalanced(input);

    return 0;
}
