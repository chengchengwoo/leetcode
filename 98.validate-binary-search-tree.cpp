/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.20%)
 * Total Accepted:    358.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
    bool isValidBST(TreeNode* root) {
        //return isValidBSTRecursively(root, nullptr, nullptr);
        return isValidBSTIteratively(root);
    }
    // T: O(n) S: O(n)
    bool isValidBSTRecursively(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if ((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return isValidBSTRecursively(root->left, min, root)
                && isValidBSTRecursively(root->right, root, max);
    }
    // T: O(n) S: O(n)
    bool isValidBSTIteratively(TreeNode* root) {
        struct Tuple {
            TreeNode* node;
            TreeNode* min;
            TreeNode* max;
        };
        stack<Tuple> st;
        Tuple s{root, nullptr, nullptr};
        while (s.node || !st.empty()) {
            while (s.node) {
                if ((s.min && s.node->val <= s.min->val) || (s.max && s.node->val >= s.max->val)) {
                    return false;
                }
                
                st.push(s);
                s.max = s.node;
                s.node = s.node->left;
            }

            s = st.top(); st.pop();
            s.min = s.node;
            s.node = s.node->right;
        }
        return true;
    }
};

