#include <iostream>

using namespace std;

struct Node {
    int data{};
    Node *next{};

    Node(int data) : data(data) {}
};

class LinkedList {
private:
    Node *head{};
    Node *tail{};
    int elements = 0;

public:
    void reverse() {
        if (elements < 2) return;
        tail = head;
        Node *curr = head->next, *prv = head, *nxt;
        while (curr) {
            //      p c n
            //  1 2 3 4 5
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        head->next = nullptr;
        head = prv;
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
    l.insert_front(10);
    l.insert_front(2);
    l.insert_front(30);
    l.insert_front(4);
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(0);
    l.print(); // 0 2 1 4 30 2 10
    l.reverse();
    l.print(); // 10 2 30 4 1 2 0

    return 0;
}