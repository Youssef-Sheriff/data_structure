#include <bits/stdc++.h>

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
    void move_to_back(int value) {
        LinkedList l;
        Node *temp;
        while (head && head->data == value) {
            temp = head;
            head = head->next;
            delete temp;
            l.insert_front(value);
        }
        Node *curr = head, *prv = nullptr;

        while (curr->next) {
            if (curr->data == value) {
                if (prv)
                    prv->next = curr->next;
                temp = curr;
                curr = curr->next;
                delete temp;
                l.insert_front(value);
            } else {
                prv = curr;
                curr = curr->next;
            }
        }
//        cout << curr->data << endl;
        curr->next = l.head;
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
    l.insert_front(1);
    l.insert_front(8);
    l.insert_front(1);
    l.insert_front(7);
    l.insert_front(1);
    l.insert_front(4);
    l.insert_front(2);
    l.insert_front(1);
    l.insert_front(3);
    l.insert_front(2);
    l.insert_front(1);
    l.print(); // 1 2 3 1 2 4 1 7 1 8 1 1
    l.move_to_back(1);
    l.print(); // 2 3 2 4 7 8 1 1 1 1 1 1
    l.move_to_back(2);
    l.print(); // 3 4 7 8 1 1 1 1 1 1 2 2
    l.move_to_back(3);
    l.print(); // 4 7 8 1 1 1 1 1 1 2 2 3


    return 0;
}