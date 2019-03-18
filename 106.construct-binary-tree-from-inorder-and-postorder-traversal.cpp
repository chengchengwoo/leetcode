/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (37.86%)
 * Total Accepted:    141.1K
 * Total Submissions: 371.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return buildTree(postorder, 0, postorder.size() - 1, inorderIndex, 0);
    }
    // T: O(n) S: O(n)
    TreeNode* buildTree(vector<int>& postorder, int postorderBegin, int postorderEnd,
        unordered_map<int, int>& inorderIndex, int inorderBegin) {
        if (postorder.empty() || (postorderBegin > postorderEnd)) return nullptr;

        int rootVal = postorder[postorderEnd];
        int rootIdx = inorderIndex[rootVal];
        int leftSize = rootIdx - inorderBegin;

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(postorder, postorderBegin, postorderBegin + leftSize - 1,
            inorderIndex, inorderBegin);
        root->right = buildTree(postorder, postorderBegin + leftSize, postorderEnd - 1,
            inorderIndex, rootIdx + 1);
        return root;
    }
};

