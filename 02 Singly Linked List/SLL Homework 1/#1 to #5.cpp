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

    ~LinkedList() {
        Node *curr = head;
        while (head) {
            head = head->next;
            delete curr;
            curr = head;
        }
        delete curr;
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
        Node* temp = head;
        head = head->next;
        delete temp;
        elements--;
    }

    Node* get_nth_back(int n) {
        if (n > elements) return nullptr;
        Node *curr = head;
        // 1 2 3 4 5 6
        n = elements - n; // 6 - 1 = 5
        while (n--)
            curr = curr->next; // 5.next = 6 >> true
        return curr; // return 6
    }

    bool is_same1(LinkedList &other) {
        if (this->elements != other.elements) return false;
        Node *curr1 = head, *curr2 = other.head;
        while (curr1 and curr2) {
            if (curr1->data != curr2->data) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }

    bool is_same2(LinkedList &other) {
        Node *curr1 = head, *curr2 = other.head;
        while (curr1 and curr2) {
            if (curr1->data != curr2->data) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
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
    l.print(); // 1 2 3 4 5
    l.delete_front();
    l.print(); // 2 3 4 5
    cout << l.get_nth_back(2)->data << '\n'; // 4

    l2.insert_front(5);
    l2.insert_front(4);
    cout << l.is_same1(l2) << '\n'; // 0
    l2.insert_front(3);
    l2.insert_front(2);
    cout << l.is_same1(l2) << '\n'; // 1
    cout << l2.is_same2(l) << '\n'; // 1

    return 0;
}