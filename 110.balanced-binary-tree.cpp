/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (40.33%)
 * Total Accepted:    294.5K
 * Total Submissions: 729.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedTopDownCache(root);
    }
    // T: O(nlogn) S: O(n)
    bool isBalancedTopDown(TreeNode* root) {
        if (!root) return true;
        return abs(getHeight(root->left) - getHeight(root->right)) <= 1
                && isBalancedTopDown(root->left) && isBalancedTopDown(root->right);
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    // T: O(n) S: O(n)
    // 1. 在从底向上计算高度的同时，校验left, right的高度差是否大于1
    // 2. 如果大于1，则直接返回false
    bool isBalancedBottomUp(TreeNode* root) {
        return getHeightCheck(root) != -1;
    }
    int getHeightCheck(TreeNode* root) {
        if (!root) return 0;

        int left = getHeightCheck(root->left);
        if (left == -1) return -1;

        int right = getHeightCheck(root->right);
        if (right == -1) return -1;

        return (abs(left - right) > 1) ? -1 : (max(left, right) + 1);
    }
    // T: O(n) S: O(n) + O(unordered_map)
    bool isBalancedTopDownCache(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return isBalancedTopDownCacheHelper(root, &dp);
    }
    bool isBalancedTopDownCacheHelper(TreeNode* root, unordered_map<TreeNode*, int>* dp) {
        if (!root) return true;
        return abs(getHeightCache(root->left, dp) - getHeightCache(root->right, dp)) <= 1
                && isBalancedTopDownCacheHelper(root->left, dp)
                && isBalancedTopDownCacheHelper(root->right, dp);
    }
    int getHeightCache(TreeNode* root, unordered_map<TreeNode*, int>* dp) {
        if (!root) return 0;
        auto it = dp->find(root);
        if (it != dp->end()) return it->second;
        int height = max(getHeight(root->left), getHeight(root->right)) + 1;
        dp->insert({root, height});
        return height;
    }
};

