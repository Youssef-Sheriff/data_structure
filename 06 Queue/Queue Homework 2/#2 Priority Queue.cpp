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

class PriorityQueue {
    Queue q1, q2, q3;
public:

    PriorityQueue(int size) : q1(size), q2(size), q3(size) {}

    void enqueue(int val, int priority) {
        if (priority == 1) q1.enqueue(val);
        else if (priority == 2) q2.enqueue(val);
        else if (priority == 3) q3.enqueue(val);
    }

    int dequeue() {
        if (!q3.isEmpty()) return q3.dequeue();
        else if (!q2.isEmpty()) return q2.dequeue();
        else return q1.dequeue();
    }

    void print() {
        if (!q3.isEmpty()) {
            cout << "Priority #3: ";
            q3.print();
        }
        if (!q2.isEmpty()) {
            cout << "Priority #2: ";
            q2.print();
        }
        if (!q1.isEmpty()) {
            cout << "Priority #1: ";
            q1.print();
        }
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    PriorityQueue task(8);
    task.enqueue(103, 1);
    task.enqueue(33, 3);
    task.enqueue(200, 2);
    task.enqueue(323, 3);
    task.print();
    //   Priority #3: 33 323
    //   Priority #2: 200
    //   Priority #1: 103
    cout << task.dequeue() << endl; // 33
    cout << task.dequeue() << endl; // 323


    return 0;
}