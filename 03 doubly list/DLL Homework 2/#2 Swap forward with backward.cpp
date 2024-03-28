#include <iostream>

using namespace std;

struct Node {
    int data{};
    Node *prev{};
    Node *next{};

    Node(int data) : data(data) {}
};

class LinkedList {
private:
    Node *head{};
    Node *tail{};
    int length = 0;
public:
    void link(Node *first, Node *second) {
        if (first) first->next = second;
        if (second) second->prev = first;
    }

    void insert_front(int val) {
        Node *newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            link(newNode, head);
            head = newNode;
        }
        length++;
    }

    void swap_forward_backward() {
        if (length < 2) return;
        link(tail->prev, head); //
        link(tail, head->next);
        tail->prev = nullptr;
        head->next = nullptr;
        swap(head, tail);
    }

    Node *getHead() const {
        return head;
    }

    Node *getTail() const {
        return tail;
    }


    void print() {
        if (!head) return;
        Node *curr = head;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    LinkedList l;
//    l.insert_front(1);
//    l.insert_front(2);
    l.insert_front(1);
    l.insert_front(3);
    l.insert_front(10);
    l.insert_front(2);
    l.insert_front(4);
    l.print();
    cout << l.getHead() << ' ' << l.getTail() << endl; // 0x10, 0x90
    l.swap_forward_backward();
    l.print();
    cout << l.getHead() << ' ' << l.getTail() << endl; // 0x90, 0x10


    return 0;
}