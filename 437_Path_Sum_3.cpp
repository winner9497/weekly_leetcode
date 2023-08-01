// Runtime 73.79%, Memory 41.99%
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
    int pathSum(TreeNode* root, int targetSum) {
        result_ = 0;
        vector<long long> vecSum;
        targetSum_ = targetSum;
        searchTree(root, vecSum);
        return result_;
    }

private:
    void searchTree(TreeNode* tree, vector<long long>& vecSum) {
        // return if nullptr
        if (!tree) return;

        // Add val to all vecSum, push new sum
        for (int i = 0; i < vecSum.size(); ++i) {
            vecSum[i] += tree->val;
        }
        vecSum.push_back(tree->val);

        // check Sum
        for (long long i : vecSum) {
            if (i == targetSum_) ++result_;
        }

        // check children nodes
        searchTree(tree->left, vecSum);
        searchTree(tree->right, vecSum);

        // Subtract val from all vecSum, pop
        for (int i = 0; i < vecSum.size(); ++i) {
            vecSum[i] -= tree->val;
        }
        vecSum.pop_back();
    }

    int result_;
    int targetSum_;
};
