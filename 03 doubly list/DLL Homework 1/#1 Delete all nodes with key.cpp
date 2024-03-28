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

    void insert_back(int val) {
        Node *newNode = new Node(val);
        if (!tail) head = tail = newNode;
        else {
            link(tail, newNode);
            tail = newNode;
        }
        length++;

    }

    void delete_front() {
        if (!head) return;
        length--;
        if (length == 1) {
            head = tail = nullptr;
            return;
        }
        Node *curr = head->next;
        delete head;
        head = curr;
        if (head) head->prev = nullptr;

    }

    void delete_end() {
        if (!tail) return;
        length--;
        if (length == 1) {
            head = tail = nullptr;
            return;
        }
        Node *curr = tail->prev;
        delete tail;
        tail = curr;
        if (tail) tail->next = nullptr;
    }

    void delete_with_key(int val) {
        if (!head) return;
        insert_front(-val);
        insert_back(-val);
        Node *curr = head;
        while (curr) {
            if (curr->data == val) {
                link(curr->prev, curr->next);
                Node *temp = curr;
                delete temp;
                length--;
            }
            curr = curr->next;
        }
        delete_front(), delete_end();
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
    l.insert_front(4);
    l.insert_front(4);
    l.insert_front(5);
    l.insert_front(4);
    l.insert_front(5);
    l.insert_front(2);
    l.insert_front(4);
    l.print();
    l.delete_with_key(5);
    l.print();

    return 0;
}