/* 中序遍历二叉树 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char ch) : val(ch){};
    TreeNode(char ch, TreeNode *l, TreeNode *r) : val(ch), left(l), right(r){};
};

void inorder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        inorder(root->left);
    }
    cout << root->val;
    if (root->right) {
        inorder(root->right);
    }
}

int main() {
    // string str("a{b{d,e{g,h{,i}}},c{f}}");
    // string str("a{b{c}}");
    // string str("a{b{d, e}, c{f, g}}");
    string str;
    cin >> str;
    if (str.length() == 0) {
        return -1;
    }
    TreeNode *root = new TreeNode(str[0]);
    stack<TreeNode *> stk;
    stk.push(root);
    bool isLeft = true;
    for (int i = 1; i < str.length(); ++i) {
        // cout << "[debug] stk.size() = " << stk.size() << endl;
        if (str[i] == '{') {
            isLeft = true;
        }
        else if (str[i] == ',') {
            isLeft = false;
        }
        else if (str[i] == '}') {
            // cout << "\tpop node: " << stk.top()->val << endl;
            stk.pop();
        }
        else if (isalpha(str[i])) {
            TreeNode *node = new TreeNode(str[i]);
            if (isLeft) {
                stk.top()->left = node;
                // cout << "\tnode: " << stk.top()->val << " has left node: " << node->val << endl;
            }
            else {
                stk.top()->right = node;
                // cout << "\tnode: " << stk.top()->val << " has right node: " << node->val << endl;
            }

            if (str[i + 1] == '{') {
                stk.push(node);
                // cout << "\tpush node: " << node->val << endl;
            }
        }
    }
    inorder(root);
    cout << endl;

    return 0;
}
