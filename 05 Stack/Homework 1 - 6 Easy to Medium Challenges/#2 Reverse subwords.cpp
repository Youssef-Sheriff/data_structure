#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
    stack<char> st;
    string str, res = "";
    getline(cin, str); // to enter spaces
    int sz = str.size();
    for (int i = 0; i < sz; ++i) {
        // abc d efg xy
        while (isalpha(str[i])) {
            st.push(str[i]);
            i++;
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        res += ' ';
    }
    cout << res << endl; // cba d gfe yx
    // youssef sherif >> fessuoy firehs



    return 0;
}