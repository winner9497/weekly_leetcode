// Runtime 89.73%, Memory 64.63%
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result_ = vector<vector<int>>();
        vector<int> path;
        targetSum_ = targetSum;
        searchTree(root, 0, path);
        return result_;
    }

private:
    void searchTree(TreeNode* tree, int currentSum, vector<int>& path) {
        // return if nullptr
        if (!tree) return;

        // Add val to currentSum
        currentSum += tree->val;
        path.push_back(tree->val);

        // if leaf node, check Sum
        if (!tree->left && !tree->right) {
            if (currentSum == targetSum_) result_.emplace_back(path);
            path.pop_back();
            return;
        }
        // else, search childrens
        else {
            searchTree(tree->left, currentSum, path);
            searchTree(tree->right, currentSum, path);
            path.pop_back();
        }
    }

    vector<vector<int>> result_;
    int targetSum_;
};
