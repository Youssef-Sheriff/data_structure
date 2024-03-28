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

// solution
class Solution {
public:
    bool isPerfect(TreeNode *root) {
        if (!root) return true;
        int expect_nodes = 1; // 2^0
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int curr_size = q.size();
            if (curr_size != expect_nodes) return false;
            for (int i = 0; i < curr_size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            expect_nodes *= 2;// or expect_nodes *=2
        }
        return true;
    }

};


int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    BinaryTree tree(2);
    tree.add({3, 5}, {'L', 'L'});
    tree.add({3, 6}, {'L', 'R'});
    tree.add({13, 7}, {'R', 'L'});
    tree.add({13, 8}, {'R', 'R'});
    cout << Solution().isPerfect(tree.root) << endl; // true



    return 0;
}