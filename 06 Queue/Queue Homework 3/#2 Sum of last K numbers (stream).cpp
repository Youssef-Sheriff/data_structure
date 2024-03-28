#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

class Queue {
    int size{};
    int front{0};
    int rear{0};
    int elements{};
    int *arr{};

public:
    Queue(int size) :
            size(size) {
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    int next(int pos) {
        return (pos + 1) % size;
    }

    void enqueue(int val) {
        assert(!isFull());
        arr[rear] = val;
        rear = next(rear);
        elements++;
    }

    int dequeue() {
        assert(!isEmpty());
        int val = arr[front];
        front = next(front);
        --elements;
        return val;
    }

    void print() {
        int curr = front;
        for (int i = 0; i < elements; ++i) {
            cout << arr[curr] << ' ';
            curr = next(curr);
        }
        cout << '\n';
    }

    int isEmpty() {
        return elements == 0;
    }

    bool isFull() {
        return elements == size;
    }
};

class Last_K_nums {
private:
    int k{}, sum{0};
    Queue q;
    int elements{0};
public:
    Last_K_nums(int k) : k(k), q(k + 1) {}


    int next(int val) {
        q.enqueue(val);
        sum += val;
        elements++;
        if (elements > k) {
            sum -= q.dequeue();
            elements--;
        }
        return sum;
    }
};


int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    Last_K_nums l(4);

    int n;
    while (cin >> n) {                 // 1 2 3 4 5 6 7 8 9
        cout << l.next(n) << ' '; // 1 3 6 10 14 18 22 26 30
    }

    return 0;
}