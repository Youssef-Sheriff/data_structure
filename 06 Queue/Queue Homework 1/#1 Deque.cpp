#include <iostream>
#include <cassert>

using namespace std;

class Deque {
private:
    int size{}, front{0}, rear{0}, elements{0}, *arr{};
public:
    Deque(int size) : size(size) {
        arr = new int[size];
    }

    ~Deque() {
        delete[] arr;
    }

    void enqueue_front(int val) {
        assert(!isFull());
        arr[front] = val;
        if (elements == 0) {
            rear = next(rear);
        }
        front = prv(front);
        ++elements;
    }

    void enqueue_back(int val) {
        assert(!isFull());
        if (elements == 0) {
            front = prv(front);
        }
        arr[rear] = val;
        rear = next(rear);
        ++elements;
    }

    void dequeue_back() {
        assert(!isEmpty());
        rear = prv(rear);
        --elements;
    }

    void dequeue_front() {
        assert(!isEmpty());
        front = next(front);
        --elements;
    }


    int next(int idx) {
        return (idx + 1) % size;
    }

    int prv(int idx) {
        return ((idx - 1) % size + size) % size;
    }


    void print() {
        if (elements == 0) {
            cout << "- Empty -" << endl;
            return;
        }
        int curr = next(front);
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

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    Deque q(10);

    q.enqueue_front(3);
    q.enqueue_front(2);
    q.enqueue_back(4);
    q.enqueue_front(1);
    q.print();          //    1 2 3 4
    q.dequeue_back();
    q.print();          //    1 2 3
    q.dequeue_front();
    q.print();          //    2 3
    q.dequeue_back();
    q.print();          //    2
    q.dequeue_front();
    q.print();          //    - Empty -


    return 0;
}