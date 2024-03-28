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
    void swap_head_tail() {
        if (elements < 2) return;
        if (elements == 2) {
            tail->next = head;
            head->next = nullptr;
            swap(head, tail);
            return;
        }
        Node *curr = head;
        while (curr->next != tail)
            curr = curr->next;

        tail->next = head->next;
        head->next = nullptr;
        curr->next = head;
        swap(head, tail);
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
    l.print();
    cout << "head: ";
    cout << l.getHead()->data << ' ' << l.getHead() << endl;
    cout << "tail: ";
    cout << l.getTail()->data << ' ' << l.getTail() << endl;
    cout << "==== after swaping ====\n";
    l.swap_head_tail();
    cout << "head: ";
    cout << l.getHead()->data << ' ' << l.getHead() << endl;
    cout << "tail: ";
    cout << l.getTail()->data << ' ' << l.getTail() << endl;
    l.print();
    /*
            5 4 3 2 1
            head: 5 0x60
            tail: 1 0xc0
            ==== after swaping ====
            head: 1 0xc0
            tail: 5 0x60
            1 4 3 2 5

      */

    return 0;
}