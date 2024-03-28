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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        deque<TreeNode *> d;
        if (!root) return ans;
        bool direction = true;
        d.push_back(root);
        TreeNode *curr;
        int sz;
        while (!d.empty()) {
            sz = d.size();
            vector<int> lvl;
            while (sz--) {
                if (direction) {
                    curr = d.front();
                    d.pop_front();
                    if (curr->left) d.push_back(curr->left);
                    if (curr->right) d.push_back(curr->right);
                } else {
                    curr = d.back();
                    d.pop_back();
                    if (curr->right) d.push_front(curr->right);
                    if (curr->left) d.push_front(curr->left);
                }
                lvl.push_back(curr->val);
            }
            direction = !direction;
            ans.push_back(lvl);
        }
        return ans;
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
    vector<vector<int>> v = Solution().zigzagLevelOrder(tree.root);
    for (int i = 0; i < v.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ' ';
        }
        cout << ']';
    }
// [ 2 ][ 13 3 ][ 5 6 7 8 ]

    return 0;
}