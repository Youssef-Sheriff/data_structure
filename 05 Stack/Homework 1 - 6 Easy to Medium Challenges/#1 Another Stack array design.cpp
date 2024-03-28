#include <iostream>

using namespace std;
#define endl '\n'

class Stack {
private:
    int size{};
    int added_elements{};
    int *arr{};
public:
    Stack(int size) {
        this->size = size;
        this->added_elements = 0;
        arr = new int[size];
    }

    bool isFull() {
        return added_elements == size;
    }

    bool isEmpty() {
        return added_elements == 0;
    }

    bool push(int rkm) {
        if (isFull()) return false;

        for (int i = added_elements; i > 0; --i)
            arr[i] = arr[i - 1];
        arr[0] = rkm;
        added_elements++;
        return true;
    }

    bool pop(int &temp) {
        if (isEmpty()) return false;
        temp = arr[0];
        for (int i = 0; i < added_elements - 1; ++i)
            arr[i] = arr[i + 1];
        added_elements--;
        return true;
    }

    bool peek(int &temp) {
        if (isEmpty()) return false;
        temp = arr[0];
        return true;
    }

    void print() {
        for (int i = 0; i < added_elements; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

int main() {
    Stack st(3);
    int temp;
    cout << st.pop(temp) << endl; // 0 >> stack is empty
    st.push(1);
    st.push(2);
    st.push(3);
    st.print(); // 3 2 1
    st.pop(temp);
    cout << temp << endl; // 3
    st.print(); // 2 1
    cout << st.push(3) << endl; // 1
    st.print(); // 3 2 1
    st.push(4);
    cout << st.push(5) << endl; // 0 >> stack is full
    st.push(6); // doesn't push
    st.print(); // 3 2 1


    return 0;
}