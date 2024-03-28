#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

class Stack {
private:
    int size{};
    int top{};
    int *arr{};

public:
    Stack(int size) : size(size), top(-1) {
        arr = new int[size];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        assert(!isFull());
        arr[++top] = x;
    }

    int pop() {
        assert(!isEmpty());
        return arr[top--];
    }

    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void print() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << ' ';
        cout << '\n';
    }
};

class Queue {
private:
    int size{}, elements{0};
    Stack s1, s2;

    // to reorder element to satisfy queue concept
    void add_and_reverse(int val) {
        s1.push(val);
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }

public:
    Queue(int size) : size(size), s1(size), s2(size) {

    }

    void enqueue(int val) {
        assert(!s1.isFull());
        add_and_reverse(val);
        elements++;
    }

    int dequeue() {
        assert(!isEmpty());
        elements--;
        return s2.pop();
    }

    bool isEmpty() {
        return s2.isEmpty();
    }

    bool isFull() {
        return s2.isFull();
    }

    void print() {
        s2.print();
    }

};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    Queue q(5);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(10);
    q.print();
    q.enqueue(45);
    q.print();
    q.dequeue();
    q.print();
    cout << q.dequeue() << endl;
    q.print();
    return 0;
}