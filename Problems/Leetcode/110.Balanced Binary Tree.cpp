class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftH = height(root->left);
        if (leftH == -1) return -1;

        int rightH = height(root->right);
        if (rightH == -1) return -1;

        if (abs(leftH - rightH) > 1)
            return -1;

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
