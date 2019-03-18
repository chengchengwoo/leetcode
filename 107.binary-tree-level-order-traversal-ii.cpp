/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.57%)
 * Total Accepted:    209.1K
 * Total Submissions: 458.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
    // T: O(n) S: O(n)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            vector<int> nodes;
            nodes.reserve(size);
            for (size_t i = 0; i < size; ++i) {
                TreeNode* s = q.front(); q.pop();
                nodes.push_back(s->val);
                if (s->left) q.push(s->left);
                if (s->right) q.push(s->right);
            }
            res.emplace_back(nodes);
        }

        for (size_t i = 0; i < res.size() / 2; ++i) {
            std::swap(res[i], res[res.size() - i - 1]);
        }

        return res;
    }
};

