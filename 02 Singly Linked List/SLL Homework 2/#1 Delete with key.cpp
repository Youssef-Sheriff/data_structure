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

    void delete_node_with_key(int value) {
        if (!head) return;
        if (value == head->data) {
            delete_front();
            return;
        }
        Node *curr = head, *temp;
        while (curr->next) {
            if (curr->next->data == value) {
                temp = curr->next;
                // 1 2 3 4 5
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
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

    void delete_front() {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        elements--;
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
    // test all function here
    LinkedList l, l2;
    l.insert_front(5);
    l.insert_front(4);
    l.insert_front(3);
    l.insert_front(2);
    l.insert_front(1);
    l.print();
    l.delete_node_with_key(1);
    l.print();

    return 0;
}