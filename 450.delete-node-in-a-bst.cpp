/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (39.20%)
 * Total Accepted:    57.5K
 * Total Submissions: 146.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //return deleteNodeRecursive(root, key);
        return deleteNodeIterative(root, key);
    }
    // T: O(h) S: O(h)
    TreeNode* deleteNodeRecursive(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            TreeNode* newRoot = nullptr;
            if (!root->left && !root->right) {
                newRoot = nullptr;
            } else if (!root->right) {
                newRoot = root->left;
            } else if (!root->left) {
                newRoot = root->right;
            } else {
                TreeNode* leftMax = root->left;
                while (leftMax->right) {
                    leftMax = leftMax->right;
                }
                leftMax->right = root->right;
                newRoot = root->left;
            }
            delete root;
            root = nullptr;
            return newRoot;
        } else if (root->val > key) { 
            root->left = deleteNodeRecursive(root->left, key);
        } else {
            root->right = deleteNodeRecursive(root->right, key);
        }
        
        return root;
    }
    // T: O(h) S: O(1)
    TreeNode* deleteNodeIterative(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* target = root;
        TreeNode parentObj(0);
        TreeNode* parent = &parentObj;
        parent->left = target;
        bool isLeft = true;
        while (target) {
            if (target->val == key) {
                TreeNode* newRoot = nullptr;
                if (!target->left && !target->right) {
                    newRoot = nullptr;
                } else if (!target->right) {
                    newRoot = target->left;
                } else if (!target->left) {
                    newRoot = target->right;
                } else {
                    TreeNode* leftMax = target->left;
                    while (leftMax->right) {
                        leftMax = leftMax->right;
                    }
                    leftMax->right = target->right;
                    newRoot = target->left;
                }
                if (isLeft) parent->left = newRoot;
                else parent->right = newRoot;
                delete target;
                target = nullptr;
                break;
            } else if (target->val > key) {
                parent = target;
                target = target->left;
                isLeft = true;
            } else {
                parent = target;
                target = target->right;
                isLeft = false;
            }
        }

        return parentObj.left;
    }
};

