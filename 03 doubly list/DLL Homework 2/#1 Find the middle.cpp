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

    Node *find_middle() {
        if (!head) return nullptr;
        Node *s = head, *f = head;
        while (f and f->next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    Node *find_mid() {
        if (!head) return nullptr;
        Node *l = head, *r = tail;
        while (l->next != r and l != r) {
            l = l->next;
            r = r->prev;
        }
        return r;
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
//    l.insert_front(1);
//    l.insert_front(2);
    l.insert_front(1);
    l.insert_front(3);
    l.insert_front(10);
    l.insert_front(2);
    l.insert_front(4);
    l.print();
    cout << l.find_middle()->data; // 10
    cout << l.find_mid()->data;    // 10
//    l.print();

    return 0;
}