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
    void remove_last_occurance(int value) {
        if (elements < 2) return;
        Node *curr = head, *prv = head, *temp = head;
        while (curr->next) {
            if (curr->next->data == value) {
                prv = curr;
                temp = curr->next;
            }
            curr = curr->next;
        }
        if (prv == head and head->data == value) {
            head = head->next;
            delete temp;
            return;
        }
        if (temp->data == value) {
            prv->next = prv->next->next;
            delete temp;
        }
        elements--;
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

    l.insert_front(4);
    l.insert_front(1);
    l.insert_front(3);
    l.insert_front(2);
    l.insert_front(1);
    l.print();   // 1 2 3 1 4
    l.remove_last_occurance(1);
    l.print();   // 1 2 3 4


    return 0;
}