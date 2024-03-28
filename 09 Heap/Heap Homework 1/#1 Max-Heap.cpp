#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
private:
    int *arr{}, size{}, capacity{1000};

    int parent(int child_pos) {
        return child_pos == 0 ? -1 : ((child_pos - 1) / 2);
    }

    int left(int node) {
        int pos = node * 2 + 1;
        return pos >= size ? -1 : pos;
    }

    int right(int node) {
        int pos = node * 2 + 2;
        return pos >= size ? -1 : pos;
    }

    void heapify_up(int child) {
        int parent_pos = parent(child);
        if (child == 0 or arr[parent_pos] > arr[child]) return;
        swap(arr[child], arr[parent_pos]);
        heapify_up(parent_pos);
    }

    void heapify_down(int node_pos) {
        int child = left(node_pos);
        int right_pos = right(node_pos);

        if (child == -1) return; // has no child

        if (right_pos != -1 and arr[child] < arr[right_pos]) child = right_pos;

        if (arr[child] > arr[node_pos]) {
            swap(arr[child], arr[node_pos]);
            heapify_down(child);
        }
    }

public:
    MaxHeap() {
        arr = new int[capacity];
        size = 0;
    }

    ~MaxHeap() {
        delete[] arr;
        arr = nullptr;
    }

    void push(int val) {
        assert(size + 1 <= capacity);
        arr[size++] = val;
        heapify_up(size - 1);
    }

    int top() {
        assert(!empty());
        return arr[0];
    }


    void pop() {
        assert(!empty());
        arr[0] = arr[--size];
        heapify_down(0);
    }

    bool empty() {
        return size == 0;
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    MaxHeap h;
    vector<int> v{5, 4, 2, 1, 6, 7, 3, 10};
    for (int i = 0; i < (int) v.size(); ++i) {
        h.push(v[i]);
    }
    while (!h.empty()) {
        cout << h.top() << ' ';
        h.pop();
    }
    return 0;
}