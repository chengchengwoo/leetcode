/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (36.97%)
 * Total Accepted:    286.5K
 * Total Submissions: 773.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        //return hasPathSumRecursive(root, sum);
        return hasPathSumIterative(root, sum);
    }
    // T: O(n) S: O(n)
    bool hasPathSumRecursive(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return hasPathSumRecursive(root->left, sum - root->val)
            || hasPathSumRecursive(root->right, sum - root->val);
    }
    // T: O(n) S: O(n)
    bool hasPathSumIterative(TreeNode* root, int sum) {
        struct Item {
            TreeNode* root;
            int sum;
        };
        stack<Item> st;
        Item s{root, sum};
        while (s.root || !st.empty()) {
            while (s.root) {
                if (!s.root->left && !s.root->right && s.root->val == s.sum) {
                    return true;
                }
                st.push(s);
                s.sum -= s.root->val;
                s.root = s.root->left;
            }
            s = st.top(); st.pop();
            s.sum -= s.root->val;
            s.root = s.root->right;
        }
        return false;
    }
};

