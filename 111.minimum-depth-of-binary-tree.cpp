/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.82%)
 * Total Accepted:    273.7K
 * Total Submissions: 785.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
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
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        return minDepthIteratively(root);
    }

    // T: O(n) S: O(n)
    int minDepthRecursively(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && !root->right) return minDepthRecursively(root->left) + 1;
        if (!root->left && root->right) return minDepthRecursively(root->right) + 1;
        return std::min(minDepthRecursively(root->left), minDepthRecursively(root->right)) + 1;
    }
    // T: O(n) S: O(n)
    // BFS，遍历到第一个叶子时，返回depth
    int minDepthIteratively(TreeNode* root) {
        if (!root) return 0;
        
        int depth = 1;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* s = q.front(); q.pop();
                if (!s->left && !s->right) return depth;
                if (s->left) q.push(s->left);
                if (s->right) q.push(s->right);
            }
            ++depth;
        }
        return -1;
    }
};

