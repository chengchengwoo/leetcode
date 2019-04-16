/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (46.93%)
 * Total Accepted:    336.3K
 * Total Submissions: 715.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderRecursively(root, &res, 0);
        return res;
        //return levelOrderIteratively(root);
    }
    // T: O(n) S: O(n)
    void levelOrderRecursively(TreeNode* root, vector<vector<int>>* res, int level) {
        if (!root) {
            return;
        }
        if (level >= res->size()) {
            res->resize(level + 1);
        }
        res->at(level).push_back(root->val);
        if (root->left) {
            levelOrderRecursively(root->left, res, level + 1);
        }
        if (root->right) {
            levelOrderRecursively(root->right, res, level + 1);
        }
    }
    // T: O(n) S: O(n)
    // BFS，使用一个队列实现
    vector<vector<int>> levelOrderIteratively(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            vector<int> nodes;
            for (size_t i = 0; i < size; ++i) {
                TreeNode* s = q.front(); q.pop();
                nodes.push_back(s->val);
                if (s->left) q.push(s->left);
                if (s->right) q.push(s->right);
            }
            // 转移语义，提升性能
            res.emplace_back(nodes);
        }

        return res;
    }
};

