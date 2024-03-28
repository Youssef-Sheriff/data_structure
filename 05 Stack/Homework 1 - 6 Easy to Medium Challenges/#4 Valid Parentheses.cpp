#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    int sz = s.size();
    stack<char> st;
    for (int i = 0; i < sz; ++i) {
        if (!st.empty() &&
            (st.top() == '(' && s[i] == ')' ||
             st.top() == '[' && s[i] == ']' ||
             st.top() == '{' && s[i] == '}')) {
            st.pop();

        } else st.push(s[i]);

    }
    return st.empty();
}

int main() {

    string str;
    cin >> str;
    cout << (isValid(str) ? "valid" : "not valid") << endl;
    //  ({[)   >> not valid
    //  ()[]{} >> valid
    //  "(]"
    // ()()()(()()){}{}(((())))([])()[]{}{[]} >> valid
    // (]())(][)(]([)] >> not valid

    return 0;
}