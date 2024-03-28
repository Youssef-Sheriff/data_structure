#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string s) {
    int sz = s.size();
    stack<char> st;
    st.push(s[sz - 1]);
    for (int i = sz - 2; i >= 0; --i) {
        if (!st.empty() and s[i] == st.top())
            st.pop();
        else st.push(s[i]);
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {

    string str;
    cin >> str;
    cout << removeDuplicates(str) << '\n';
//    -- accepted on leetcode --
//            aaaaaaaa >> -
//            abbaca >> ca
//            azxxzy >> ay


    return 0;
}