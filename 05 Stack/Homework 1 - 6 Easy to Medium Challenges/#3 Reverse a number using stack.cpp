#include <iostream>
#include <stack>

using namespace std;

int reverse_num(int num) {
    stack<int> fs, sc;
    while (num) {
        fs.push(num % 10);
        num /= 10;
    }
    while (!fs.empty()) {
        sc.push(fs.top());
        fs.pop();
    }
    int rkm = 0;
    while (!sc.empty()) {
        rkm = rkm * 10 + sc.top();
//        cout << rkm << ' ';
        sc.pop();
    }
    return rkm;
}

int main() {

    cout << reverse_num(-1245410) << endl; // -145421
    cout << reverse_num(120) << endl;      // 21
    cout << reverse_num(1234) << endl;     // 4321
    cout << reverse_num(-9415) << endl;    // -5149

    return 0;
}