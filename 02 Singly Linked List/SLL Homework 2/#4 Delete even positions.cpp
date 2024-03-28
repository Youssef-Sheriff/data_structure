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
    void delete_even_positions() {
        if (elements < 2)return;
        Node *curr = head, *temp;
        while (curr and curr->next) {
            temp = curr->next;
            curr->next = temp->next;
            curr = temp->next;
            delete temp;
            elements--;
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
    l.insert_front(10);
    l.insert_front(2);
    l.insert_front(30);
    l.insert_front(4);
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(0);
    l.print(); // 0 2 1 4 30 2 10
    l.delete_even_positions();
    l.print(); // 0 1 30 10

    return 0;
}