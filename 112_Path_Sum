// Runtime 100%, Memory 82.65%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        result_ = false;
        targetSum_ = targetSum;
        searchTree(root, 0);
        return result_;
    }

private:
    void searchTree(TreeNode* tree, int currentSum) {
        // return if nullptr or found true
        if (!tree || result_) return;

        // Add val to currentSum
        currentSum += tree->val;

        // if leaf node, check Sum
        if (!tree->left && !tree->right) {
            if (currentSum == targetSum_) result_ = true;
            return;
        }
        // else, search childrens
        else {
            searchTree(tree->left, currentSum);
            searchTree(tree->right, currentSum);
        }
    }

    bool result_;
    int targetSum_;
};
