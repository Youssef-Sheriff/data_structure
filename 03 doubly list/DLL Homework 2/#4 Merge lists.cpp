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
        if (!head)
            head = tail = newNode;
        else {
            link(tail, newNode);
            tail = newNode;
        }
    }

    void merge_2sorted_lists(LinkedList &other) {
        Node *first = this->head, *sec = other.head;
        while (sec and first) {
            if (sec and first and sec->data <= first->data) {
                if (first == head) insert_front(sec->data);
                else {
                    Node *newNode = new Node(sec->data);
                    link(first->prev, newNode);
                    link(newNode, first);
                }
                sec = sec->next;
            } else if (sec and first and sec->data > first->data) {
                first = first->next;
            } else if (!sec or !first) return;
        }
        // if some values in second > all values in first linked list
        while (sec) {
            insert_back(sec->data);
            sec = sec->next;
        }
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
    LinkedList l, l2;
    // {10,20,30,40,50}
    l.insert_front(50);
    l.insert_front(40);
    l.insert_front(30);
    l.insert_front(20);
    l.insert_front(10);
    // {15,17,22,24,35}
    l2.insert_front(70);
    l2.insert_front(35);
    l2.insert_front(24);
    l2.insert_front(22);
    l2.insert_front(17);
    l2.insert_front(15);
    l2.print();
    l2.merge_2sorted_lists(l); // 10 15 17 20 22 24 30 35 40 50 70
    l2.print();


    return 0;
}