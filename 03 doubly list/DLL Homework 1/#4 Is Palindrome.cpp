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
    
    bool is_palindrome() {
        if (!head) return false;
        Node *l = head, *r = tail;
        for (int i = 0; i < length / 2; ++i) {
            if (!(l->data == r->data)) return false;
            l = l->next, r = r->prev;
        }
        return true;
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
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(1);
//    l.insert_front(2);
//    l.insert_front(4);
    l.print();
    cout << l.is_palindrome(); // true
//    l.print();

    return 0;
}