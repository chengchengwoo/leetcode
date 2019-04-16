/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (39.36%)
 * Total Accepted:    201K
 * Total Submissions: 509.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorderIndex, 0);
    }
    // T: O(n) S: O(n)
    // 1. 根据Inorder构建map，查找root节点，得到子树的Inorder，及子树大小
    // 2. Preorder首个元素作为root，根据子树大小，得到子树的Preorder
    // 3. 使用子树的Inorder及Preorder递归处理
    TreeNode* buildTree(vector<int>& preorder, int preorderBegin,
        int preorderEnd, unordered_map<int, int>& inorderIndex, int inorderBegin) {
        if (preorder.empty() || (preorderBegin > preorderEnd)) return nullptr;
        
        int rootVal = preorder[preorderBegin];
        int rootIdx = inorderIndex[rootVal];
        int leftSize = rootIdx - inorderBegin;
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, preorderBegin + 1, preorderBegin + leftSize,
            inorderIndex, inorderBegin);
        root->right = buildTree(preorder, preorderBegin + leftSize + 1, preorderEnd,
            inorderIndex, rootIdx + 1);
        return root;
    }
};

