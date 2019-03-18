/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.16%)
 * Total Accepted:    238.6K
 * Total Submissions: 484.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //return sortedArrayToBSTRecursive(nums, 0, nums.size() - 1);
        return sortedArrayToBSTIterative(nums);
    }
    // T: O(n) S: O(logn)
    TreeNode* sortedArrayToBSTRecursive(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;

        int mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRecursive(nums, begin, mid - 1);
        root->right = sortedArrayToBSTRecursive(nums, mid + 1, end);
        
        return root;
    }
    // T: O(n) S: O(n)
    TreeNode* sortedArrayToBSTIterative(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        struct Item {
            TreeNode* root;
            int begin;
            int end;
            bool left;
        };
        stack<Item> st;
        TreeNode dummy(0);
        st.push(Item{&dummy, 0, nums.size() - 1, true});
        while (!st.empty()) {
            Item s = st.top(); st.pop();
            if (s.begin > s.end) {
                continue;
            }
            int mid = s.begin + (s.end - s.begin) / 2;
            TreeNode* child = new TreeNode(nums[mid]);
            if (s.left) {
                s.root->left = child;
            } else {
                s.root->right = child;
            }
            st.push(Item{child, s.begin, mid - 1, true});
            st.push(Item{child, mid + 1, s.end, false});
        }
        return dummy.left;
    }
};

