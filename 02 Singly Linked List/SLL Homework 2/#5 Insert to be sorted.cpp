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
    void insert_sorted(int value) {
        if (!head or head->data > value) insert_front(value);
        else if (tail->data < value) insert_back(value);
        else {
            Node *curr = head, *newNode = new Node(value);
            while (curr->next->data < value) {
                // 1 2 4  10 30 let's add 5
//                if (curr->next->data > value) break;
                curr = curr->next;
            }
//            cout << curr->data << endl;
            newNode->next = curr->next;
            curr->next = newNode;
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

    void insert_back(int value) {
        Node *newNode = new Node(value);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
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
    l.insert_sorted(10);
    l.print();
    l.insert_sorted(2);
    l.print();
    l.insert_sorted(30);
    l.print();
    l.insert_sorted(4);
    l.print();
    l.insert_sorted(1);
    l.print();
    /* output:
                10
                2 10
                2 10 30
                2 4 10 30
                1 2 4 10 30
      */

    return 0;
}