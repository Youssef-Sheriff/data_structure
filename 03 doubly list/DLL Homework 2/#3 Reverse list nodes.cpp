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

    void reverse() {
        if (length < 2) return;
        Node *first = head, *second = head->next, *cpy = second->next;
        while (first and second) {
            link(second, first);
            first = second, second = cpy;
            if (cpy) cpy = cpy->next;
            else break;
        }
        head->next = tail->prev = nullptr;
        swap(head, tail);
        // for debug and visual nxt, prv
        first = head->next;
        while (first->next) {
            cout << first->prev->data << " <- " << first->data << " -> " << first->next->data << endl;
            first = first->next;
        }
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
    l.insert_front(7);
    l.insert_front(6);
    l.insert_front(5);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(2);
    l.insert_front(1);
    l.print(); // 1 2 3 4 5 6 7
    l.reverse();
    l.print(); // 7 6 5 4 3 2 1

    return 0;
}