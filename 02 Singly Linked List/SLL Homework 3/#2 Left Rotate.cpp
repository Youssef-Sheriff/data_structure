#include <iostream>

using namespace std;

struct Node {
    int data{};
    Node *next{};

    Node(int data) : data(data) {}
};

class LinkedList {
public:
    Node *getHead() const {
        return head;
    }

    Node *getTail() const {
        return tail;
    }

private:
    Node *head{};
    Node *tail{};
    int elements = 0;

public:

    void left_rotate(int times) {
        times %= elements;
        while (times--)
            left_rotate();
    }

    void left_rotate() {
        if (elements < 2) return;
        Node *curr = head;
        int temp = head->data;
        while (curr->next) {
            curr->data = curr->next->data;
            curr = curr->next;
        }

        tail->data = temp;
    }

    void insert_front(int value) {
        Node *newNode = new Node(value);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        elements++;
    }

    void print() {
        Node *curr = head;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    LinkedList l;
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(3);
    l.insert_front(4);
    l.insert_front(5);
    l.print();   // 5 4 3 2 1
    l.left_rotate(3);
    l.print();   // 2 1 5 4 3


    return 0;
}