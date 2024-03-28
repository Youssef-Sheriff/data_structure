#include <iostream>

using namespace std;

class Stack {
private:
    int top1{}, top2{};
    int capacity{};
    int *arr;
public:     //   assume capacity is even & 2 stacks have the same size capacity / 2
    Stack(int capacity) : capacity(capacity), top1(-1),
                          top2(capacity / 2 - 1) {
        arr = new int[capacity];
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity / 2 - 1;
    }

    bool isFull1() {
        return top1 == capacity / 2 - 1;
    }

    bool isFull2() {
        return top2 == capacity - 1;
    }

    void push(int id, int rkm) {
        if (id == 1) {
//            assert(!isFull1());
            if (!isFull1()) arr[++top1] = rkm;
        } else if (id == 2) {
//            assert(!isFull2());
            if (!isFull2()) arr[++top2] = rkm;
        }
    }

    int pop(int id) {
        if (id == 1) {
            if (!isEmpty1()) return arr[top1--];
        } else if (id == 2) {
            if (!isEmpty2()) return arr[top2--];
        }
    }

    int peek(int id) {
        if (id == 1) {
            if (!isEmpty1()) return arr[top1];
        } else if (id == 2) {
            if (!isEmpty2()) return arr[top2];
        }
    }

    void print() {
        cout << "Stack 1: ";
        for (int i = top1; i >= 0; --i) cout << arr[i] << ' ';
        cout << endl << "Stack 2: ";
        for (int i = top2; i >= capacity / 2; --i) cout << arr[i] << ' ';
    }
};

int main() {

    Stack st(10);
    st.push(2, 5);
    st.push(2, 6);
    st.pop(2);
    st.push(2, 7);
    st.push(2, 9);
    st.push(1, 4);
    cout << st.peek(1) << endl; // 4
    cout << st.peek(2) << endl; // 9
    st.push(1, 6);
    st.push(1, 8);
    st.push(2, 3);

    st.print(); // Stack 1: 8 6 4
//                 Stack 2: 3 9 7 5

    return 0;
}