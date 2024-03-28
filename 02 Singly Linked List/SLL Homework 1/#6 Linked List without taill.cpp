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
public:
    void print() {
        Node *curr = head;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }

    void add_element(int value) {
        Node *newNode = new Node(value);
        if (!head)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    Node *get_tail() { // or we can use function get_nth_from_back(1);
        if (!head) return nullptr;
        Node *curr = head;
        while (curr->next)
            curr = curr->next;
        // 1 2 3 4 5
        return curr;
    }

};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    // test all function here
    LinkedList l, l2;
    l.add_element(5);
    l.add_element(4);
    l.add_element(3);
    l.add_element(2);
    l.add_element(1);
    l.add_element(2);
    l.print(); // 1 2 3 4 5
    cout << l.get_tail()->data; // 5


    return 0;
}