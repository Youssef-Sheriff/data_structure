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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        if (!root->left and !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val)
               + hasPathSum(root->right, targetSum - root->val);
    }


};


int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    cout << Solution().hasPathSum(tree.root, 14); // true


    return 0;
}