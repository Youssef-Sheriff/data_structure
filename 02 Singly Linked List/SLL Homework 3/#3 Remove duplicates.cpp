#include <bits/stdc++.h>

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

    void remove_duplicates() {
        // I can use nested loop, too.
        if (elements < 2) return;
        map<int, bool> m;
        Node *curr = head->next, *prv = head, *temp;
        m[head->data] = true;
        while (curr) {
            if (m[curr->data]) {
                temp = curr;
                prv->next = temp->next;
                curr = temp->next;
                delete temp;
                elements--;
            } else {
                m[curr->data] = true;
                prv = curr;
                curr = curr->next;
            }
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
    l.insert_front(2);
    l.insert_front(5);
    l.insert_front(3);
    l.insert_front(4);
    l.insert_front(2);
    l.insert_front(3);
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(1);
    l.print();   // 1 2 1 3 2 4 3 5 2
    l.remove_duplicates();
    l.print();   // 1 2 3 4 5


    return 0;
}