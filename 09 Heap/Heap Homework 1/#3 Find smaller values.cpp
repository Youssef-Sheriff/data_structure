#include <bits/stdc++.h>

using namespace std;

class MinHeap {
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
        // when parent < child function stop
        int parent_pos = parent(child);
        if (child == 0 or arr[parent_pos] < arr[child]) return;
        swap(arr[child], arr[parent_pos]);
        heapify_up(parent_pos); // child = parent_pos
    }

    void heapify_down(int node_pos) {
        // we assume that arr[left] smaller than arr[right]
        int child = left(node_pos);
        int right_pos = right(node_pos);

        if (child == -1) return; // has no child

        if (right_pos != -1 and arr[child] > arr[right_pos]) child = right_pos;

        if (arr[child] < arr[node_pos]) {
            swap(arr[child], arr[node_pos]);
            heapify_down(child);
        }
    }

public:
    MinHeap() {
        arr = new int[capacity];
        size = 0;
    }

    ~MinHeap() {
        delete[] arr;
        arr = nullptr;
    }

    // when i push val multiply it (val * -1)
    void push(int val) {
        assert(size + 1 <= capacity);
        arr[size++] = val;
        heapify_up(size - 1);
    }

    int top() {
        assert(!empty());
        return arr[0]; // to display the real value
    }


    void pop() {
        assert(!empty());
        arr[0] = arr[--size];
        heapify_down(0);
    }

    bool empty() {
        return size == 0;
    }

    // this is my code for this function
    // but it will remove this elements
    // so your code is more efficient than me
    void print_less_than(int val, int parent_pos = 0) {
//        while (!empty() and top() < val) {
//            cout << top() << ' ';
//            pop();
//        }
        if (parent_pos == -1 or arr[parent_pos] >= val)
            return;

        cout << arr[parent_pos] << ' ';

        print_less_than(val, left(parent_pos));
        print_less_than(val, right(parent_pos));
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    // when i push val multiply it (val * -1)
    MinHeap h;
    vector<int> v{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
    for (int i = 0; i < (int) v.size(); ++i) {
        h.push(v[i]);
    }

    h.print_less_than(10);
    return 0;
}