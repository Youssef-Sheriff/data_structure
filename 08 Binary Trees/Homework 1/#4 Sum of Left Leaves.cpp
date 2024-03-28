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

bool left;

// solution
class Solution {
public:
    bool isLeft;
    int total = 0;

    bool isLeaf(TreeNode *root) {
        return !root->left and !root->right;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        if (isLeaf(root) and isLeft) total += root->val;
        if (root->left) {
            isLeft = true;
            sumOfLeftLeaves(root->left);
        }
        if (root->right) {
            isLeft = false;
            sumOfLeftLeaves(root->right);
        }
        return total;
    }
};


int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    BinaryTree tree(3);
    tree.add({9}, {'L'});
    tree.add({20, 15}, {'R', 'L'});
    tree.add({20, 7}, {'R', 'R'});

    cout << Solution().sumOfLeftLeaves(tree.root); // 24


    return 0;
}