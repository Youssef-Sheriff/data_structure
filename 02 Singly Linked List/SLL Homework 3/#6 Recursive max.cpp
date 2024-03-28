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

    int max_value(Node *curr) {
        if (!head) return INT_MIN;
        if (curr == nullptr) return 0;
        return max(curr->data, max_value(curr->next));
    }

    Node *getHead() const {
        return head;
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
    cout << l.max_value(l.getHead()) << endl; // -2147483648
    l.insert_front(1);
    l.insert_front(8);
    l.insert_front(12);
    cout << l.max_value(l.getHead()) << endl; // 12


    return 0;
}