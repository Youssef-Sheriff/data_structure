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
    int nodeParent(TreeNode *root, int target) {
        if (!root or root->val == target) return -1;
        if (root->left and root->left->val == target or root->right and root->right->val == target) return root->val;
        int p = nodeParent(root->left, target);
        int pt = nodeParent(root->right, target);
        return max(p, pt);
    }

    int calculateNodeDepth(TreeNode *root, int target, int depth = 0) {
        if (!root) return -1;
        if (root->val == target) {
            return depth;
        }
        int leftDepth = calculateNodeDepth(root->left, target, depth + 1);
        int rightDepth = calculateNodeDepth(root->right, target, depth + 1);
        return max(leftDepth, rightDepth);
    }

    bool isCousins(TreeNode *root, int x, int y) {
        return calculateNodeDepth(root, x) == calculateNodeDepth(root, y) and
               nodeParent(root, x) != nodeParent(root, y);
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

    cout << Solution().isCousins(tree.root, 15, 7) << endl; // false - brothers



    return 0;
}