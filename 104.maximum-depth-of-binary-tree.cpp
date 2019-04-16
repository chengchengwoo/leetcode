/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (59.10%)
 * Total Accepted:    454.9K
 * Total Submissions: 768.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its depth = 3.
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
    int maxDepth(TreeNode* root) {
        return maxDepthRecursively(root);
    }
    // T: O(n) S: O(n)
    int maxDepthRecursively(TreeNode* root) {
        if (!root) return 0;
        return std::max(maxDepthRecursively(root->left), maxDepthRecursively(root->right)) + 1;
    }
    // T: O(n) S: O(n)
    // BFS，使用queue实现
    int maxDepthIteratively(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* s = q.front(); q.pop();
                if (s->left) q.push(s->left);
                if (s->right) q.push(s->right);
            }
            ++depth;
        }

        return depth;
    }
};

