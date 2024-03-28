#include <iostream>
#include <cassert>

using namespace std;

class Vector {
private:
    int *arr = nullptr;
    int size = 0;

public:
    Vector(int size) : size(size) {
        if (size < 0) size = 1;
        arr = new int[size];
    }

    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }

    void push_back(int value) {

        int *arr2 = new int[size + 1];
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];
        arr2[size++] = value;
        swap(arr, arr2);
        delete[] arr2;
    }

    void right_rotate() {
        if (size <= 1) return;
        int temp = arr[size - 1]; // last element
        for (int i = size - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    void left_rotate() {
        if (size <= 1) return;
        int temp = arr[0]; // first element
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }

    void right_rotate(int times) {
        // avoid repeat to original order
        times = times % size; // if the steps = size >> do nothing
        while (times--) {
            right_rotate();
        }
    }

    int pop(int idx) {
        assert(idx >= 0 && idx < size);
        int temp = arr[idx];
        for (int i = idx; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        return temp;
    }

    int find_transposition(int value) {
        //
        int temp = -1; // return -1 >> if no value
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                if (i == 0) // if value exists in the first idx
                    return 0; // do nothing
                temp = i - 1;
                swap(arr[temp], arr[temp + 1]); // shift value one step left
                break;
            }
        }
        return temp;
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }

};

int main() {

    Vector v(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.print(); // 0 1 2 3 4
    v.right_rotate(2);
    v.print(); // 3 4 0 1 2
    v.pop(2);
    v.print(); // 3 4 1 2
    v.left_rotate();
    v.print(); // 4 1 2 3
    v.find_transposition(2);
    v.print(); // 4 2 1 3

    return 0;
}