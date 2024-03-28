#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val{};
    TreeNode *left{};
    TreeNode *right{};

    TreeNode(int val) : val(val) {}
};


struct BinaryTree {
    TreeNode *root{};

    BinaryTree(int root_value) :
            root(new TreeNode(root_value)) {
    }

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        TreeNode *current = this->root;
        for (int i = 0; i < (int) values.size(); ++i) {
            if (direction[i] == 'L') {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                else
                    assert(current->left->val == values[i]);
                current = current->left;
            } else {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                else
                    assert(current->right->val == values[i]);
                current = current->right;
            }
        }
    }
};

class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        if (!root) return false;
        bool ok = false;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left) {
                if (ok) return false;
                q.push(curr->left);
            } else ok = true;
            if (left and curr->right) {
                if (ok) return false;
                q.push(curr->right);
            } else ok = true;
        }
        return true;
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    BinaryTree tree(1);
    tree.add({2, 5}, {'L', 'L'});
    tree.add({3, 7}, {'R', 'L'});
    tree.add({3, 8}, {'R', 'R'});
    return 0;
}