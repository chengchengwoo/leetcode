/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (66.68%)
 * Total Accepted:    43.1K
 * Total Submissions: 64.6K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * Given the root node of a binary search tree (BST) and a value. You need to
 * find the node in the BST that the node's value equals the given value.
 * Return the subtree rooted with that node. If such node doesn't exist, you
 * should return NULL.
 * 
 * For example, 
 * 
 * 
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * And the value to search: 2
 * 
 * 
 * You should return this subtree:
 * 
 * 
 * ⁠     2     
 * ⁠    / \   
 * ⁠   1   3
 * 
 * 
 * In the example above, if we want to search the value 5, since there is no
 * node with value 5, we should return NULL.
 * 
 * Note that an empty tree is represented by NULL, therefore you would see the
 * expected output (serialized tree format) as [], not null.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        //return searchBSTRecursive(root, val);
        return searchBSTIterative(root, val);
    }
    // T: O(h=logn[best] OR n[worst]) S: O(h)
    TreeNode* searchBSTRecursive(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        else if (root->val < val) return searchBSTRecursive(root->right, val);
        else return searchBSTRecursive(root->left, val);
    }
    // T: O(h=logn(best) OR n[worst]) S: O(1)
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) return root;
            else if (root->val < val) root = root->right;
            else root = root->left;
        }
        return nullptr;
    }
};

