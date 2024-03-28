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
    void swap_pairs() {
        // c-> c-> c->
        // 1 2 3 4 5 6 7
        if (elements <= 1) return;
        Node *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            swap(curr->data, curr->next->data);
            curr = curr->next->next;
        }
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
    l.insert_front(7);
    l.insert_front(6);
    l.insert_front(5);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(2);
    l.print(); // 2 3 4 5 6 7
    l.swap_pairs();
    l.print(); // 3 2 5 4 7 6
    l.insert_front(1);
    l.print(); // 1 3 2 5 4 7 6
    l.swap_pairs();
    l.print(); // 3 1 5 2 7 4 6

    return 0;
}