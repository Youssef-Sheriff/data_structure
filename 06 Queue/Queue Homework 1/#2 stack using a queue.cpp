#include <iostream>
#include <cassert>

using namespace std;

class Queue {
private:
    int size{}, front{0}, rear{0}, elements{0}, *arr{};
public:

    Queue(int size) : size(size) {
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int val) {
        assert(!isFull());
        arr[rear] = val;
        rear = next(rear);
        ++elements;
    }

    int dequeue() {
        assert(!isEmpty());
        int ret = arr[front];
        front = next(front);
        --elements;
        return ret;
    }

    int qu_front() {
        assert(!isEmpty());
        return arr[front];
    }


    int next(int idx) {
        return (idx + 1) % size;
    }

    void print() {
        if (elements == 0) {
            cout << "- Empty -" << endl;
            return;
        }
        int curr = front;
        for (int i = 0; i < elements; ++i) {
            cout << arr[curr] << ' ';
            curr = next(curr);
        }
        cout << endl;
    }

    bool isEmpty() {
        return elements == 0;
    }

    bool isFull() {
        return elements == size;
    }

};

class Stack {
private:
    Queue q;
    int elements{0};

    void move_to_front(int val) {
        int sz = elements;
        q.enqueue(val);
        while (sz--) {
            q.enqueue(q.dequeue());
        }
    }

public:
    Stack(int size) : q(size) {}

    void push(int val) {
        move_to_front(val);
        elements++;
    }

    int pop() {
        elements--;
        return q.dequeue();
    }

    int peek() {
        return q.qu_front();
    }

    bool isFull() {
        return q.isFull();
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    // for debug ..
    void print() {
        q.print();
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    Stack s(10);
    s.push(5);
    s.push(10);
    s.push(515);
    s.push(3);
    s.push(123);
    s.print(); // 123 3 515 10 5

    return 0;
}