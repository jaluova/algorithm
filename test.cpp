#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    int val;
    TNode *l;
    TNode *r;
    TNode(int x) : val(x), l(nullptr), r(nullptr) {}
};

bool isBST(TNode *root, long min, long max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return isBST(root->l, min, root->val) && isBST(root->r, root->val, max);
}

bool isBST(TNode *root) { return isBST(root, LONG_MIN, LONG_MAX); }

int main() {
    // 接受数据
    TNode *root;
    // 判断
    bool ans = isBST(root);
    std::cout << (ans ? "true" : "false") << std::endl;

    return 0;
}